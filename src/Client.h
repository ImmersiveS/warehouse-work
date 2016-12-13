#ifndef WAREHOUSE_WORK_CLIENT_H
#define WAREHOUSE_WORK_CLIENT_H

#include <iostream>
#include <vector>
#include "Product.h"
#include "Invoice.h"
#include "Warehouse.h"

class Warehouse;
class Invoice;
class Client {
public:
    Client();

    Client(const std::string &name);

    const std::string &getName() const;

    void setName(const std::string &name);

    std::vector<Product> &getProducts();

    void setProducts(const std::vector<Product> &products);

     std::vector<Invoice> &getInvoices();

    void setInvoices(const std::vector<Invoice> &invoices);

    int getNumOfUnpaidInvoices() const;

    void countNumOfUnpaidInvoices();

    int getNumOfCompletedRequests() const;

    void countNumOfCompletedRequests();

    int getNumOfRequest() const;

    void sendRequest(Warehouse& warehouse, Request&& request);

    void payInvoice(Warehouse& warehouse, Invoice& invoice);

private:
    std::string name;
    std::vector<Product> products;
    std::vector<Invoice> invoices;
    int numOfUnpaidInvoices;
    int numOfCompletedRequests;
    int numOfRequest;
};


#endif //WAREHOUSE_WORK_CLIENT_H
