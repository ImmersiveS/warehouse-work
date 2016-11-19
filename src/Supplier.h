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

    Supplier();

    const std::string &getName() const;

    void setName(const std::string &name);

    const std::vector<Product> &getProducts() const;

    void setProducts(const std::vector<Product> &products);

    const std::vector<Product> &getRequests() const;

    void setRequests(const std::vector<Product> &requests);

    void sendProducts(const Warehouse& warehouse, std::vector<Product> proucts);

private:
    std::string name;
    std::vector<Product> products;
    std::vector<Product> requests;
};


#endif //WAREHOUSE_WORK_SUPPLIER_H
