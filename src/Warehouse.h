//
// Created by User on 19.11.2016.
//

#ifndef WAREHOUSE_WORK_WEARHOUSE_H
#define WAREHOUSE_WORK_WEARHOUSE_H

#include <iostream>
#include <vector>
#include "Product.h"
#include "Invoice.h"
#include "Request.h"
#include "Contract.h"
#include "Supplier.h"
#include "Client.h"

class Warehouse
{
public:

    const std::string &getName() const;

    void setName(const std::string &name);

    const std::vector<Product> &getProducts() const;

    void setProducts(const std::vector<Product> &products);

private:
    std::string name;
    std::vector<Product> products;
    class Accounting
    {
    public:
        void sendRequest(Supplier supplier, Request request);
        void payInvoice(Invoice invoice);
        void sendInvoice(Client client, Invoice invoice);
    private:
        std::vector<Invoice> invoices;
        std::vector<Request> requests;
        std::vector<Contract> contracts;
    };
};


#endif //WAREHOUSE_WORK_WEARHOUSE_H
