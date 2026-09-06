#include <iostream>
#include <memory>
#include "product.h"
#include "fruit.h"
#include "vegetable.h"
#include "inventory.h"
#include "connection.h"

int main() {
    Inventory inventario;

    // Agregamos productos (el id lo pasamos en 0, Inventory lo reasigna solito)
    auto manzana = std::make_shared<Fruit>(0, "Manzana", 1.50, 100, "2026-09-01", true, "2026-09-20");
    auto zanahoria = std::make_shared<Vegetable>(0, "Zanahoria", 0.80, 50, "2026-09-01", true, "2026-09-15");

    inventario.addProduct(manzana);
    inventario.addProduct(zanahoria);

    std::cout << "=== Inventario actual ===" << std::endl;
    for (const auto& linea : inventario.listProducts()) {
        std::cout << linea << std::endl;
    }

    std::cout << "\n=== Probando deleteProduct con id valido ===" << std::endl;
    inventario.deleteProduct(1); // borra la manzana (id 1, asignado por Inventory)
    for (const auto& linea : inventario.listProducts()) {
        std::cout << linea << std::endl;
    }

    std::cout << "\n=== Probando deleteProduct con id INVALIDO (debe lanzar excepcion) ===" << std::endl;
    try {
        inventario.deleteProduct(999);
    } catch (const std::runtime_error& e) {
        std::cout << "Error capturado: " << e.what() << std::endl;
    }
    Database db; db.connect(); db.testQuery();

    return 0;
}