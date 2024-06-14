#ifndef CONCRETEPRODUCTFACTORY_H
#define CONCRETEPRODUCTFACTORY_H

#include "ProductFactory.h"
#include "Database.h"
#include "ConcreteProduct.h"

class ConcreteProductFactory : public ProductFactory {
private:
    Database* database;
public:
    ConcreteProductFactory(Database* db) : database(db) {}
    Product* createProduct(const std::string& barcode) const override {
        auto productData = database->getProductData(barcode);
        return new ConcreteProduct(productData.first, productData.second, barcode);
    }
};

#endif // CONCRETEPRODUCTFACTORY_H
