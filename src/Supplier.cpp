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

 std::vector<Product> &Supplier::getProducts() {
    return products;
}

void Supplier::setProducts(const std::vector<Product> &products) {
    Supplier::products = products;
}

std::vector<Request> &Supplier::getRequests() {
    return requests;
}

void Supplier::setRequests(const std::vector<Request> &requests) {
    Supplier::requests = requests;
}

void Supplier::sendProducts(Warehouse &warehouse, std::vector<Product> proucts) {
    for (int i = 0; i < proucts.size(); ++i) {
        proucts[i].setDateOfReceivingForWarehouse();
        warehouse.getProducts().push_back(proucts[i]);
    }
}

Supplier::Supplier(const std::string &name, const std::vector<Product> &products) : name(name), products(products) {}

void Supplier::sendInvoice(Warehouse& warehouse, Invoice& invoice) {
    warehouse.accounting.getInvoices().push_back(invoice);
}

