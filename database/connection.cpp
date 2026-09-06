#include "connection.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <stdexcept>

Database::Database() {
    loadEnv(".env");
}

Database::~Database() {
    if (conn) {
        PQfinish(conn);
    }
}

void Database::loadEnv(const std::string& path) {
    std::ifstream file(path);
    if (!file.is_open()) {
        throw std::runtime_error("No se pudo abrir el archivo .env en: " + path);
    }
    std::string linea;
    while (std::getline(file, linea)) {
        if (linea.empty() || linea[0] == '#') continue;
        auto pos = linea.find('=');
        if (pos == std::string::npos) continue;
        std::string clave = linea.substr(0, pos);
        std::string valor = linea.substr(pos + 1);
        if (clave == "DB_HOST") envHost = valor;
        else if (clave == "DB_PORT") envPort = valor;
        else if (clave == "DB_NAME") envDbName = valor;
        else if (clave == "DB_USER") envUser = valor;
        else if (clave == "DB_PASSWORD") envPassword = valor;
    }
}

std::string Database::buildConnectionString() const {
    std::ostringstream oss;
    oss << "host=" << envHost << " port=" << envPort << " dbname=" << envDbName
        << " user=" << envUser << " password=" << envPassword;
    return oss.str();
}

void Database::connect() {
    conn = PQconnectdb(buildConnectionString().c_str());
    if (PQstatus(conn) != CONNECTION_OK) {
        std::string error = PQerrorMessage(conn);
        PQfinish(conn);
        conn = nullptr;
        throw std::runtime_error("Error al conectar a PostgreSQL: " + error);
    }
}

bool Database::isConnected() const {
    return conn != nullptr && PQstatus(conn) == CONNECTION_OK;
}

void Database::testQuery() {
    if (!isConnected()) {
        throw std::runtime_error("No hay conexion activa. Llama a connect() primero.");
    }
    PGresult* res = PQexec(conn, "SELECT version();");
    if (PQresultStatus(res) != PGRES_TUPLES_OK) {
        std::string error = PQerrorMessage(conn);
        PQclear(res);
        throw std::runtime_error("Error en la query: " + error);
    }
    std::cout << "Version de PostgreSQL: " << PQgetvalue(res, 0, 0) << std::endl;
    PQclear(res);
}