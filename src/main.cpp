#include <iostream>
#include <cstdlib>
#include <memory>
#include <tuple>

#include "NotNumberException.h"
#include "Product.h"
#include "Client.h"

using namespace std;

int main()
{
    string buffChecker;
    int checker;
    while (true) {

        cout << "\nChoose operation: "
                "\n1)Read general information"
                "\n2)See report of warehouse work"
                "\n3)Quit" << endl;
        try {
            cin >> buffChecker;

            for (auto item : buffChecker)
                if (item < '0' || item > '9')
                    throw NotNumberException();
            checker = atoi(buffChecker.c_str());
        }
        catch (const WarehouseWorkException &e) {
            e.what();
            continue;
        }
        catch (...) {
            cerr << "Undefined exception called" << endl;
            continue;
        }

        switch(checker)
        {
            case 1:
            {
                cout << "FN: Lobachev S.U.\nVariant: 8\nLevel: V\n"
                        "Assignment: simulate work of warehouse with interruption with clients and suppliers" << endl;
                break;
            }
            case 2:
            {
                unique_ptr<Warehouse> warehouse(new Warehouse("Petrovskiy", {{"Sprite", 7, 10}, {"Bread", 5, 15}, {"Iphone 7", 2000, 100}, {"Nobel Prize", 0, 10}}));

                auto sprite = make_unique<Supplier>(Supplier("Sprite", {{"Sprite", 7, 20}}));
                auto ferrero = make_unique<Supplier>(Supplier("Swedesh institute", {{"Nobel Prize", 0, 15}}));
                auto apple = make_unique<Supplier>(Supplier("Apple", {{"Iphone 7", 2000, 3000}}));

                auto ivan = make_shared<Client>(Client("Ivan"));
                auto jane = make_shared<Client>(Client("Jane"));
                auto bobDylan = make_shared<Client>(Client("Bob Dylan"));

                warehouse->accounting.sendRequest(*apple, Request({{"Iphone 7", 2000, 100}}));
                warehouse->accounting.payInvoice(warehouse->accounting.getInvoices().back());

                ivan->sendRequest(*warehouse, Request({{"Sprite", 7, 2}, {"Bread", 5, 3}}));
                ivan->sendRequest(*warehouse, Request({{"Bread", 5, 4}}));
                ivan->payInvoice(*warehouse, ivan->getInvoices().back());

                jane->sendRequest(*warehouse, Request({{"Iphone 7", 2000, 1}}));

                bobDylan->sendRequest(*warehouse, Request({{"Iphone 7", 2000, 1}}));
                bobDylan->sendRequest(*warehouse, Request({{"Sprite", 7, 2}}));
                bobDylan->sendRequest(*warehouse, Request({{"Nobel Prize", 5, 2}}));
                for (int i = 0; i < 3; ++i)
                    bobDylan->payInvoice(*warehouse, bobDylan->getInvoices()[i]);

                for (auto &item: warehouse->accounting.getContracts())
                {
                    if (!&item)
                        cout << "There are no operations done in the warehouse" << endl;
                    else {
                        if (item.getSupplier() != nullptr)
                            cout << "Contract between " << item.getWarehouse()->getName() << " and "
                                 << item.getSupplier()->getName() << endl;
                        if (item.getClient() != nullptr)
                            cout << "Contract between " << item.getWarehouse()->getName() << " and "
                                 << item.getClient()->getName() << endl;
                        for (auto &prod : item.getProducts())
                            cout << "Products: name: " << prod.getName() << " price " << prod.getPrice() <<
                                 " amount " << prod.getAmount() << " date of receiving " << prod.getDateOfReceiving();
                        cout << "Full cost: " << item.getCost() << endl;
                        cout << endl;
                    }
                }

                vector<shared_ptr<Client>> allClients = {ivan, jane, bobDylan};
                auto clientsInfo = [&](int id)->tuple<string, int, int, int>
                {
                    allClients[id]->countNumOfUnpaidInvoices();
                    return make_tuple(allClients[id]->getName(),
                                      allClients[id]->getNumOfRequest(),
                                      allClients[id]->getNumOfUnpaidInvoices(),
                                      allClients[id]->getNumOfCompletedRequests());
                };

                for (int i = 0; i < allClients.size(); ++i) {
                    auto client0 = clientsInfo(i);
                    cout << "\nNumber of " << get<0>(client0) << "'s requests: "
                         << get<1>(client0);
                    cout << "\nNumber of" << get<0>(client0) << "'s unpaid requests: "
                         << get<2>(client0);
                    cout << "\nNumber of" << get<0>(client0) << "'s completed requests: "
                         << get<3>(client0);
                }
                break;
            }
            case 3:
                return 0;
            default:
                cout << "Wrong selection!" << endl;
        }
    }
}