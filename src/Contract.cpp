#include "Contract.h"

const std::vector<Product> &Contract::getProducts() const {
    return products;
}

void Contract::setProducts(const std::vector<Product> &products) {
    Contract::products = products;
}

std::shared_ptr<Supplier> Contract::getSupplier() const {
    return supplier;
}

std::shared_ptr<Warehouse> Contract::getWarehouse() {
    return warehouse;
}

int Contract::getCost() {
    return cost;
}

void Contract::setCost(int cost) {
    Contract::cost = cost;
}

Contract::Contract(std::vector<Product> &products, Supplier &supplier, Warehouse &warehouse, int cost) :
        products(products), cost(cost) {
    this->supplier = std::make_shared<Supplier>(supplier);
    this->warehouse = std::make_shared<Warehouse>(warehouse);
    this->client = nullptr;
}

Contract::Contract(std::vector<Product> &products, Client &client, Warehouse &warehouse, int cost) :
        products(products), cost(cost) {
    this->client = std::make_shared<Client>(client);
    this->warehouse = std::make_shared<Warehouse>(warehouse);
    this->supplier = nullptr;
}
Contract::Contract() {
    this->client = nullptr;
    this->warehouse = nullptr;
    this->supplier = nullptr;
}

std::shared_ptr<Client> Contract::getClient() {
    return client;
}
