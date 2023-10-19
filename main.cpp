#include <iostream>
#include <string>
#include <list>
#include "item.h"
using namespace std;



int main() {
    list<Item> itemList; // create a list to store items

    char option;
    do {
        cout << "Choose an option:\n";
        cout << "1. Add new item\n";
        cout << "2. Search by item\n";
        cout << "3. Search by owner CPF\n";
        cout << "S. Exit\n";
        cin >> option;

        if (option == '1') {
            Item newItem;
            cout << "Enter item name: ";
            cin >> newItem.name;
            cout << "Enter owner name: ";
            cin >> newItem.ownerName;
            cout << "Enter owner CPF: ";
            cin >> newItem.ownerCPF;
            cout << "Enter quantity: ";
            cin >> newItem.quantity;

            itemList.push_back(newItem); // add new item to the end of the list
        } else if (option == '2') {
            string itemName;
            cout << "Enter item name to search: ";
            cin >> itemName;

            bool found = false;
            for (auto it = itemList.begin(); it != itemList.end(); it++) {
                if (it->name == itemName) {
                    cout << "Item found!\n";
                    cout << "Name: " << it->name << endl;
                    cout << "Owner name: " << it->ownerName << endl;
                    cout << "Owner CPF: " << it->ownerCPF << endl;
                    cout << "Quantity: " << it->quantity << endl;
                    found = true;
                    break;
                }
            }

            if (!found) {
                cout << "Item not found.\n";
            }
        } else if (option == '3') {
            string ownerCPF;
            cout << "Enter owner CPF to search: ";
            cin >> ownerCPF;

            bool found = false;
            for (auto it = itemList.begin(); it != itemList.end(); it++) {
                if (it->ownerCPF == ownerCPF) {
                    cout << "Item found!\n";
                    cout << "Name: " << it->name << endl;
                    cout << "Owner name: " << it->ownerName << endl;
                    cout << "Owner CPF: " << it->ownerCPF << endl;
                    cout << "Quantity: " << it->quantity << endl;
                    found = true;
                    break;
                }
            }

            if (!found) {
                cout << "Item not found.\n";
            }
        }
    } while (option != 'S' || option != 's');
    
    return 0;
}
