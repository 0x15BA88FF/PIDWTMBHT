#include <iostream>
#include <string>

using namespace std;

class BankAccount {
private:
    string name;
    int accountNumber;
    string accountType; // checking/saving
    double balance;
    double interestRate; // decimal
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
            cout << "Insufficient funds.\n";
        }
    }

    void applyInterest() {
        balance += balance * interestRate;
    }

    // Getters
    string getName() const { return name; }
    int getAccountNumber() const { return accountNumber; }
    string getAccountType() const { return accountType; }
    double getBalance() const { return balance; }
    double getInterestRate() const { return interestRate; }
};

// Initialize static member
int BankAccount::nextAccountNumber = 1000;

int main() {
    BankAccount accounts[10];

    accounts[0].setAccountDetails("Pasca", "Saving", 5000, 0.02);
    accounts[1].setAccountDetails("0x1BA88FF", "Checking", 2000, 0.01);

    accounts[0].deposit(1000);
    accounts[1].withdraw(500);
    accounts[0].applyInterest();

    // First account
    cout << "Account Number: " << accounts[0].getAccountNumber() << endl;
    cout << "Name: " << accounts[0].getName() << endl;
    cout << "Type: " << accounts[0].getAccountType() << endl;
    cout << "Balance: $" << accounts[0].getBalance() << endl;
    cout << "Interest Rate: " << accounts[0].getInterestRate() * 100 << "%" << endl;

    cout << endl;

    // Second account
    cout << "Account Number: " << accounts[1].getAccountNumber() << endl;
    cout << "Name: " << accounts[1].getName() << endl;
    cout << "Type: " << accounts[1].getAccountType() << endl;
    cout << "Balance: $" << accounts[1].getBalance() << endl;
    cout << "Interest Rate: " << accounts[1].getInterestRate() * 100 << "%" << endl;

    return 0;
}
