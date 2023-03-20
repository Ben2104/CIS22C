/* 
Lab #3
Edison Trinh
Hoang Khoi Do
Class for Stack
*/

#include "SinglyLinkedList.hpp"

class Stack : private  SinglyLinkedList {
    public:

        //Constructor & Destructors

        Stack() : SinglyLinkedList() {};
        ~Stack(){};

        // Class Manipulation Methods


        void push(Currency* object) {this->addCurrency(object, 0);};


        Currency* pop() {return this->removeCurrency(0);};
        void freeStack() {this->freeLinkedList();};

        // Print Stack

        string printStack() {return this->PrintList();};
        Currency* peek() {return this->getCurrency(0);};

};

/*
 void push(Currency* object)
    Pre: object - object we are pushing onto stack
        0 - since is a stack we push to the top of a stack so index 0
    Post: variable does not chabge
        Return: None

    We are just basically referring to our method in SinglyLinkedList class since we are pushing something onto a stack
    its the same as adding a new object to the index 0 of a linked list so we just reuse
*/


/*
Currency* pop() {return this->removeCurrency(0);};
    Pre: index 0
    Post: None
    Return: Currency object pointer

    Since pop removes the first element of a stack we can just reuse the method from linkedlist class since all we have to do is
    just remove the first object in the stack so we just return removeCurrency(0)
*/

/*
void freeStack() {this->freeLinkedList();};
    Pre: None
    Post: None
    Return: None

    We are simply just using the code as we had in the linkedlist class to free memory
*/

/*
string printStack() {return this->PrintList();};
    Pre: None
    Post: None
    Return: string

    Same pseudocode as printlist in SinglyLinkedList
*/

/*
Currency* peek() {return this->getCurrency(0);}
    Pre: None
    Post: None
    Return: returning currency pointer of an object

    Since peeks feature allows it to look at the item in the top of the stack that is equivlent to the 0th index of a linked list
    so we just use a linked list method which returns the object that is at the 0th index of the list.

*/

