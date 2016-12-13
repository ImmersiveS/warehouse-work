#ifndef WAREHOUSE_WORK_CONTRACT_H
#define WAREHOUSE_WORK_CONTRACT_H
#include <iostream>
#include <vector>
#include <memory>
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

    std::shared_ptr<Supplier> getSupplier() const;

    std::shared_ptr<Warehouse> getWarehouse();

    std::shared_ptr<Client> getClient();

    int getCost();

    void setCost(int cost);

private:
    std::vector<Product> products;
    std::shared_ptr<Warehouse> warehouse;
    std::shared_ptr<Supplier> supplier;
    std::shared_ptr<Client> client;
    int cost;
};


#endif //WAREHOUSE_WORK_CONTRACT_H
