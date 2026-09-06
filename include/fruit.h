#pragma once
#include "product.h"

class Fruit : public Product {
private:
    bool esOrganico;
    std::string fechaCaducidad;

public:
    Fruit(int id, const std::string& nombre, double precio, int stock,
          const std::string& fechaIngreso, bool esOrganico, const std::string& fechaCaducidad)
        : Product(id, nombre, precio, stock, fechaIngreso),
          esOrganico(esOrganico), fechaCaducidad(fechaCaducidad) {}

    bool getEsOrganico() const { return esOrganico; }
    std::string getFechaCaducidad() const { return fechaCaducidad; }

    std::string showInfo() const override {
        return "[Fruta] " + name + " | Precio: $" + std::to_string(price) +
               " | Stock: " + std::to_string(stock) +
               " | Organico: " + (esOrganico ? "Si" : "No") +
               " | Caduca: " + fechaCaducidad;
    }

    std::string getTipo() const override {
        return "fruta";
    }
};