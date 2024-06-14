#ifndef INVOICE_H
#define INVOICE_H

#include "Product.h"
#include "ProductFactory.h"
#include <vector>
#include <iostream>

class Invoice {
private:
    std::vector<Product*> products;
    ProductFactory* factory;
public:
    Invoice(ProductFactory* factory) : factory(factory) {}
    ~Invoice() {
        for (auto product : products) {
            delete product;
        }
    }
    void addProduct(const std::string& barcode) {
        products.push_back(factory->createProduct(barcode));
    }
    void printInvoice() const {
        std::cout << "Invoice:\n";
        for (const auto& product : products) {
            std::cout << "Barcode: " << product->getBarcode()
                      << ", Name: " << product->getName()
                      << ", Price: " << product->getPrice() << "\n";
        }
    }
};

#endif // INVOICE_H
