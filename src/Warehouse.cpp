#include "Warehouse.h"

const std::string &Warehouse::getName() const {
    return name;
}

void Warehouse::setName(const std::string &name) {
    Warehouse::name = name;
}

std::vector<Product> &Warehouse::getProducts() {
    return products;
}

void Warehouse::setProducts(const std::vector<Product> &products) {
    Warehouse::products = products;
}

Warehouse::Warehouse(const std::string &name, const std::vector<Product> &products) : accounting(*this), name(name), products(products)
{
    this->name = name;
    this->products = products;
}

Warehouse::Warehouse() : accounting(*this) { this->name = "unnamed"; }

Warehouse::Warehouse(const std::string &name) : accounting(*this), name(name) { this->name = name; }

void Warehouse::Accounting::sendRequest(Supplier& supplier, Request&& request) {
        supplier.getRequests().push_back(request);
        std::shared_ptr<Invoice> invoice(new Invoice(request.getProducts(), supplier));
        supplier.sendInvoice(this->getWarehouse(), *invoice);
}

void Warehouse::Accounting::payInvoice(Invoice& invoice) {
    invoice.setPaid(true);
    invoice.getSupplier()->sendProducts(this->getWarehouse(), invoice.getProducts());
}

void Warehouse::Accounting::sendInvoice( Client& client,  Invoice& invoice) {
    client.getInvoices().push_back(invoice);
}

void Warehouse::Accounting::sendProducts(Client &client, std::vector<Product> products) {
//    std::transform(proucts.begin(), proucts.end(), proucts.begin(),
//                   [](Product& product){ return product.setDateOfReceivingForClient();});
    for (int i = 0; i < products.size(); ++i) {
        products[i].setDateOfReceivingForClient();
        client.getProducts().push_back(products[i]);
    }
    client.countNumOfCompletedRequests();
    this->makeContractWithClient(this->getWarehouse(), products, client);
}

std::vector<Invoice> &Warehouse::Accounting::getInvoices() {
    return invoices;
}

void Warehouse::Accounting::setInvoices(const std::vector<Invoice> &invoices) {
    this->invoices = invoices;
}

Warehouse::Accounting::Accounting(Warehouse &warehouse) : warehouse(warehouse) {}

Warehouse &Warehouse::Accounting::getWarehouse() {
    return warehouse;
}

std::vector<Request> &Warehouse::Accounting::getRequests() {
    return requests;
}

void Warehouse::Accounting::setRequests(const std::vector<Request> &requests) {
    Accounting::requests = requests;
}

 std::vector<Contract> &Warehouse::Accounting::getContracts() {
    return contracts;
}

void Warehouse::Accounting::setContracts(const std::vector<Contract> &contracts) {
    Accounting::contracts = contracts;
}

void Warehouse::Accounting::makeContractWithSupplier(Warehouse &warehouse, std::vector<Product> products,
                                                      Supplier &supplier) {
    int cost = 0;
    for (auto item : products)
        cost += item.getPrice() * item.getAmount();
    std::shared_ptr<Contract> contract(new Contract(products, supplier, warehouse, cost));
    contracts.push_back(*contract);
}
void Warehouse::Accounting::makeContractWithClient(Warehouse &warehouse, std::vector<Product> products,
                                                     Client &client) {
    int cost = 0;
    for (auto item : products)
        cost += item.getPrice() * item.getAmount();
    std::shared_ptr<Contract> contract(new Contract(products, client, warehouse, cost));
    contracts.push_back(*contract);
}
