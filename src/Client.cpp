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

void Client::setNumOfUnpaidInvoices(int numOfUnpaidInvoices) {
    Client::numOfUnpaidInvoices = numOfUnpaidInvoices;
}

int Client::getNumOfReceivedProducts() const {
    return numOfReceivedProducts;
}

void Client::setNumOfReceivedProducts(int numOfReceivedProducts) {
    Client::numOfReceivedProducts = numOfReceivedProducts;
}

int Client::getNumOfRequest() const {
    return numOfRequest;
}

void Client::setNumOfRequest(int numOfRequest) {
    Client::numOfRequest = numOfRequest;
}
void Client::sendRequest(const Warehouse& warehouse, const Request& request) {

}
void Client::payInvoice(Invoice invoice) {

}