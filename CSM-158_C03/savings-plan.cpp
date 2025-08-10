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
    SavingsPlan plan(500, 12, 0.048, 25);

    cout << "Periodic Deposit: $" << plan.getPeriodicDeposit() << endl;
    cout << "Deposits per Year: " << plan.getM() << endl;
    cout << "Interest Rate: " << plan.getInterestRate() * 100 << "%" << endl;
    cout << "Years: " << plan.getYears() << endl;
    cout << "Total Accumulated: $" << plan.calculateTotalAccumulated() << endl;

    SavingsPlan goalPlan;
    goalPlan.setM(12);
    goalPlan.setInterestRate(0.05);
    goalPlan.setYears(30);

    double requiredDeposit = goalPlan.calculateRequiredDeposit(1000000);

    cout << "\nRequired monthly deposit to reach $1,000,000 in 30 years at 5%: $"
         << requiredDeposit << endl;

    return 0;
}
