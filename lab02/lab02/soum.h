/*
Header File: SOUM
Description:
*/
#ifndef SOUM_H
#define SOUM_H

#include <iostream>
#include "currency.h"

class Soum : public Currency
{
protected:
    double input;
    string currency = "Soum";
    string get_currency()
    {
        return currency;
    }

private:
public:
    Soum() : Currency(){};
    Soum(double input) : Currency(input){};
    Soum(const Soum &origObject) : Currency(origObject){};
};

#endif