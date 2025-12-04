#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class BankAccount{
    private:
        double balance;
        string transactionFile;
    
    void logTransaction(string type, double amount){
            ofstream file(transactionFile, ios::app);
            if (file.is_open()){
                file << type << ": $" << amount << endl;
                file.close();
            }
        }
    
    public:
        BankAccount(double initialBalance = 0.0, string filename = "transactions.txt"){
            balance = initialBalance;
            transactionFile = filename;
            ofstream file(transactionFile, ios::trunc);
            file << "Transactions" << endl;
            file.close();
        }
    
    void deposit(double amount){
        if (amount > 0){
            balance += amount;
            logTransaction("Deposit", amount);
            cout << "Deposited $" << amount << endl;
        }
        else {
            cout << "Invalid deposit amount." << endl;
        }
    }
    
    void makePurchase(string description, double cost){
        if (cost <= balance){
            balance -= cost;
            logTransaction(description + " purchase", cost);
            cout << description << ": -$" << cost << endl;
        }
        else {
            cout << "Insufficient funds for this purchase." << endl;
        }
    }
    
    void displayBalance(){
        cout << "Current Balance: $" << balance << endl; 
    }
};

int main() {
    BankAccount myAccount;

    myAccount.deposit(1000.00);
    myAccount.makePurchase("Hot Chocolate", 4.50);
    myAccount.makePurchase("PG RX-78-2 Gundam Model Kit", 298.69);
    myAccount.displayBalance();

    return 0;
}
