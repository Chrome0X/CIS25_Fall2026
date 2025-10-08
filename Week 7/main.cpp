#include <iostream>
#include <string>
using namespace std;

int searchID;
int index;

struct Item { 
    string name;
    int id;
};

int BinarySearch(Item* inventory, int targetID) {

    int left = 0;
    int right = 99;

    while (left <= right) {
        int mid = (left + right)/2;
        if (inventory[mid].id == targetID)
            return mid;
        else if (inventory[mid].id < targetID)
            left = mid + 1;
        else 
            right = mid - 1;
    }
    return -1;
}

int main(){

Item* inventory = new Item[100];

for (int i = 0; i < 100; ++i){
    inventory[i].name = "Item #" + to_string(i);
    inventory[i].id = i;
}

cout << "Please enter a search ID from 0-99: ";

cin >> searchID;

index = BinarySearch(inventory, searchID);

if (index != -1){
    cout << "The item that matches the ID you entered is " << inventory[index].id;
}
else{
    cout << "Could not find item under " << searchID;
}

delete[] inventory;

}