//
// Created by User on 19.11.2016.
//

#include "Client.h"

const std::string &Client::getName() const {
    return name;
}

void Client::setName(const std::string &name) {
    Client::name = name;
}

const std::vector<Product> &Client::getProducts() const {
    return products;
}

void Client::setProducts(const std::vector<Product> &products) {
    Client::products = products;
}

const std::vector<Invoice> &Client::getInvoices() const {
    return invoices;
}

void Client::setInvoices(const std::vector<Invoice> &invoices) {
    Client::invoices = invoices;
}

int Client::getNumOfUnpaidInvoices() const {
    return numOfUnpaidInvoices;
}

void Client::countNumOfUnpaidInvoices() {
    int unpaidInvoices = 0;
    for (auto &item : invoices)
        if (!item.isIsPaid())
            unpaidInvoices++;
    Client::numOfUnpaidInvoices = unpaidInvoices;
}

int Client::getNumOfReceivedProducts() const {
    return numOfReceivedProducts;
}

void Client::countNumOfReceivedProducts() {
    Client::numOfReceivedProducts = Client::products.size();
}

int Client::getNumOfRequest() const {
    return numOfRequest;
}

void Client::sendRequest(const Warehouse& warehouse, const Request& request) {
    numOfRequest++;
}
void Client::payInvoice(const Invoice& invoice) {

}

Client::Client(const std::string &name) : name(name), numOfRequest(0), numOfReceivedProducts(0), numOfUnpaidInvoices(0) {}

Client::Client() : name("undefined"), numOfRequest(0), numOfReceivedProducts(0), numOfUnpaidInvoices(0) {}
