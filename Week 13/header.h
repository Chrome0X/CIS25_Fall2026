#include <iostream>
#include <string>
using namespace std;

class User {
    public:
        virtual void accessLevel() {
            cout << "Access level: User" << endl;
        }
};

class Employee : public User {
    public:
        void accessLevel () {
            cout << "Access level: Employee" << endl;
        }
};

class InventoryManager : public Employee {
    public:
        void accessLevel() {
            cout << "Access level: Inventory Manager" << endl;
        }
};