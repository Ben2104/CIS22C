/*
Header File: KRONE
Description:
*/
#ifndef KRONE_H
#define KRONE_H

#include <iostream>
#include "currency.h"

class Krone : public Currency
{
protected:
    double input;
    string currency = "Krone";
    string get_currency()
    {
        return currency;
    }
    
private:
public:
    Krone() : Currency(){};
    Krone(double input) : Currency(input){};
    Krone(const Krone &origObject) : Currency(origObject){};
    
};

#endif