//
// Created by User on 19.11.2016.
//

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

void Warehouse::Accounting::sendRequest(Supplier supplier, Request request) {

}
void Warehouse::Accounting::payInvoice(Invoice invoice) {

}
void Warehouse::Accounting::sendInvoice(Client client, Invoice invoice) {

}