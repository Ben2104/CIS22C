/* 
Lab #3
Edison Trinh
Hoang Khoi Do
Main file to demonstrate LinkedList, Stack, and Queues through manipulating them with their class methods.
*/



#include <iostream>
#include <string>
using namespace std;
#include "Currency.hpp"
#include "Krone.hpp"
#include "SinglyLinkedList.hpp"
#include "LinkNode.hpp"
#include "Stack.hpp"
#include "Queue.hpp"


int main() {
    Currency *currencies[] = {new Krone(57.12), new Krone(23.44), new Krone(87.43), new Krone(68.99), new Krone(111.22),
                              new Krone(44.55), new Krone(77.77), new Krone(18.36), new Krone(543.21), new Krone(20.21),
                              new Krone(345.67), new Krone(36.18), new Krone(48.48), new Krone(101.00), new Krone(11.00),
                              new Krone(21.00), new Krone(51.00), new Krone(1.00), new Krone(251.00), new Krone(151.00) 
                              };

    SinglyLinkedList linkedList;
    Stack stackList;
    Queue queueList;

    cout << "Hi, Im Edison Trinh. Welcome to my program demonstrating Linked Lists, Stacks, and Queues" << endl;
    cout << "[Click Enter To Continue] ";
    cin.ignore();

    cout << "\n\nLinked List" << endl;
    cout << "__________________________________________________________________________________________\n\n";

    linkedList.ListAppend(currencies[6]);
    linkedList.ListAppend(currencies[5]);
    linkedList.ListAppend(currencies[4]);
    linkedList.ListAppend(currencies[3]);
    linkedList.ListAppend(currencies[2]);
    linkedList.ListAppend(currencies[1]);
    linkedList.ListAppend(currencies[0]);

   for (int i = 7; i < 20; i++) {
    linkedList.ListAppend(currencies[i]);
   }
   
   cout << linkedList.findCurrency(new Krone(87.43)) << endl;
   cout << linkedList.findCurrency(new Krone(44.56)) << endl;
   linkedList.removeCurrency(currencies[4]);
   cout << linkedList.PrintList() << endl;

   linkedList.addCurrency(currencies[8], linkedList.findCurrency(currencies[8]) % 5);
   linkedList.addCurrency(currencies[9], linkedList.findCurrency(currencies[9]) % 5);
   linkedList.addCurrency(currencies[10], linkedList.findCurrency(currencies[10]) % 5);
   linkedList.addCurrency(currencies[11], linkedList.findCurrency(currencies[11]) % 5);

   linkedList.removeCurrency(linkedList.GetCount() % 6);
   linkedList.removeCurrency(linkedList.GetCount() / 7);
   cout << linkedList.PrintList() << endl;



    // Stack  

    cout << "\n\nStack" << endl;
    cout << "__________________________________________________________________________________________\n\n";

    for (int j = 13; j < 20; j++) {
        stackList.push(currencies[j]);
    }

    
    cout << stackList.peek()->getWhole() << "." << stackList.peek()->getFraction() << endl;
    stackList.pop();
    stackList.pop();
    stackList.pop();
    cout << stackList.printStack() << endl;

    for (int j = 0; j < 5; j++) {
        stackList.push(currencies[j]);
    }

    stackList.pop();
    stackList.pop();
    cout << stackList.printStack();


    // Queue

    cout << "\n\nQueue" << endl;
    cout << "__________________________________________________________________________________________\n\n";

    queueList.Enqueue(currencies[5]);
    queueList.Enqueue(currencies[7]);
    queueList.Enqueue(currencies[9]);
    queueList.Enqueue(currencies[11]);
    queueList.Enqueue(currencies[13]);
    queueList.Enqueue(currencies[15]);
    queueList.Enqueue(currencies[17]); 

    cout << queueList.printQueue() << endl;

    cout << queueList.peekFront()->getWhole() << "." << queueList.peekFront()->getFraction() << endl;
    cout << queueList.peekRear()->getWhole() << "." << queueList.peekRear()->getFraction() << endl;

    queueList.Dequeue();
    queueList.Dequeue();

    cout << queueList.printQueue() << endl;

    queueList.Enqueue(currencies[10]);
    queueList.Enqueue(currencies[11]);
    queueList.Enqueue(currencies[12]);
    queueList.Enqueue(currencies[13]);
    queueList.Enqueue(currencies[14]);
    
    queueList.Dequeue();
    queueList.Dequeue();
    queueList.Dequeue();

    queueList.printQueue();


    linkedList.freeLinkedList();
    stackList.freeStack();
    queueList.freeQueue();

    for (int f = 0; f < 20; f++) {
        delete(currencies[f]);
    }

    cout << "\n\n\nAll memory on heap sucessfully deallocated. Program has terminated.";

}
    