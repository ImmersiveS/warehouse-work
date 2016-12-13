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

    bool isPaid();

    void setPaid(bool isPaid);

    std::shared_ptr<Supplier> getSupplier();

private:
    std::vector<Product> products;
    int cost;
    bool paid;
    std::string dateOfPaying;
    std::shared_ptr<Warehouse> warehouse;
    std::shared_ptr<Supplier> supplier;
};


#endif //WAREHOUSE_WORK_INVOCE_H
