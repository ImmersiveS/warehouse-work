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
class Supplier {
public:
    Supplier(const std::string &name, const std::vector<Product> &products);

    const std::string &getName() const;

    void setName(const std::string &name);

     std::vector<Product> &getProducts() ;

    void setProducts(const std::vector<Product> &products);

     std::vector<Request> &getRequests();

    void setRequests(const std::vector<Request> &requests);

    void sendProducts(const Warehouse& warehouse, std::vector<Product> proucts);

private:
    std::string name;
    std::vector<Product> products;
    std::vector<Request> requests;
};


#endif //WAREHOUSE_WORK_SUPPLIER_H
