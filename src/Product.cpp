//
// Created by User on 19.11.2016.
//

#include "Product.h"

const std::string &Product::getName() const {
    return name;
}

void Product::setName(const std::string &name) {
    Product::name = name;
}

float Product::getPrice() const {
    return price;
}

void Product::setPrice(float price) {
    Product::price = price;
}

std::string Product::getDateOfReceiving() const {
    return dateOfReceiving;
}

void Product::setDateOfReceiving() {
    std::chrono::system_clock::time_point dateOfPaying  = std::chrono::system_clock::now();
    time_t dateOfReceiving = std::chrono::system_clock::to_time_t(dateOfPaying + std::chrono::hours(72));
    Product::dateOfReceiving = asctime(localtime(&dateOfReceiving));
}
