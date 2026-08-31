#pragma once
#include <string>

class Product {
    protected:
     int id;
     std::string name;
     double price;
     int stock;
     std::string date_added; //fecha en la que se agrego el producto
    
    public:
     Product(int id, const std::string& name, double price, int stock, const std::string& date_added)
            : id(id), name(name), price(price), stock(stock), date_added(date_added) {}

     virtual ~Product() = default; //destructor virtual para permitir la herencia
    
     // Getters
     int getId() const { return id; }
     std::string getName() const { return name; }
     double getPrice() const { return price; }
     int getStock() const { return stock; }

     // Setters
     void setStock(int newStock) { stock = newStock; }

     // Método virtual puro : cada hijo debe implementar su propia versión de este método
     virtual std::string showInfo() const = 0;

     // ,étodo virtual puro útil para la base de datos más adelante
     virtual std::string getTipo() const = 0; // ej: "fruta", "verdura"
};