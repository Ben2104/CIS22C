/* Lab #4
Edision Trinh
Hoang Khoi Do
Class for BST
*/
#pragma once
#include "BSTNode.hpp"
#include "Queue.hpp"
#include <iostream>
#include <string>
#include <queue>
class BST
{
private:
    BSTNode *root;
    int count = 0;

public:
    // Constructor Destructor
    BST()
    {
        root = nullptr;
    }
    ~BST() {}

    // Function:
    void insert(Currency *data);
    string breadthFirst();
    BSTNode *inOrder(BSTNode *node);
    BSTNode *preOrder(BSTNode *node);
    BSTNode *postOrder(BSTNode *node);
    BSTNode *search(BSTNode *root, Currency *data);
    void remove(Currency *key);
    void emptyTree(BSTNode *node);
    string store_postOrder(BSTNode *node);
    string store_inOrder(BSTNode *node);
    string store_preOrder(BSTNode *node);

    bool isEmpty();
    // Getter & Setter:
    BSTNode *getRoot() { return root; };
    void setRoot(BSTNode *location) { this->root = location; }
    void setCount(int val) { count = val; }
    int getCount() { return count; }
};
/*
bool BST::isEmpty()
    Pre: None
    Post: None
    Return True or False

    Check if the tree is empty then return true if it is empty else false
*/
bool BST::isEmpty()
{
    if (root == nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/*
void BST::insert(Currency *data)
    Pre: Currnecy Data
    Post: Inserts Data into tree
    Return: Void

    Does logical checks like if the key is greater than the nodes on the tree and if its greater than root it goes right and less than it goes left and it recursively keeps going
    until it finds a nullptr then it gets inserted there

    
*/
void BST::insert(Currency *data)
{

    BSTNode *node = new BSTNode(data);
    if (root == nullptr)
    {
        root = node;
    }
    else
    {
        BSTNode *curNode = root;
        while (curNode != nullptr)
        {
            if (curNode->getData()->isGreater(*data))
            {
                if (curNode->getLeft() == nullptr)
                {
                    curNode->setLeft(node);
                    curNode = nullptr;
                }
                else
                {
                    curNode = curNode->getLeft();
                }
            }
            else
            {
                if (curNode->getRight() == nullptr)
                {
                    curNode->setRight(node);
                    curNode = nullptr;
                }
                else
                {
                    curNode = curNode->getRight();
                }
            }
        }
        count++;
    }
}


/*
BSTNode *BST::search(BSTNode *node, Currency *key)

    Pre: BSTNode* Node, Currency* key
    Post: just used to compare
    Return: Return a BSTNode pointer

    Recursively searches for a specific key if it finds it then it will return the node and if it doesnt it just calls itself but to the left or right

*/
BSTNode *BST::search(BSTNode *node, Currency *key)
{

    if (node != nullptr)
    {
        if (key->getWhole() == node->getData()->getWhole() && key->getFraction() == node->getData()->getFraction())
        {
            return node;
        }
        else if (node->getData()->isGreater(*key))
        {
            return search(node->getLeft(), key);
        }
        else
        {
            return search(node->getRight(), key);
        }
    }

    return nullptr;
}

/*
BSTNode *BST::inOrder(BSTNode *node)
    Pre: BSTNode* Node
    Post: used to traverse tree
    Return: Node pointer

    Traverses through the tree by going left root than right
*/

BSTNode *BST::inOrder(BSTNode *node)
{
    BST count;
    if (node == nullptr)
        return nullptr;

    inOrder(node->getLeft());
    cout << node->getData()->getWhole() << "." << node->getData()->getFraction() << " ";
    inOrder(node->getRight());
    return nullptr;
}

/*
BSTNode *BST::preOrder(BSTNode *node)
    Pre: BSTNode* Node
    Post: used to traverse tree
    Return: Node pointer

    Traverses through root node first then left then right
*/

BSTNode *BST::preOrder(BSTNode *node)
{
    if (node == nullptr)
        return nullptr;
    cout << node->getData()->getWhole() << "." << node->getData()->getFraction() << " ";
    preOrder(node->getLeft());
    preOrder(node->getRight());
    return nullptr;
}

/*
BSTNode *BST::postOrder(BSTNode *node)
    Pre: BSTNode* Node
    Post: used to traverse tree
    Return: Node pointer

    Traverses through left first then right then root
*/

BSTNode *BST::postOrder(BSTNode *node)
{
    if (node == nullptr)
        return nullptr;
    postOrder(node->getLeft());
    postOrder(node->getRight());
    cout << node->getData()->getWhole() << "." << node->getData()->getFraction() << " ";
    return nullptr;
}


/*
string BST::breadthFirst()
    Pre: None
    Post: None
    Return: String

    Puts the first element if the tree is not empty into a queue then puts that nodes children into the queue then it gets popped
    and this cycle continues until queue is empty

*/
string BST::breadthFirst()
{
    string numbers = "";
    int count = 0;
    BSTNode *curNode = this->getRoot();
    if (curNode == nullptr)
    {
        return "Empty";
    }

    queue<Currency*> q;
    q.push(curNode->getData());
    count++;

    while (count > 0)
    {
        Currency *curData = q.front();
        numbers += to_string(curData->getWhole()) + "." + to_string(curData->getFraction());
        numbers += " ";
        if (curNode->getLeft() != nullptr)
        {
            q.push(curNode->getLeft()->getData());
            count++;
        }
        if (curNode->getRight() != nullptr)
        {
            q.push(curNode->getRight()->getData());
            count++;
        }
        q.pop();
        count--;
        if (count > 0)
        {
            curNode = search(this->getRoot(), q.front());
        }
    }
    return numbers;
}

/*
void BST::remove(Currency *key)
    Pre: Currency* key
    Post: used to compare 
    Return: None

    The arguement key is compared with every node it traverses through and if there is a match then it would get deleted but not before fixing the pointers of other nodes.
    If there is a leaf then then parNode pointes just get set to nullptr effectively removing leafs
    If its one internal with one children or 2 childre
*/

void BST::remove(Currency *key)
{
    BSTNode *parNode = nullptr;
    BSTNode *curNode = this->getRoot();

    while (curNode != nullptr) // Search for Node
    {
        if (curNode->getData()->getWhole() == key->getWhole() && curNode->getData()->getFraction() == key->getFraction()) // Node Found
        {
            if (curNode->getLeft() == nullptr && curNode->getRight() == nullptr) // Remove leaf
            {
                if (parNode == nullptr)
                {
                    this->setRoot(nullptr);
                }
                else if (parNode->getLeft() == curNode)
                {
                    parNode->setLeft(curNode->getLeft());
                }
                else
                {
                    parNode->setRight(curNode->getRight());
                }
            }
            else if (curNode->getRight() == nullptr) // Remove node with left child
            {                                        // right child empty
                if (parNode == nullptr)
                {
                    this->setRoot(curNode->getLeft());
                }
                else if (parNode->getLeft() == curNode)
                {
                    parNode->setLeft(curNode->getLeft());
                }
                else
                {
                    parNode->setRight(curNode->getLeft());
                }
            }
            else if (curNode->getLeft() == nullptr) // Remove node with right child
            {                                       // left child empty
                if (parNode == nullptr)
                {
                    this->setRoot(curNode->getRight());
                }
                else if (parNode->getLeft() == curNode)
                {
                    parNode->setLeft(curNode->getRight());
                }
                else
                {
                    parNode->setRight(curNode->getRight());
                }
            }
            else // remove the node with 2 children
            {
                BSTNode *sucNode = curNode->getRight();
                while (sucNode->getLeft() != nullptr)
                {
                    sucNode = sucNode->getLeft();
                }
                Currency *sucData = sucNode->getData();
                remove(sucNode->getData());
                curNode->setData(sucData);
            }
            return;
        }
        else if (key->isGreater(*curNode->getData())) // search  right
        {
            parNode = curNode;
            curNode = curNode->getRight();
        }
        else
        {
            parNode = curNode;
            curNode = curNode->getLeft(); // search left
        }
    }
    return;
}


/*
void BST::emptyTree(BSTNode *p)
    Pre: BSTNode* p
    Post: used to traverse
    Return: None

    Traverse through the tree and deletes the nodes recursively
*/
void BST::emptyTree(BSTNode *p)
{
    if (p == nullptr)
    {
        return;
    }
    emptyTree(p->getLeft());
    emptyTree(p->getRight());
    p->setLeft(nullptr);
    p->setRight(nullptr);
    if (p == this->root && this->root->getLeft() == nullptr && this->root->getRight() == nullptr)
    {
        this->setRoot(nullptr);
    }
    delete p;
}

/*
string BST::store_inOrder(BSTNode *node)
    Pre: BSTNode* Node
    Post: used to traverse tree
    Return: string

    Traverses through left first then root then right and then store string
*/
string BST::store_inOrder(BSTNode *node)
{
    static string numbers = "";
    if (node == nullptr)
        return "Empty";

    store_inOrder(node->getLeft());
    numbers += to_string(node->getData()->getWhole()) + "." + to_string(node->getData()->getFraction());
    numbers += " ";
    store_inOrder(node->getRight());
    return numbers;
}

/*
string BST:::store_preOrder(BSTNode *node)
    Pre: BSTNode* Node
    Post: used to traverse tree
    Return: string

    Traverses through left first then right then root and then store string
*/

string BST::store_preOrder(BSTNode *node)
{
    static string numbers = "";
    if (node == nullptr)
        return "Empty";
    numbers += to_string(node->getData()->getWhole()) + "." + to_string(node->getData()->getFraction());
    numbers += " ";
    store_preOrder(node->getLeft());
    store_preOrder(node->getRight());
    return numbers;
}
/*
string BST::store_postOrder(BSTNode *node)
    Pre: BSTNode* Node
    Post: used to traverse tree
    Return: string

    Traverses through left first then right then root and then store string
*/
string BST::store_postOrder(BSTNode *node)
{
    static string numbers = "";
    if (node == nullptr)
        return "Empty";
    store_postOrder(node->getLeft());
    store_postOrder(node->getRight());
    numbers += to_string(node->getData()->getWhole()) + "." + to_string(node->getData()->getFraction());
    numbers += " ";
    return numbers;
}
