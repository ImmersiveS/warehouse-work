#include <iostream>
#include <cstdlib>
#include "NotNumberException.h"

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
            string::iterator it;
            for (it = buffChecker.begin(); it < buffChecker.end(); ++it)
                if (*it < '0' || *it > '9')
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
                //main actions
            }
            case 3:
                return 0;
            default:
                cout << "Wrong selection!" << endl;
        }
    }
}