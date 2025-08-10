#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

class SavingsPlan {
private:
    double periodicDeposit;  // R
    int m;                   // deposits per year
    double interestRate;     // r
    int years;               // t

public:
    // Constructors
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

    // Calculate total accumulated amount
    double calculateTotalAccumulated() const {
        double factor = pow(1 + interestRate / m, m * years) - 1;
        return periodicDeposit * (factor / (interestRate / m));
    }

    // Calculate required periodic deposit for target amount S
    double calculateRequiredDeposit(double targetAmount) const {
        double factor = pow(1 + interestRate / m, m * years) - 1;
        return targetAmount * (interestRate / m) / factor;
    }

    // Display info
    void displayPlanDetails() const {
        cout << fixed << setprecision(2);
        cout << "Periodic Deposit: $" << periodicDeposit << endl;
        cout << "Deposits per Year: " << m << endl;
        cout << "Interest Rate: " << (interestRate * 100) << "%" << endl;
        cout << "Years: " << years << endl;
        cout << "Total Accumulated: $" << calculateTotalAccumulated() << endl;
    }
};

// Test program
int main() {
    // Example: deposit $500 monthly, 4.8% annual interest, 25 years
    SavingsPlan plan(500, 12, 0.048, 25);
    plan.displayPlanDetails();

    // Example: target $1,000,000 in 30 years, 12 deposits/year, 5% interest
    SavingsPlan goalPlan;
    goalPlan.setM(12);
    goalPlan.setInterestRate(0.05);
    goalPlan.setYears(30);
    double requiredDeposit = goalPlan.calculateRequiredDeposit(1000000);
    cout << "\nRequired monthly deposit to reach $1,000,000 in 30 years at 5%: $"
         << fixed << setprecision(2) << requiredDeposit << endl;

    return 0;
}
