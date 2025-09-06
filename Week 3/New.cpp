#include <iostream> 
using namespace std; 
int main() {
    string itemName;
    int quantity;
    double costPer;
    double price;
    cout << "Hello! What would you like?";
    cin >> itemName;
    cout << "How many would you like?";
    cin >> quantity;
    cout << "How much is it?";
    cin >> costPer;
    price = quantity*costPer;

    cout << "Okay, your order total is" << price << "for" << quantity << "of" << itemName << ". Thank you!" << endl;
}