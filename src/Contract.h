//
// Created by User on 19.11.2016.
//

#ifndef WAREHOUSE_WORK_CONTRACT_H
#define WAREHOUSE_WORK_CONTRACT_H
#include <iostream>
#include <vector>
#include "Product.h"
#include "Supplier.h"
#include "Client.h"
#include "Warehouse.h"

class Warehouse;
class Client;
class Supplier;
class Contract {
public:
    Contract(std::vector<Product> &products, Supplier &supplier, Warehouse &warehouse, int cost);

    Contract(std::vector<Product> &products, Client &client, Warehouse &warehouse, int cost);

    Contract();

    const std::vector<Product> &getProducts() const;

    void setProducts(const std::vector<Product> &products);

    Supplier *getSupplier() const;

    void setSupplier(Supplier *supplier);

    Warehouse *getWarehouse();

    void setWarehouse(Warehouse *warehouse);

    Client *getClient();

    int getCost();

    void setCost(int cost);

private:
    std::vector<Product> products;
//    std::unique_ptr<Supplier> supplier;
//    std::unique_ptr<Warehouse> warehouse;
//    std::unique_ptr<Client> client;
    Supplier* supplier;
    Warehouse* warehouse;
    Client* client;
    int cost;
};


#endif //WAREHOUSE_WORK_CONTRACT_H
