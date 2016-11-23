//
// Created by User on 19.11.2016.
//

#ifndef WAREHOUSE_WORK_SUPPLIER_H
#define WAREHOUSE_WORK_SUPPLIER_H

#include <iostream>
#include <vector>
#include "Product.h"
#include "Warehouse.h"

class Warehouse;
class Request;
class Invoice;
class Supplier {
public:
    Supplier(const std::string &name, const std::vector<Product> &products);
    Supplier();
    std::string &getName();

    void setName(const std::string &name);

     std::vector<Product> &getProducts() ;

    void setProducts(const std::vector<Product> &products);

     std::vector<Request> &getRequests();

    void setRequests(const std::vector<Request> &requests);

    void sendProducts(Warehouse& warehouse, std::vector<Product> &products);

    void sendInvoice(Warehouse& warehouse, Invoice& invoice);

private:
    std::string name;
    std::vector<Product> products;
    std::vector<Request> requests;
};


#endif //WAREHOUSE_WORK_SUPPLIER_H
