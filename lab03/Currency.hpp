
/* 
Lab #3
Hoang Khoi Do 
Edison Trinh
Base class with all the methods for the inherited class to use
*/

#pragma once
#include <iostream>
#include <string>
using namespace std;

class Currency {

private:
    int whole;
    int fraction; 
public:
    
    /*
    Constructors
    Pre: Parameter Value, Object
    Post: Creates a object with given arguements
    return: None    
    */

    // Default Constructor
    Currency();
    // Constructor with parameters
    Currency(double value);
    //Copy Constructor
    Currency(Currency& value);

    // Destructor 

    ~Currency() {};

    /* Getters
    Pre: Void
    Post: Void
    Return: Returns value of the variable its getting
    */ 

    int getWhole();
    int getFraction();
    virtual string getName() = 0;

    /* Setters
    Pre: Int value
    Post: Changes our objects variable value
    return: Void
    */

    void setWhole(int value);
    void setFraction(int value);

    /* Add 
    Pre: Currency Object
    Post: Object whole & fraction variable
    return: Nothing
    */

    void add(Currency& input);

    /*Subtract
    Pre: Currency Object
    Post: Object whole and fraction variable changed
    return nothing;
    */

    void subtract(Currency& input);

    /* Equal
    Pre: Currency Object
    Post: Nothing Changed
    Return: True Or False
    */

    bool isEqual(Currency& input);
    
    /* Greater
    Pre: Currency Object
    Post: Nothing Changed
    Return: True Or False
    */

    bool isGreater(Currency& input);
    
    /*Print
    Pre: Nothing
    Post: Prints object data
    return: Nothing
    */

    void print() {
        cout << "|" << this->getWhole() << "." << this->getFraction() << " " << this->getName() << "|";
    }
};

//Constructors

Currency::Currency() {
    whole = 0;
    fraction = 0;
}

Currency::Currency(double value) {
    if (value < 0) {
        cout << "Invalid.";

    } else {
        whole = value;
        fraction = (value - whole) * 101;
    }
}

 Currency::Currency(Currency& value) {
    whole = value.whole;
    fraction = value.fraction;
}

// Getters
int Currency::getWhole() {
    return whole;
}

int Currency::getFraction() {
    return fraction;
}

// Setters

void Currency::setWhole(int value) {
    whole = value;
}

void Currency::setFraction(int value) {
    fraction = value;
}

// Add

void Currency::add(Currency& input) {
    try {
        if (this->getName() != input.getName()) {
            throw this->getName();
        } 

        whole = whole + input.whole;
        fraction = fraction + input.fraction;

        if (fraction >= 100) {
            whole += 1;
            fraction -= 100;
        }
    }

    catch (string ex) {
        cout << "Exception: Invalid addition." << endl;
    }  
    
}
// Subtract

void Currency::subtract(Currency& input) {
    
    try {
        int exCheckW = whole - input.whole;
        int exCheckF = fraction;

        if (fraction < input.getFraction()) {
            exCheckW -= 1;
            exCheckF = (exCheckF - input.fraction) + 100;
        }

        if (this->getName() != input.getName()) {
            throw this->getName();
        } 
        
        if (exCheckW < 0) {
            throw exCheckW;
        }


        whole = whole - input.whole;
        if (fraction < input.getFraction()) {
            whole -= 1;
            fraction = (fraction - input.fraction) + 100;
        } else {
            fraction = fraction - input.fraction;
        }

        
    } catch (string ex) {
        cout << "Exception: Invalid subtraction." << endl;
    }  catch (int ex) {
        cout << "Exception: Invalid subtraction (negative)" << endl;
    }
}

bool Currency::isEqual(Currency& input) {
    bool value;
    try {
        if (this->getName() != input.getName()) {
            throw this->getName();
        } 

        if (whole == input.getWhole() && fraction == input.getFraction()) {
            value = true;
        } else {
            value = false;
        }
    } catch (string ex) {
        cout << "Exception: Invalid comparison.";
    }
    return value;
}

bool Currency::isGreater(Currency& input) {
    try {
        bool rValue;
        if (whole > input.getWhole()) {
            rValue = true;
        } else if (whole == input.getWhole()) {
            if (fraction > input.getFraction()) {
                rValue = true;
            }
        } else {
            rValue = false;
        }
        return rValue;
    } catch (string ex) {
        cout << "Exception: Invalid comparison.";
    }
    
}

