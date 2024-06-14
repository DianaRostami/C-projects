#ifndef PRODUCTFACTORY_H
#define PRODUCTFACTORY_H

#include "Product.h"
#include <string>

class ProductFactory {
public:
    virtual ~ProductFactory() {}
    virtual Product* createProduct(const std::string& barcode) const = 0;
};

#endif // PRODUCTFACTORY_H
