//
// Created by user on 15.11.2016.
//

#ifndef WAREHOUSE_WORK_NOTNUMBEREXCEPTION_H
#define WAREHOUSE_WORK_NOTNUMBEREXCEPTION_H


#include "WarehouseWorkException.h"

class NotNumberException : public  WarehouseWorkException
{
public:
    const void what() const { cout << "Invalid input data" << endl; }
};


#endif //WAREHOUSE_WORK_NOTNUMBEREXCEPTION_H
