#include "Invoice.h"

std::vector<Product> &Invoice::getProducts(){
    return products;
}

void Invoice::setProducts(const std::vector<Product> &products) {
    Invoice::products = products;
}

bool Invoice::isPaid() {
    return paid;
}

void Invoice::setPaid(bool isPaid) {
    Invoice::paid = isPaid;
}

Invoice::Invoice(std::vector<Product> &products, Warehouse& warehouse) : products(products), paid(false), dateOfPaying("non-existent")
{
    this->warehouse = std::make_shared<Warehouse>(warehouse);
    this->supplier = nullptr;
    cost = 0;
    for (auto item : products)
        cost += item.getPrice() * item.getAmount();
}

Invoice::Invoice(std::vector<Product> &products, Supplier& supplier) : products(products), paid(false), dateOfPaying("non-existent")
{
    this->supplier = std::make_shared<Supplier>(supplier);
    this->warehouse = nullptr;
    cost = 0;
    for (auto item : products)
        cost += item.getPrice() * item.getAmount();
}

std::shared_ptr<Supplier> Invoice::getSupplier() {
    return supplier;
}
