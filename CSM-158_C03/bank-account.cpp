#include <iostream>
#include <string>

using namespace std;

class BankAccount {
private:
    string name;
    int accountNumber;
    string accountType;
    double balance;
    double interestRate;
    static int nextAccountNumber;

public:
    BankAccount() {
        accountNumber = ++nextAccountNumber;
        balance = 0.0;
        interestRate = 0.0;
    }

    BankAccount(string accName, string type, double initialBalance, double rate) {
        accountNumber = ++nextAccountNumber;
        name = accName;
        accountType = type;
        balance = initialBalance;
        interestRate = rate;
    }

    void setAccountDetails(string accName, string type, double initialBalance, double rate) {
        name = accName;
        accountType = type;
        balance = initialBalance;
        interestRate = rate;
    }

    void deposit(double amount) {
        balance += amount;
    }

    void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
        } else {
            cout << "Insufficient funds in account " << accountNumber << endl;
        }
    }

    void applyInterest() {
        balance += balance * interestRate;
    }

    void printAccount() const {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Name: " << name << endl;
        cout << "Type: " << accountType << endl;
        cout << "Balance: $" << balance << endl;
        cout << "Interest Rate: " << interestRate * 100 << "%" << endl;
        cout << "-----------------------" << endl;
    }
};

int BankAccount::nextAccountNumber = 1000;

int main() {
    BankAccount accounts[10] = {
        {"Pasca", "Saving", 5000, 0.02},
        {"kevin", "Checking", 2000, 0.01},
        {"Benjamin", "Saving", 3000, 0.03},
        {"Ama", "Checking", 1500, 0.015},
        {"Saira", "Saving", 8000, 0.025},
        {"Eve", "Checking", 1200, 0.01},
        {"Ado", "Saving", 7000, 0.02},
        {"Yoasobi", "Checking", 2500, 0.015},
        {"kenshi Yonezu", "Saving", 6000, 0.02},
        {"ACAne", "Checking", 4000, 0.01}
    };
    
    accounts[0].deposit(1000);
    accounts[1].withdraw(500);
    accounts[2].applyInterest();
    accounts[3].deposit(200);
    accounts[4].withdraw(1000);
    accounts[5].applyInterest();
    accounts[6].deposit(3000);
    accounts[7].withdraw(2000);
    accounts[8].applyInterest();
    accounts[9].deposit(700);

    // Print all accounts
    for (int i = 0; i < 10; i++) {
        accounts[i].printAccount();
    }

    return 0;
}
