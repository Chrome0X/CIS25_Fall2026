#include <iostream>
#include "Stuff.h"
using namespace std;
int main() { 
    int option; 
    int selection;
	do { 
    	showMenu(); 
    	cin >> option; 
        if (option == 1){
            cout << "Please chose a number: ";
            cin >> selection;
            cout << "Result: " << addSelf(selection) << endl;
        }
        else if (option == 2){
            cout << "Please chose a number: ";
            cin >> selection;
            cout << "Result: " << subtSelf(selection) << endl;
        }
        else if (option == 3){
            cout << "Please chose a number: ";
            cin >> selection;
            cout << "Result: " << mulSelf(selection) << endl;
        }
        else if (option == 4){
            cout << "Please chose a number: ";
            cin >> selection;
            cout << "Result: " << divSelf(selection) << endl;
        }
    } while (option != 5);
}