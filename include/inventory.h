#pragma once
#include <vector>
#include <memory>
#include <string>
#include <stdexcept>
#include "product.h"

class Inventory {
private:
    std::vector<std::shared_ptr<Product>> productos;
    int nextId;

public:
    explicit Inventory(int startId = 1) : nextId(startId) {}

    void addProduct(std::shared_ptr<Product> producto) {
        producto->setId(nextId);
        nextId++;
        productos.push_back(producto);
    }

    void deleteProduct(int id) {
        for (auto it = productos.begin(); it != productos.end(); ++it) {
            if ((*it)->getId() == id) {
                productos.erase(it);
                return;
            }
        }
        throw std::runtime_error("No existe un producto con id " + std::to_string(id));
    }

    std::vector<std::string> listProducts() const {
        std::vector<std::string> resultado;
        for (const auto& p : productos) {
            resultado.push_back(p->showInfo());
        }
        return resultado;
    }
};