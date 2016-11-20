//
// Created by User on 19.11.2016.
//

#ifndef WAREHOUSE_WORK_INVOCE_H
#define WAREHOUSE_WORK_INVOCE_H
#include <iostream>
#include <vector>
#include "Product.h"

class Invoice {
public:
    Invoice(const std::vector<Product> &products);

    const std::vector<Product> &getProducts() const;

    void setProducts(const std::vector<Product> &products);

    int getCost() const;

    void setCost(int cost);

    bool isIsPaid() const;

    void setIsPaid(bool isPaid);

    const std::string &getDateOfPaying() const;

    void setDateOfPaying(const std::string &dateOfPaying);

private:
    std::vector<Product> products;
    int cost;
    bool isPaid;
    std::string dateOfPaying;
};


#endif //WAREHOUSE_WORK_INVOCE_H
