#include <iostream>
#include <cstdlib>
#include <memory>

#include "NotNumberException.h"
#include "Product.h"
#include "Client.h"
#include "ClientsInformation.h"

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
                unique_ptr<Warehouse> warehouse(new Warehouse("Petrovskiy", {{"Sprite", 7, 10}, {"Bread", 5, 15}, {"Iphone 7", 2000, 100}}));

                unique_ptr<Supplier> sprite(new Supplier("Sprite", {{"Sprite", 7, 20}}));
                unique_ptr<Supplier> ferrero(new Supplier("Ferrero", {{"Nutella", 20, 15}}));
                shared_ptr<Supplier> apple (new Supplier("Apple", {{"Iphone 7", 2000, 3000}}));

                shared_ptr<Client> ivan (new Client("Ivan"));
                shared_ptr<Client> jane (new Client("Jane"));
                shared_ptr<Client> bobDylan(new Client("Bob Dylan"));

                warehouse->accounting.sendRequest(*apple, Request({{"Iphone 7", 2000, 100}}));
                warehouse->accounting.payInvoice(warehouse->accounting.getInvoices().back());

                ivan->sendRequest(*warehouse, Request({{"Sprite", 7, 2}, {"Bread", 5, 3}}));
                ivan->sendRequest(*warehouse, Request({{"Bread", 5, 4}}));
                ivan->payInvoice(*warehouse, ivan->getInvoices().back());

                jane->sendRequest(*warehouse, Request({{"Iphone 7", 2000, 1}}));

                bobDylan->sendRequest(*warehouse, Request({{"Iphone 7", 2000, 1}}));
                bobDylan->sendRequest(*warehouse, Request({{"Sprite", 7, 2}}));
                bobDylan->sendRequest(*warehouse, Request({{"Bread", 5, 2}}));
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

                ClientsInformation<Client>** pClientsInformation = new ClientsInformation<Client>*[3];
                    pClientsInformation[0] = new ClientsInformation<Client>(*ivan);
                    pClientsInformation[1] = new ClientsInformation<Client>(*jane);
                    pClientsInformation[2] = new ClientsInformation<Client>(*bobDylan);
                for (int i = 0; i < 3; ++i) {
                    pClientsInformation[i]->countNumOfUnpaidInvoices();
                    cout << "\nNumber of " << pClientsInformation[i]->getName() << "'s requests: "
                         << pClientsInformation[i]->getNumOfRequest();
                    cout << "\nNumber of" << pClientsInformation[i]->getName() << "'s unpaid requests: "
                         << pClientsInformation[i]->getNumOfUnpaidInvoices();
                    cout << "\nNumber of" << pClientsInformation[i]->getName() << "'s completed requests: "
                         << pClientsInformation[i]->getNumOfCompletedRequests();
                }
                for (int i = 0; i < 3; ++i)
                    delete pClientsInformation[i];
                delete[] pClientsInformation;
                break;
            }
            case 3:
                return 0;
            default:
                cout << "Wrong selection!" << endl;
        }
    }
}