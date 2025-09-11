#include <iostream> 
using namespace std; 
int main() { 
    int selection;
    double price;
    char choice;
    double menuPrices[] = {6.99, 3.99, 4.99, 5.99, 8.99, 2.99};
    cout << "1. Turkey Burger $6.99\n2. Fries S: $3.99 M: 4.99 L: $5.99\n3. Deluxe Turkey Burger $8.99\n4. Drink $2.99\n5. Combo Meal\n";
    cout << "What would you like? ";
    cin >> selection;
    if (selection == 1) {
        price = menuPrices[0];
        cout << "Your total is " << price << ", please see cashier to pay.";
    }
    else if (selection == 2) {
        cout << "What size fry would you like? ";
        cin >> choice;
        if (choice == 'S')
            price = menuPrices[1];
        else if (choice == 'M')
            price = menuPrices[2];
        else if (choice == 'L')
            price = menuPrices[3];
        else cout << "Sorry, that is an invalid choice";
        cout << "Your total is " << price << ", please see cashier to pay.";
    }
    else if (selection == 3) {
        price = menuPrices[4];
        cout << "Your total is " << price << ", please see cashier to pay.";
    }
    else if (selection == 4) {
        price = menuPrices[5];
        cout << "Your total is " << price << ", please see cashier to pay.";
    }
    else if (selection == 5) {
        price = menuPrices[0] + menuPrices[5];
        cout << "The combo comes with Turkey Burger, a Drink, and a choice of Fries\n What size fry would you like? ";
        cin >> choice;
        if (choice == 'S')
            price += menuPrices[1];
        else if (choice == 'M')
            price += menuPrices[2];
        else if (choice == 'L')
            price += menuPrices[3];
        else cout << "Sorry, that is an invalid choice";
        cout << "Your total is " << (price - 1.50) << ", please see cashier to pay.";
    }
    else cout << "Sorry, that is not a valid option.";
}