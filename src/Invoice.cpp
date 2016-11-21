//
// Created by User on 19.11.2016.
//

#include "Invoice.h"

const std::vector<Product> &Invoice::getProducts() const {
    return products;
}

void Invoice::setProducts(const std::vector<Product> &products) {
    Invoice::products = products;
}

int Invoice::getCost() const {
    return cost;
}

void Invoice::setCost(int cost) {
    Invoice::cost = cost;
}

bool Invoice::isIsPaid() const {
    return isPaid;
}

void Invoice::setIsPaid(bool isPaid) {
    Invoice::isPaid = isPaid;
}

const std::string &Invoice::getDateOfPaying() const {
    return dateOfPaying;
}

void Invoice::setDateOfPaying(const std::string &dateOfPaying) {
    Invoice::dateOfPaying = dateOfPaying;
}

Invoice::Invoice(std::vector<Product> &products) : products(products), isPaid(false), dateOfPaying("non-existent")
{
    cost = 0;
    for (auto item : products)
        cost += item.getPrice() * item.getAmount();
}
