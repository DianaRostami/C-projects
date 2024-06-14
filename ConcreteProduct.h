#ifndef CONCRETEPRODUCT_H
#define CONCRETEPRODUCT_H

#include "Product.h"

class ConcreteProduct : public Product {
private:
    std::string name;
    double price;
    std::string barcode;
public:
    ConcreteProduct(const std::string& name, double price, const std::string& barcode)
        : name(name), price(price), barcode(barcode) {}
    std::string getName() const override { return name; }
    double getPrice() const override { return price; }
    std::string getBarcode() const override { return barcode; }
};

#endif // CONCRETEPRODUCT_H
