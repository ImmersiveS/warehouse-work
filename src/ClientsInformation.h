//
// Created by User on 19.11.2016.
//

#ifndef WAREHOUSE_WORK_CLIENTSINFORMATION_H
#define WAREHOUSE_WORK_CLIENTSINFORMATION_H
#include <iostream>

template<class ...Clients>
class ClientsInformation : public Clients...
{
public:
    ClientsInformation(const Clients&... clients) : Clients(clients)... {}
};
#endif //WAREHOUSE_WORK_CLIENTSINFORMATION_H
