#ifndef DATABASE_H
#define DATABASE_H

#include <string>
#include <unordered_map>

class Database {
private:
    std::unordered_map<std::string, std::pair<std::string, double>> productData;
public:
    Database() {
        // اسامی محصولات
        productData["1000"] = {"Milk", 2.5};
        productData["1001"] = {"Bread", 1.2};
        productData["1002"] = {"Butter", 3.4};
        productData["1003"] = {"cheese", 4.5};
        productData["1004"] = {"cream", 5.3};
        productData["1005"] = {"bean", 8};
        productData["1006"] = {"banana", 10.2};
        productData["1007"] = {"cucumber", 3};
        productData["1008"] = {"cake", 5.5};
        productData["1009"] = {"nuts", 4.3};
        productData["1010"] = {"juice", 7.4};
        productData["1011"] = {"water", 3.5};
        productData["1012"] = {"oil", 11.1};
        productData["1013"] = {"sandwich", 25.7};
        productData["1014"] = {"potato crisp", 7.8};

    }
    std::pair<std::string, double> getProductData(const std::string& barcode) const {
        auto it = productData.find(barcode);
        if (it != productData.end()) {
            return it->second;
        }
        return {"Unknown", 0.0};
    }
};

#endif // DATABASE_H
