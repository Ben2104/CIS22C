/* 
Lab #3
Edison Trinh
Hoang Khoi Do
Class for SinglyLinkedList 
*/

#pragma once
#include <string>
#include "LinkNode.hpp"
#include "Currency.hpp"
#include "Krone.hpp"

class SinglyLinkedList {
    private:
        int count;
        LinkNode* start;
        LinkNode* end;
    public:

        // Constructor & Destructor

        SinglyLinkedList() {start = nullptr; end = nullptr; count = 0;};
        ~SinglyLinkedList(){};

        // Class Manipulation Methods

        void ListAppend(Currency* data);
        void addCurrency(Currency* data, int index);
        Currency* removeCurrency(Currency* object);
        Currency* removeCurrency(int index);

        
        void freeLinkedList();

        // Getters & Setters
    
        LinkNode* getStart() {return start;};
        Currency* getCurrency(int index);
        int GetCount() {return count;};
        int countCurrency() {return count;};

        void setStart(LinkNode* newStart) {start = newStart;};

        // Class Print Methods
        string PrintList();
        bool isListEmpty();
        int findCurrency(Currency* object);
};


/*
void SinglyLinkedList::ListAppend(Currency* data)
    Pre: data - currency pointer
    Post: Used to give data to our linknode 
    Return: None

    This method appends a new node to the end of a linked list by setting the head to the node we want to add if the list is empty or setting the tail node next pointer to it and setting it to the tail node
*/

void SinglyLinkedList::ListAppend(Currency* data) {

    LinkNode* newNode = new LinkNode(data);

    if (start == nullptr) {
        start = newNode;
        end = newNode; 
    } else {
        end->setNext(newNode);
        end = newNode;
    }
    count++;
    
}

/*
void SinglyLinkedList::addCurrency(Currency* data, int index)
    Pre: data - Currency Pointer 
         index - the index location
    Post: No changes to the parameter variable
    Return: none

    This method adds a object of currency to the linked list and has two parameter one for the actual data we would like to add and 2nd the index
    for the index of where we want to add our new node

*/
void SinglyLinkedList::addCurrency(Currency* data, int index) {

    try {
        if (index < 0 || index > count) {
            throw index;
        } 

        LinkNode* newNode = new LinkNode(data);

        if (start == nullptr) {
            start = newNode;
            end = newNode; 
        } else if (index == 0) {
            newNode->setNext(start);
            start = newNode;
        } else if (index == count) {
            end->setNext(newNode);
            end = newNode;
        } else {
            LinkNode* curNode = start; 
            for (int i = 0; i < index - 1; i++) {
                curNode = curNode->getNext();
            }
            newNode->setNext(curNode->getNext());
            curNode->setNext(newNode);
        }
        
    } catch (int ex) {
        cout << "Exception : Out of range!";
    }
    
}

/*
string SinglyLinkedList::PrintList()
    Pre: None
    Post: None
    Return: string of all the data in the linked list

    This method stores all the data of the linked list and index of it into a string and returns it by traversing each node
    and using getters to store all the data of that node into a string variable which then returns it at the end
*/
string SinglyLinkedList::PrintList() {
    LinkNode* curNode = start;
    int number = 0;
    string list;

   while (curNode != nullptr) { 
        string sNumber =  "(" +  to_string(number) + ")";
        list += sNumber + " ";
        list += to_string(curNode->getData()->getWhole()) + "." + to_string(curNode->getData()->getFraction());
        list += "    ";
        curNode = curNode->getNext();
        number++;
    }
    return list;
}

/*
Currency* SinglyLinkedList::removeCurrency(Currency* object)
    Pre: object pointer of type currency
    Post: No changes to parameter variable just used as a reference to look for something
    return: pointer of a currency object

    This method removes an object in the linked list by taking in a pointer of a currency object and traverses through the node
    and if it finds a node with the same data as it then it would remove it by setting the node before it to point to the node ahead of it
    and changing its next pointer value to nullptr which effectivly removes it from the list since the pointer before it doesnt point to it anymore and 
    instead points to the node in front of it then returns the removed node adress

*/
Currency* SinglyLinkedList::removeCurrency(Currency* object) {
    LinkNode* curNode = start;
    while (curNode != nullptr) {
        if (curNode->getNext()->getData()->getWhole() == object->getWhole() && curNode->getNext()->getData()->getFraction() == object->getFraction()) {
            LinkNode* sucNode = curNode->getNext();
            curNode->setNext(sucNode->getNext());
            sucNode->setNext(nullptr);
            return object;
        } else if (curNode->getData()->getWhole() == object->getWhole() && curNode->getData()->getFraction() == object->getFraction()) {
            LinkNode* sucNode = curNode->getNext();
            start->setNext(nullptr);
            start = sucNode;
            return object;
        }
        curNode = curNode->getNext();
    }
    return nullptr;
}


/*
Currency* SinglyLinkedList::removeCurrency(int index)
    Pre: index
    Post: No changes just used as a reference to find something
    return: index number of removed node

    It would remove a node in the linked list based on its index position by traversing the list
    until it finds one with the same index as the arguement index then removes it by setting the
    previous next pointer of that node to the one ahead of it also sets the removed node next pointer
    to null and then returns the memory address of the removed object.
*/

Currency* SinglyLinkedList::removeCurrency(int index) {
    LinkNode* curNode = start;
    int number = 0;

    while (curNode != nullptr) {
        if (number == index && curNode == start) {
            LinkNode* sucNode = curNode->getNext();
            start->setNext(nullptr);
            start = sucNode;
            return start->getData();
        } else if (number + 1 == index) {

            LinkNode* sucNode = curNode->getNext();
            curNode->setNext(sucNode->getNext());
            sucNode->setNext(nullptr);
            return sucNode->getData();
        }
        curNode = curNode->getNext();
        number++;
    }
    
    return nullptr;
}


/*
int SinglyLinkedList::findCurrency(Currency* object)
    Pre: Currency object pointer
    Post: no changes used as ref
    return: index of object found

    This method searches for an object in the linked list based on the data put in as a arguement
    so it traverses the list until it finds a node with the same data type as the arguement and then returns
    the index
*/
int SinglyLinkedList::findCurrency(Currency* object) {
    int number = 0;
    LinkNode* curNode = start;

    if (start == nullptr) {
        return -1;
    } else {
        while (curNode != nullptr) {
            if (curNode->getData()->getWhole() == object->getWhole() && curNode->getData()->getFraction() == object->getFraction()) {
                return number;
            }
            curNode = curNode->getNext();
            number++;
        }
    }
    return -1;
}

/*
Currency* SinglyLinkedList::getCurrency(int index)
    Pre: index - position of
    Post: just used as ref no change
    Return: a pointer to a currency object

    It checks if the linked list is empty if it is it will throw  an exception while it isnt empty
    it would then traverse through the list into it reaches a node with the same index as the arguement then
    it would return the object that matched the index back
*/

Currency* SinglyLinkedList::getCurrency(int index) {
    
    try {
        if (index < 0 || index > count) {
            throw index;
        } 

        int number = 0;
        LinkNode* curNode = start;

        if (start == nullptr) {
            throw start;
        } else {
            while (curNode != nullptr) {
                if (number == index) {
                    return curNode->getData();
                }
                curNode = curNode->getNext();
                number++;
            }
            return nullptr;
        }
    } catch (int ex) {
        cout << "Exception : Out of range!";
        return nullptr;
    } catch (LinkNode* ex) {
        cout << "Exception : Empty List!";
        return nullptr;
    }
}

/*
bool SinglyLinkedList::isListEmpty()
    Pre: None
    Post: None
    Return: True or False

    Checks if the start has a pointer to another object and if it doesnt then that means is empty 
    then it would return true if it is empty else false

*/
bool SinglyLinkedList::isListEmpty() {
    if (start == nullptr) {
        return true;
    } else {
        return false;
    }
}


/*
void SinglyLinkedList::freeLinkedList()
    Pre: None
    Post: None
    ReturnL None

    Traverse through the linked list and deletes the allocated memory on the heap as it goes throug hthe list
*/
void SinglyLinkedList::freeLinkedList() {
    LinkNode* curNode = start;
    LinkNode* sucNode;
    while(curNode != nullptr) {
        sucNode = curNode->getNext();
        delete curNode;
        curNode = sucNode;
    }
}