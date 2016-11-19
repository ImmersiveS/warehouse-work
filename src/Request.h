//
// Created by User on 19.11.2016.
//

#ifndef WAREHOUSE_WORK_REQUEST_H
#define WAREHOUSE_WORK_REQUEST_H
#include <iostream>
#include <vector>
#include "Product.h"

class Request {
private:
public:
    const std::vector<Product> &getProducts() const;

    void setProducts(const std::vector<Product> &products);

    bool isCompliteness() const;

    void setCompliteness(bool compliteness);

private:
    std::vector<Product> products;
    bool compliteness;

};


#endif //WAREHOUSE_WORK_REQUEST_H
