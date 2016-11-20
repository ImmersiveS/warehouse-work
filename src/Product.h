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
    Product(const std::string &name, float price, int amount);

    Product();

    const std::string &getName() const;

    void setName(const std::string &name);

    float getPrice() const;

    void setPrice(float price);

    std::string getDateOfReceiving() const;

    void setDateOfReceiving();

    int getAmount() const;

    void setAmount(int amount);

private:
    std::string name;
    float price;
    std::string dateOfReceiving;
    int amount;
};


#endif //WAREHOUSE_WORK_PRODUCT_H
