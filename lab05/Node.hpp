#pragma once
#include "Currency.hpp"

class Node {
private:
    Currency* data;
    int key;
public:

    // Constructor & Destructor
    Node();
    Node(Currency* object);
    ~Node(){};

    int hash(Currency *object);

    // Setters & Getters
    int getKey();
    Currency* getData();

    void setKey(int newKey);
    void setData(Currency* newData);

};

Node::Node() {
    data = nullptr;
    key = 0;
}

Node::Node(Currency* object) {
    data = object;
    key = hash(object);
}

/*
    int Node::hash(Currency* object) 
    Pre: Currency* object
    Post: calculates a key value for it based on the equation
    Return: Key Value 

    Hashes the node item value first then returns the found key value
*/
int Node::hash(Currency* object) {
    int w = object->getWhole();
    int f = object->getFraction();
    int m = 2;
    int n = 3;

    int keyValue =  ((m * w) + (n * f)) % 29;
    return keyValue;
}

int Node::getKey() {
    return key;
}

Currency* Node::getData() {
    return data;
}

void Node::setKey(int newKey) {
    key = newKey;
}

void Node::setData(Currency* newData) {
    data = newData;
}