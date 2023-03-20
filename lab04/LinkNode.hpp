#pragma once
#include "Currency.hpp"


class LinkNode {
    private:
        Currency* data;
        LinkNode* next;
        
    public: 
        LinkNode(Currency* data) {this->data = data; this->next = nullptr;}
        ~LinkNode(){};
    
        // Getters & Setters

        LinkNode* getNext() {
            return next;
        }

        Currency* getData() {
            return data;
        }

        void setNext(LinkNode* value) {
            next = value;
        }


};