#include "Warehouse.h"

const std::string &Warehouse::getName() const {
    return name;
}

void Warehouse::setName(const std::string &name) {
    Warehouse::name = name;
}

const std::vector<Product> &Warehouse::getProducts() const {
    return products;
}

void Warehouse::setProducts(const std::vector<Product> &products) {
    Warehouse::products = products;
}

//Warehouse::Warehouse(const std::string &name, const std::vector<Product> &products) : name(name), products(products)
//{
//    this->name = name;
//    this->products = products;
//}
//
//Warehouse::Warehouse() { this->name = "unnamed"; }
//
//Warehouse::Warehouse(const std::string &name) : name(name) { this->name = name; }

void Warehouse::Accounting::sendRequest(const Supplier& supplier, const Request& request) {

}
void Warehouse::Accounting::payInvoice(const Invoice& invoice) {

}
void Warehouse::Accounting::sendInvoice(const Client& client, const Invoice& invoice) {

}
void Warehouse::Accounting::sendProducts(const Client &client, std::vector<Product> proucts) {

}