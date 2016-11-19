//
// Created by User on 19.11.2016.
//

#ifndef WAREHOUSE_WORK_PRODUCT_H
#define WAREHOUSE_WORK_PRODUCT_H
#include <iostream>
#include <ctime>
#include <chrono>

class Product {
public:
    Product(const std::string &name, float price);

    Product();

    const std::string &getName() const;

    void setName(const std::string &name);

    float getPrice() const;

    void setPrice(float price);

    std::string getDateOfReceiving() const;

    void setDateOfReceiving();

private:
    std::string name;
    float price;
    std::string dateOfReceiving;
};


#endif //WAREHOUSE_WORK_PRODUCT_H
