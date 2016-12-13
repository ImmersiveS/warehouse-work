#ifndef WAREHOUSE_WORK_REQUEST_H
#define WAREHOUSE_WORK_REQUEST_H
#include <iostream>
#include <vector>
#include "Product.h"

class Request {
public:
    Request(const std::vector<Product> &products);

    std::vector<Product> &getProducts();

    void setProducts(const std::vector<Product> &products);

private:
    std::vector<Product> products;
};


#endif //WAREHOUSE_WORK_REQUEST_H
