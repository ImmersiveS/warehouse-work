#include <iostream>
#include <cstdlib>
#include <memory>

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
                        "Assignment: implement the class long arithmetic within its operations and exception handling" << endl;
                break;
            }
            case 2:
            {
                unique_ptr<Supplier> sprite(new Supplier("Sprite", {{"Sprite", 7, 20}}));
                unique_ptr<Supplier> ferrero(new Supplier("Ferrero", {{"Nutella", 20, 15}}));
                shared_ptr<Client> ivan(new Client("Ivan"));
                shared_ptr<Client> irina(new Client("Irina"));
                unique_ptr<Warehouse> warehouse(new Warehouse("Petrovskiy", {{"Sprite", 7, 10}, {"Bread", 5, 15}}));
                ivan->sendRequest(*warehouse, Request({{"Sprite", 7, 2}, {"Bread", 5, 3}}));
                ivan->payInvoice(ivan->getInvoices().back());
                warehouse->accounting.sendRequest(*ferrero, Request({{"Nutella", 20, 2}}));
                warehouse->accounting.payInvoice(warehouse->accounting.getInvoices().back());
                cout << ivan->getProducts().back().getName() << " " << ivan->getProducts().back().getDateOfReceiving() << endl;
                cout << warehouse->getProducts().back().getName() << " " << warehouse->getProducts().back().getDateOfReceiving() << endl;
                break;
            }
            case 3:
                return 0;
            default:
                cout << "Wrong selection!" << endl;
        }
    }
}