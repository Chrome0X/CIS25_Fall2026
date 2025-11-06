#include <iostream>
#include <string>
#include "funcs.h"
using namespace std;

class Item{
    public:
    string name;
    int quantity;
};

void displayAll(Item inventory[], int size){
    cout << "==Inventory List==";
        for (int j = 0; j < size; j++) {
            cout << "Item #" << j + 1 << " " << inventory[j].name << " | Quantity: " << inventory[j].quantity << endl;
        }
}

void itemSearch(Item inventory[], int size, string searchName) {
    bool found = false;
    for (int i = 0; i < size; i++) {
        if (inventory[i].name == searchName) {
            cout << "Item found: " << inventory[i].name << " | Quantity: " << inventory[i].quantity << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Item not found in inventory." << endl;
    }
}