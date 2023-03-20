
/* Lab #5
Edision Trinh
Hoang Khoi Do
Main file to demonstrate the HashTable and User Interface
*/
#include <iostream>
#include "HashTable.hpp"
#include "Node.hpp"
#include "Krone.hpp"

int main()
{
    HashTable table;

    Node node1(new Krone(57.12));
    Node node2(new Krone(23.44));
    Node node3(new Krone(87.43));
    Node node4(new Krone(68.99));
    Node node5(new Krone(111.22));
    Node node6(new Krone(44.55));
    Node node7(new Krone(77.77));
    Node node8(new Krone(18.36));
    Node node9(new Krone(543.21));
    Node node10(new Krone(20.21));
    Node node11(new Krone(345.67));
    Node node12(new Krone(36.18));
    Node node13(new Krone(48.48));
    Node node14(new Krone(101.00));
    Node node15(new Krone(11.00));
    Node node16(new Krone(21.00));
    Node node17(new Krone(51.00));
    Node node18(new Krone(1.00));
    Node node19(new Krone(251.00));
    Node node20(new Krone(151.00));

    table.hashInsert(node1);
    table.hashInsert(node2);
    table.hashInsert(node3);
    table.hashInsert(node4);
    table.hashInsert(node5);
    table.hashInsert(node6);
    table.hashInsert(node7);
    table.hashInsert(node8);
    table.hashInsert(node9);
    table.hashInsert(node10);
    table.hashInsert(node11);
    table.hashInsert(node12);
    table.hashInsert(node13);
    table.hashInsert(node14);
    table.hashInsert(node15);
    table.hashInsert(node16);
    table.hashInsert(node17);
    table.hashInsert(node18);
    table.hashInsert(node19);
    table.hashInsert(node20);

    table.miscInfo();

    bool searchLoop = true;
    while (searchLoop)
    {
        try
        {
            double searchValue;
            cout << "Enter a value to search for: ";
            cin >> searchValue;

            table.search(new Krone(searchValue));

            char searchAgain;
            cout << "Would you like to search again? (Y/N): ";
            cin >> searchAgain;
            if (searchAgain == 'N' || searchAgain == 'n')
            {
                searchLoop = false;
                cout << "Goodbye!";
            }
        }
        catch(string e){
            cout << e << endl;
        }
    }
}