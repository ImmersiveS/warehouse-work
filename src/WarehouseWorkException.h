#ifndef WAREHOUSE_WORK_WAREHOUSEWORKEXCEPTION_H
#define WAREHOUSE_WORK_WAREHOUSEWORKEXCEPTION_H

#include <iostream>
using namespace std;

class WarehouseWorkException
{
public:
    virtual const void what() const { cout << "WarehouseWork exception called" << endl;}
};


#endif //WAREHOUSE_WORK_WAREHOUSEWORKEXCEPTION_H
