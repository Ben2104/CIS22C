/* 
Lab #3
Edison Trinh
Hoang Khoi Do   
Krone Class a derived class from base class Currency
*/



#pragma once
#include "Currency.hpp"


class Krone : public Currency {
    private:
        string name = "Krone";
    public:
    // Default Constructor
    Krone() : Currency() {};
    // Parameter Constructor
    Krone(double value) : Currency(value) {};
    // Copy Constructor
    Krone(Krone& value) : Currency(value) {};
    //Destructor
    ~Krone(){};

    // Getter
    string getName()  {
        return name;
    }
    // print
    
    
};