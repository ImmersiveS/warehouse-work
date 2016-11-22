//
// Created by User on 19.11.2016.
//

#ifndef WAREHOUSE_WORK_INVOCE_H
#define WAREHOUSE_WORK_INVOCE_H
#include <iostream>
#include <vector>
#include "Product.h"
#include "Supplier.h"

class Warehouse;
class Supplier;
class Invoice {
public:
    Invoice(std::vector<Product> &products, Warehouse& warehouse);

    Invoice(std::vector<Product> &products, Supplier& supplier);

    std::vector<Product> &getProducts();

    void setProducts(const std::vector<Product> &products);

    int getCost() const;

    void setCost(int cost);

    bool isPaid();

    void setPaid(bool isPaid);

    const std::string &getDateOfPaying() const;

    void setDateOfPaying(const std::string &dateOfPaying);

    Warehouse *getWarehouse();

    Supplier *getSupplier();

private:
    std::vector<Product> products;
    int cost;
    bool paid;
    std::string dateOfPaying;
    Warehouse *warehouse;
    Supplier *supplier;
};


#endif //WAREHOUSE_WORK_INVOCE_H
