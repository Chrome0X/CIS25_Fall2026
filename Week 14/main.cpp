#include <iostream>
using namespace std;

class Product {
    int id;
    string name;
    float price;

    public:
    Product(int pid, string pname, float pprice){
        id = pid;
        name = pname;
        price = pprice;
        cout << "Constructor called.\n";
    }

    ~Product(){
        cout << "Destructor called.\n";
    }

    void printDetails() {
        cout << "Product ID: " << id << ", Product Name: " << name << ", Product Price: $" << price << endl;
    }
};

int main() {
    Product p1(101, "Laptop", 799.99);
    p1.printDetails();

    return 0;
}