/*
Lab #5
Edison Trinh 
Hoang Khoi Do
HashTable class with all the methods include insert and search.
*/
#pragma once
#include "Currency.hpp"
#include "Node.hpp"
#include <iomanip>

class HashTable {
private:
    static const int SIZE = 29;
    Currency* table[SIZE];
    int collision;
public:
    //Constructor
    HashTable();
    //Destructor
    ~HashTable(){};
    //Function
    void miscInfo();
    bool hashInsert(Node nodeToInsert);
    Currency* search(Currency* itemToSearchFor);
};
//Constructor
HashTable::HashTable() {
    collision = 0;
    for (int i = 0; i < SIZE; i++) {
        table[i] = nullptr;
    }
}

/*
    bool HashTable::hashInsert(Node nodeToInsert)
    Pre: nodeToInsert
    Post: Insert node's data to hash
    return: True or False 

    Inserts the node data into the hash table according to its key
*/
bool HashTable::hashInsert(Node nodeToInsert) {
    int bucketsProbed = 0;
    int bucket = nodeToInsert.getKey();
    int i = 0;

    while (bucketsProbed < SIZE) {
        if (table[bucket] == nullptr) {
            table[bucket] = nodeToInsert.getData();
            return true;
        }
        i = i + 1;
        bucket = (nodeToInsert.getKey() + i + i * i) % SIZE;
        bucketsProbed += 1;
        collision += 1;
        cout << "Already FULL! Trying again @" << bucket << endl;
    }
    return false;
}

/* miscInfo
Pre: None
Post: Prints Load data, Load Factor, number of Collisions
return: Nothing

Prints out all the misc information such as the items loaded the load factor and the number of collisions that happen during insert
*/
void HashTable::miscInfo() {
    int dataItemsLoaded = 0; 
    for (int i = 0; i < SIZE; i++) {
        if (table[i] != nullptr) {
            dataItemsLoaded += 1;
        }
    }
    double loadFactor = dataItemsLoaded;
    cout << "Number of data items loaded: " << dataItemsLoaded << endl;
    cout << "Load Factor: " << fixed << setprecision(2) << loadFactor / SIZE << endl;
    cout << "Number of Collisions: " << collision << endl;
}
/* search
Pre: Currency Object
Post: Return the key if it finds it. If the key is not found it will return null

searches for a item value in the hash table and if it doesn't find it it will keep quadratically probing until it does 
*/
Currency* HashTable::search(Currency* itemToSearchFor) {
    Node searchFor(itemToSearchFor);
    int i = 0;
    int bucketsProbed = 0;
    int bucket =  searchFor.getKey();

    while (bucketsProbed < SIZE) {
        if (table[bucket] != nullptr && table[bucket]->getWhole() == searchFor.getData()->getWhole() && table[bucket]->getFraction() == searchFor.getData()->getFraction()) {
            cout << "Found @ Index: " << bucket << endl;
            return table[bucket];
        }
        i = i + 1;
        bucket = (searchFor.getKey() + i + i * i) % SIZE;
        bucketsProbed += 1;
    }
    throw string("Invalid Data");
    return nullptr;
}