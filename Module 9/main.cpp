#include <iostream>
#include <string>
#include "funcs.h"
using namespace std;

class Item{
    public:
    string name;
    int quantity;
};

int main() {
    const int size = 5;
    Item inventory[size];
    string searchName;
    int selection;

    for (int i = 0; i < size; i++) {
        cout << "Please enter a name for your new item " << i + 1 << ": ";
        cin >> inventory[i].name;
        cout << "\n Please emter a quantity for " << inventory[i].name << ": ";
        cin >> inventory[i].quantity;
        cout << "\n Your item has been logged into the inventory" << endl;
    }

    cout << "Please make a selection: \n1. Display all items in inventory \n2. Search for one item by name";
    cin >> selection;
    if (selection == 1) {
        displayAll(inventory, size);
    }

    else if (selection == 2) {
        cin >> searchName;
        itemSearch(inventory, size, searchName);
    }

    else {
        cout << "Invalid selection";
    }
}