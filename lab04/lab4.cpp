
/* Lab #4
Edision Trinh
Hoang Khoi Do
Main file to demonstrate the Binary Search Tree with its methods and User Interface.
*/
#include <iostream>
#include "SinglyLinkedList.hpp"
#include "BST.hpp"
#include "BSTNode.hpp"
#include <fstream>

using namespace std;

int main()
{
    int size = 20;
    ofstream myFile;
    int choice;
    double value;
    BST tree;
    Currency *currencies[] = {new Krone(57.12), new Krone(23.44), new Krone(87.43), new Krone(68.99), new Krone(111.22),
                              new Krone(44.55), new Krone(77.77), new Krone(18.36), new Krone(543.21), new Krone(20.21),
                              new Krone(345.67), new Krone(36.18), new Krone(48.48), new Krone(101.00), new Krone(11.00),
                              new Krone(21.00), new Krone(51.00), new Krone(1.00), new Krone(251.00), new Krone(151.00)};

    for (int i = 0; i < size; i++)
    {
        tree.insert(currencies[i]);
    }
    myFile.open("Outputfile.txt");
    while (true)
    {
        try
        {

            cout << "1.Insert Element " << endl;
            cout << "2.Delete Element " << endl;
            cout << "3.Search" << endl;
            cout << "4.Display" << endl;
            cout << "5.Delete tree" << endl;
            cout << "6.Quit" << endl;
            cout << "Please enter your choice" << endl;
            cin >> choice;
            switch (choice)
            {
            case 1:

                cout << "Inserting..." << endl;
                cout << "Enter value: " << endl;
                cin >> value;
                if (value < 0)
                {
                    throw value;
                }
                else if (tree.search(tree.getRoot(), new Krone(value)))
                {
                    throw value;
                }
                else
                {
                    tree.insert(new Krone(value));
                }
                break;
            case 2:
                cout << "Option 2" << endl;
                cout << "Please enter what to delete" << endl;
                cin >> value;
                tree.remove(new Krone(value));
                if (value < 0)
                {
                    throw value;
                }
                break;
            case 3:
                cout << "Searching..." << endl;
                cout << "Please enter the value you want to search" << endl;
                cin >> value;
                if (tree.search(tree.getRoot(), new Krone(value)))
                {
                    cout << endl;
                    cout << "Node Found\n"
                         << endl;
                }
                else if (tree.search(tree.getRoot(), new Krone(value)))
                {
                    throw value;
                }
                else
                {
                    cout << endl;
                    cout << "Node not found\n"
                         << endl;
                }
                break;
            case 4:
                cout << "Displaying..." << endl;
                cout << endl;
                cout << "preOrder:" << endl;
                tree.preOrder(tree.getRoot());
                cout << endl;
                cout << "InOrder:" << endl;
                tree.inOrder(tree.getRoot());
                cout << endl;
                cout << "postOrder: " << endl;
                tree.postOrder(tree.getRoot());
                cout << endl;
                cout << "BreadthFirst: " << endl;
                cout << tree.breadthFirst() << endl;
                myFile.open("Outputfile.txt");
                if (myFile.is_open())
                {
                    myFile << "In-Order : " << tree.store_inOrder(tree.getRoot()) << endl
                           << endl;
                    myFile << "Post-Order : " << tree.store_postOrder(tree.getRoot()) << endl
                           << endl;
                    myFile << "Pre-Order : " << tree.store_preOrder(tree.getRoot()) << endl
                           << endl;
                    myFile << "Breadth-First : " << tree.breadthFirst() << endl;
                    myFile.close();
                }
                break;
            case 5:
                cout << "Deleting the tree" << endl;
                tree.emptyTree(tree.getRoot());
                if (tree.isEmpty() == true)
                {
                    cout << "Empty tree" << endl;
                }
                else
                {
                    cout << "Tree is not empty" << endl;
                }
                break;
            case 6:
                cout << "Displaying..." << endl;
                cout << endl;
                cout << "preOrder:" << endl;
                tree.preOrder(tree.getRoot());
                cout << endl;
                cout << "InOrder:" << endl;
                tree.inOrder(tree.getRoot());
                cout << endl;
                cout << "postOrder: " << endl;
                tree.postOrder(tree.getRoot());
                cout << endl;
                cout << "BreadthFirst: " << endl;
                cout << tree.breadthFirst() << endl;
                myFile.open("Outputfile.txt");
                if (myFile.is_open())
                {
                    myFile << "In-Order : " << tree.store_inOrder(tree.getRoot()) << endl
                           << endl;
                    myFile << "Post-Order : " << tree.store_postOrder(tree.getRoot()) << endl
                           << endl;
                    myFile << "Pre-Order : " << tree.store_preOrder(tree.getRoot()) << endl
                           << endl;
                    myFile << "Breadth-First : " << tree.breadthFirst() << endl
                           << endl;
                    myFile.close();
                    tree.emptyTree(tree.getRoot());
                }
                return 0;
            default:
                cout << "Invalid choice, Enter 1-6" << endl;
                break;
            }
        }
        catch (double e)
        {
            cout << e << " is an invalid number" << endl;
            if (myFile.is_open())
            {
                myFile << e << " is an ivalid number" << endl;
                myFile.close();
            }
            else
            {
                cout << "File is not found" << endl;
            }
        }
    }
    return 0;
}
