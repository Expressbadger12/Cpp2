// cpp2day1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
//parent class
class Employee {
public:
    void calculatePay() {
        cout << "Calculating employee pay..." << endl;

    }
    void test() {
        cout << "test" << endl;
    }
};

//child classes
class SalarieEmployee : public Employee {
public:
    void calculatePay() {
        cout << "Monthly salary: $4000" << endl;
    }
};

int main()
{
    Employee employee1;
    employee1.calculatePay();
    cout << endl;
    SalarieEmployee salary1;
    salary1.calculatePay();
    salary1.test();
}


