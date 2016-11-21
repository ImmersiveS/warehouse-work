//
// Created by User on 19.11.2016.
//

#ifndef WAREHOUSE_WORK_WEARHOUSE_H
#define WAREHOUSE_WORK_WEARHOUSE_H

#include <iostream>
#include <vector>
#include <memory>
#include "Invoice.h"
#include "Request.h"
#include "Contract.h"

class Supplier;
class Client;
class Contract;
class Invoice;
class Warehouse
{
public:
    class Accounting
    {
    public:
        Accounting(Warehouse &warehouse);

        Warehouse &getWarehouse();

        std::vector<Request> &getRequests();

        void setRequests(const std::vector<Request> &requests);

        std::vector<Contract> &getContracts();

        void setContracts(const std::vector<Contract> &contracts);

        void sendRequest(Supplier& supplier, Request&& request);

        void payInvoice(Invoice& invoice);

        void sendInvoice( Client& client, Invoice& invoice);

        void sendProducts(Client& client, std::vector<Product> proucts);

        std::vector<Invoice> &getInvoices();

        void setInvoices(const std::vector<Invoice> &invoices);

    private:
        Warehouse& warehouse;
        std::vector<Invoice> invoices;
        std::vector<Request> requests;
        std::vector<Contract> contracts;
    } accounting;
    Warehouse(const std::string &name, const std::vector<Product> &products);

    Warehouse(const std::string &name);

    Warehouse();

    //Accounting *accounting;

    const std::string &getName() const;

    void setName(const std::string &name);

    const std::vector<Product> &getProducts() const;

    void setProducts(const std::vector<Product> &products);
private:

    std::string name;
    std::vector<Product> products;
};


#endif //WAREHOUSE_WORK_WEARHOUSE_H
