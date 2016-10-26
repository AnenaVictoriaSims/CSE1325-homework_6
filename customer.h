#ifndef _CUSTOMER_H_
#define _CUSTOMER_H_

#include "std_lib_facilities.h"
//#include "orders.h"


class Customer
{
    public:
        void setName(string n);
        string getName();
    private:
        string name;
};
#endif // _CUSTOMER_H_


