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

std::vector<Invoice> &Client::getInvoices() {
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

void Client::sendRequest(Warehouse& warehouse, Request&& request) {
    numOfRequest++;
    warehouse.accounting.getRequests().push_back(request);
    std::shared_ptr<Invoice> invoice(new Invoice(request.getProducts()));
    warehouse.accounting.sendInvoice(*this, *invoice);
}
void Client::payInvoice(Invoice& invoice) {

}

Client::Client(const std::string &name) : name(name), numOfRequest(0), numOfReceivedProducts(0), numOfUnpaidInvoices(0) {}

Client::Client() : name("undefined"), numOfRequest(0), numOfReceivedProducts(0), numOfUnpaidInvoices(0) {}
