/*
Header File: CURRENCY
Description:

*/
#ifndef CURRENCY_H
#define CURRENCY_H
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

class Currency
{
protected:
    int whole;
    int fractional;
    double f;
    double value;

public:
    // Constructors
    Currency(); // Default
    Currency(double input);
    Currency(const Currency &origObject); // Copy
    ~Currency();                          // Destructor

    // Prototypes
    //// Accessors
    int getWhole();
    int getFractional();
    double getValue();

    // Mutators
    void setWhole(const int num);
    void setFractional(const int num);
    void setValue(const double num);

    // Functions
    int add(double input);
    void subtract(double input);
    bool isEqual(Currency *curr);
    bool isGreater(Currency *curr);
    virtual void print();
    virtual string get_currency();
};

// Functions
//// Constructors
Currency::Currency()
{
    whole = 0;
    fractional = 0;
    f = fractional / 100;
    value = whole + f;
    cout << "Constructor created..." << endl;
}

Currency::Currency(double input)
{
    value = input;
}

Currency::Currency(const Currency &origObject)
{
}

Currency::~Currency()
{
    cout << "Destructor executed..." << endl;
}

// Accessors / Getters
/*
These functions are returns a value based on the set data type
Pre: int / double
Post: 
Return: int / double
*/
int Currency::getWhole()
{
    return whole;
}

int Currency::getFractional()
{
    return fractional;
}

double Currency::getValue()
{
    return value;
}

string Currency::get_currency()
{
    return string();
}
//// Mutators / Setters
/*
These functions are used to assign a value to the variable based on the input within the parameter
Pre: int / double
Post: int / double
Return: 
*/
void Currency::setWhole(int num)
{
    whole = num;
}

void Currency::setFractional(int num)
{
    fractional = num;
}

void Currency::setValue(double num)
{
    value = num;
}

//// Functions
/*
This function adds the inputted value to the current value.
Pre: input - a double datatype that is inputted to update the value
Post:
Return: 
*/
int Currency::add(double input)
{
    value+=input;
    return value;
}

/*
This function subtractss the inputted value from the current value.
Pre: input - a double datatype that is inputted to update the value
Post:
Return: 
*/
void Currency::subtract(double input)
{

    if (value >= input)     value = value-input;
    else                    throw "Invalid Subtraction";
}

/*
This function checks whether the inputted value equals to the current value.
Pre: *curr is a pointer that is a reference to the Currency object
Post:
Return: 
*/
bool Currency::isEqual(Currency *curr)
{
    if (value == curr->value)
        return true;
    else
        return false;
}

/*
This function checks whether the inputted value is greather than the current value.
Pre: *curr is a pointer that is a reference to the Currency object
Post:
Return: 
*/
bool Currency::isGreater(Currency *curr)
{
    if (whole < curr->whole)
    {
        return false;
    }
    return true;
}


/*
This function prints out the value and currency type
Pre:
Post:
Return: 
*/
void Currency::print()
{
    cout << setprecision(2) << fixed;
    cout << getValue() << " " << get_currency() << " ";

}

#endif