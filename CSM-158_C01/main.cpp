#include <iostream>

int main() {
    int yearsWorked;
    double baseSalary, totalSales, commission = 0.0;
    double yearBonus, salesBonus, totalPay = 0.0;

    std::cout << "Enter base salary: $";
    std::cin >> baseSalary;

    std::cout << "Enter number of years worked: ";
    std::cin >> yearsWorked;

    std::cout << "Enter total monthly sales: $";
    std::cin >> totalSales;

    if (yearsWorked <= 5) {
        yearBonus = yearsWorked * 10;
    } else {
        yearBonus = yearsWorked * 20;
    }

    if (totalSales >= 5000 && totalSales < 10000) {
        salesBonus = totalSales * 0.03;
    } else if (totalSales >= 10000) {
        salesBonus = totalSales * 0.06;
    }

    totalPay = baseSalary + yearBonus + salesBonus;

    std::cout << "Base Salary    : $" << baseSalary << std::endl;
    std::cout << "Year Bonus     : $" << yearBonus << std::endl;
    std::cout << "Sales Bonus    : $" << salesBonus << std::endl;
    std::cout << "Total Paycheck : $" << totalPay << std::endl;

    return 0;
}
