#pragma once
#include "Currency.hpp"

class BSTNode {
    private:
        Currency* data;
        BSTNode* left;
        BSTNode* right;

    public:
        BSTNode(Currency* data){this->data = data; this->right = nullptr; this->left = nullptr;}
        ~BSTNode(){}

        Currency* getData() {return data;}
        BSTNode* getLeft() {return left;}
        BSTNode* getRight() {return right;}
        void setRight(BSTNode* location) {this->right = location;}
        void setLeft(BSTNode* location) {this->left = location;} 
        void setData(Currency* location) {this->data = location;}
};