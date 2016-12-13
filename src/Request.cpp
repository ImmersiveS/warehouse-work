#include "Request.h"

std::vector<Product> &Request::getProducts() {
    return products;
}

void Request::setProducts(const std::vector<Product> &products) {
    Request::products = products;
}

Request::Request(const std::vector<Product> &products) : products(products) {}
