/*
Lab        : #2
Name       : Brandon Hung & Hoang Khoi Do
Description: Object-Oriented Programming
*/

// Libraries
#include <iostream>


// Header Files
#include "currency.h"
#include "krone.h"
#include "soum.h"

using namespace std;

// Main Function
int main()
{
    // Variables
    char method = 'z';
    char currency_initial;
    double value;
    string currency_name;

    Currency *currency[2];
    currency[0] = new Soum(0);
    currency[1] = new Krone(0);
    currency[0]->print();
    currency[1]->print();
    cout << endl;

    cout << "Program Starts" << endl;
    while (true)
    {
        try{
            cin >> method;
        if (method == 'q')
        {
            break;
        }
        cin >> currency_initial >> value >> currency_name;
        if (currency_initial == 'k' && currency_name == "Krone")
        {
            switch (method)
            {
            case 'a':
                currency[1]->add(value);
                currency[0]->print();
                currency[1]->print();
                cout << endl;
                break;
            case 's':
                currency[1]->subtract(value);
                currency[0]->print();
                currency[1]->print();
                cout << endl;
                break;
            default:
                cout << "Invalid" << endl;
            }
        }
        else if (currency_initial == 's' && currency_name == "Soum")
        {
            switch (method)
            {
            case 'a':
                currency[0]->add(value);
                currency[0]->print();
                currency[1]->print();
                cout << endl;
                break;
            case 's':
                currency[0]->subtract(value);
                currency[0]->print();
                currency[1]->print();
                cout << endl;
                break;
            default:
                throw "Invalid method";
            }
        }
        else
        {
            throw "Invalid Addtion";
            currency[0]->print();
            currency[1]->print();
            cout << endl;
        }
        }
        catch(const char e[])
        {
            cout << e << endl;
        }
    }
    cout << "Program Exited" << endl;

    return 0; // Terminate
}