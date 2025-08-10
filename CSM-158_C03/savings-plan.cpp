#include <iostream>
#include <cmath>
using namespace std;

class SavingsPlan {
private:
    double periodicDeposit;  // R
    int m;                   // deposits per year
    double interestRate;     // r
    int years;               // t

public:
    SavingsPlan() : periodicDeposit(0), m(12), interestRate(0.0), years(0) {}
    SavingsPlan(double R, int mVal, double rate, int t) 
        : periodicDeposit(R), m(mVal), interestRate(rate), years(t) {}

    // Setters
    void setPeriodicDeposit(double R) { periodicDeposit = R; }
    void setM(int mVal) { m = mVal; }
    void setInterestRate(double rate) { interestRate = rate; }
    void setYears(int t) { years = t; }

    // Getters
    double getPeriodicDeposit() const { return periodicDeposit; }
    int getM() const { return m; }
    double getInterestRate() const { return interestRate; }
    int getYears() const { return years; }

    double calculateTotalAccumulated() const {
        double factor = pow(1 + interestRate / m, m * years) - 1;
        return periodicDeposit * (factor / (interestRate / m));
    }

    double calculateRequiredDeposit(double targetAmount) const {
        double factor = pow(1 + interestRate / m, m * years) - 1;
        return targetAmount * (interestRate / m) / factor;
    }
};

int main() {
    SavingsPlan plan;

    double R, rate;
    int mVal, t;

    cout << "Enter periodic deposit amount: ";
    cin >> R;
    cout << "Enter deposits per year: ";
    cin >> mVal;
    cout << "Enter annual interest rate (in %): ";
    cin >> rate;
    cout << "Enter number of years: ";
    cin >> t;

    plan.setPeriodicDeposit(R);
    plan.setM(mVal);
    plan.setInterestRate(rate / 100.0);
    plan.setYears(t);

    cout << "\nPeriodic Deposit: $" << plan.getPeriodicDeposit() << endl;
    cout << "Deposits per Year: " << plan.getM() << endl;
    cout << "Interest Rate: " << plan.getInterestRate() * 100 << "%" << endl;
    cout << "Years: " << plan.getYears() << endl;
    cout << "Total Accumulated: $" << plan.calculateTotalAccumulated() << endl;

    double targetAmount;
    
    cout << "\nEnter target amount to calculate required deposit: ";
    cin >> targetAmount;

    double requiredDeposit = plan.calculateRequiredDeposit(targetAmount);
    
    cout << "Required periodic deposit to reach $" << targetAmount 
         << " in " << plan.getYears() << " years: $" << requiredDeposit << endl;

    return 0;
}
