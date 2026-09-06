#pragma once
#include "product.h"

class Vegetable : public Product {
private:
    bool requiereRefrigeracion;
    std::string fechaCaducidad;

public:
    Vegetable(int id, const std::string& nombre, double precio, int stock,
               const std::string& fechaIngreso, bool requiereRefrigeracion, const std::string& fechaCaducidad)
        : Product(id, nombre, precio, stock, fechaIngreso),
          requiereRefrigeracion(requiereRefrigeracion), fechaCaducidad(fechaCaducidad) {}

    bool getRequiereRefrigeracion() const { return requiereRefrigeracion; }
    std::string getFechaCaducidad() const { return fechaCaducidad; }

    std::string showInfo() const override {
        return "[Verdura] " + name + " | Precio: $" + std::to_string(price) +
               " | Stock: " + std::to_string(stock) +
               " | Refrigeracion: " + (requiereRefrigeracion ? "Si" : "No") +
               " | Caduca: " + fechaCaducidad;
    }

    std::string getTipo() const override {
        return "verdura";
    }
};