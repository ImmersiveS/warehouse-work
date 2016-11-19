//
// Created by User on 19.11.2016.
//

#include "Supplier.h"

const std::string &Supplier::getName() const {
    return name;
}

void Supplier::setName(const std::string &name) {
    Supplier::name = name;
}

const std::vector<Product> &Supplier::getProducts() const {
    return products;
}

void Supplier::setProducts(const std::vector<Product> &products) {
    Supplier::products = products;
}

const std::vector<Product> &Supplier::getRequests() const {
    return requests;
}

void Supplier::setRequests(const std::vector<Product> &requests) {
    Supplier::requests = requests;
}

void Supplier::sendProducts(const Warehouse &warehouse, std::vector<Product> proucts) {

}