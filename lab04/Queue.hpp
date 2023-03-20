/* 
Lab #3
Edison Trinh
Class for Queue
*/

#include "SinglyLinkedList.hpp"

class Queue : private SinglyLinkedList {
    public:

        // Constructors & Destructors

        Queue() : SinglyLinkedList() {};
        ~Queue(){};

        // Class Manipulation Methods

        void Enqueue(Currency* object) {ListAppend(object);};
        Currency* Dequeue() {return this->removeCurrency(0);};
        void freeQueue() {this->freeLinkedList();};

        // Class Print Methods
        string printQueue() {return this->PrintList();};
        Currency* peekFront() {return this->getCurrency(0);};
        Currency* peekRear() {return this->getCurrency(this->GetCount() - 1);};

};

/*
void Enqueue(Currency* object) {ListAppend(object);};
    Pre: Currency object pointer 
    Post: used to insert into a function arguement
    Return None

    Since Enqueue simply adds a node to the end of a list I simply just reused the Listappend method
    which adds a node to the end of a list
*/

/*
Currency* Dequeue() {return this->removeCurrency(0);};
    Pre: None
    Post: None
    Return: currency object pointer

    Since Dequeue removes a list from the front of the list I again just removeCurrency which removes the first node in a list and returns it
*/

/*
void freeQueue() {this->freeLinkedList();};
    Pre: None
    Post: None
    ReturnL None

    Just frees the Queue by deallocating all the memory of it on the heap
*/

/*
string printQueue() {return this->PrintList();};
    Pre: None
    Post: None
    Return: string to print

    This reuses the Printlist method from singlylinkedlist class and all it does is just
    go through the node and saves the node index and data to a string and then later prints it
*/

/*
Currency* peekFront() {return this->getCurrency(0);};
    Pre: None
    Post: None

    Finds the node at the start and returns the value of it since it is peekfront

*/

/*
Currency* peekRear() {return this->getCurrency(this->GetCount() - 1);};
    Pre: None
    Post: None
    Return: Currency Pointer

    Finds the node at the end of the object by using getCurrency() and then input getCount() -1 since that would be the last index which is the rear
*/