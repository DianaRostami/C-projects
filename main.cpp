#include "Database.h"
#include "ConcreteProductFactory.h"
#include "Invoice.h"

int main() {
    Database db;
    ConcreteProductFactory factory(&db);
    Invoice invoice(&factory);

    std::string barcode;
    while (true) {
        std::cout << "Enter barcode (or 'done' to finish): ";
        std::cin >> barcode;
        if (barcode == "done") break;
        invoice.addProduct(barcode);
    }

    invoice.printInvoice();

    return 0;
}
