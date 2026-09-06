#pragma once
#include <string>
#include <libpq-fe.h>

class Database {
private:
    PGconn* conn = nullptr;
    std::string envHost, envPort, envDbName, envUser, envPassword;

    void loadEnv(const std::string& path);
    std::string buildConnectionString() const;

public:
    Database();
    ~Database();

    Database(const Database&) = delete;
    Database& operator=(const Database&) = delete;

    void connect();
    bool isConnected() const;
    void testQuery();
};