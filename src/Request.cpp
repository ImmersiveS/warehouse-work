//
// Created by User on 19.11.2016.
//

#include "Request.h"

const std::vector<Product> &Request::getProducts() const {
    return products;
}

void Request::setProducts(const std::vector<Product> &products) {
    Request::products = products;
}

bool Request::isCompliteness() const {
    return compliteness;
}

void Request::setCompliteness(bool compliteness) {
    Request::compliteness = compliteness;
}
