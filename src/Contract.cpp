//
// Created by User on 19.11.2016.
//

#include "Contract.h"

const std::vector<Product> &Contract::getProducts() const {
    return products;
}

void Contract::setProducts(const std::vector<Product> &products) {
    Contract::products = products;
}

Supplier *Contract::getSupplier() const {
    return supplier;
}

void Contract::setSupplier(Supplier *supplier) {
    Contract::supplier = supplier;
}

Warehouse *Contract::getWarehouse() const {
    return warehouse;
}

void Contract::setWarehouse(Warehouse *warehouse) {
    Contract::warehouse = warehouse;
}

int Contract::getCost() const {
    return cost;
}

void Contract::setCost(int cost) {
    Contract::cost = cost;
}

Contract::Contract(std::vector<Product> &products, Supplier &supplier, Warehouse &warehouse, int cost) :
        products(products), supplier(&supplier), warehouse(&warehouse), cost(cost) {}

Contract::Contract() {}
