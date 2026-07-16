// wwhateverd2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

struct Employee {
	int employeeID;
	string name;
	double hourlyRate;
	int hoursWorked;
};

struct Car {
	string make;
	string model;
	int year;
	double price;
	bool sold;
};

void employeeexample() {
	Employee employee1;
	employee1.employeeID = 007;
	employee1.name = "James Bond";
	employee1.hourlyRate = 17.5;
	employee1.hoursWorked = 40;

	double weeklyPay = employee1.hourlyRate * employee1.hoursWorked;
	cout << "Employee Payroll: " << endl;
	cout << "Employee ID: " << employee1.employeeID << endl;
	cout << "Name: " << employee1.name << endl;
	cout << "Hourly Rate: $" << employee1.hourlyRate << endl;
	cout << "Hours worked: " << employee1.hoursWorked << endl;
	cout << "Weekly pay: " << weeklyPay << endl;
}

void carexample() {
	Car car1;
	car1.make = "Mazda";
	car1.model = "CX5";
	car1.price = 29987;
	car1.year = 2023;
	car1.sold = true;

	cout << "Car Information: " << endl;
	cout << "======================================" << endl;
	cout << "Make: " << car1.make << endl;
	cout << "Model: " << car1.model << endl;
	cout << "Year: " << car1.year << endl;
	cout << "Price: $" << car1.price << endl;
	if (car1.sold) {
		cout << "Status: sold out" << endl;
	}
	else {
		cout << "Status: available" << endl;
	}

	cout << endl;


	Car car2;
	car2.make = "Fyord";
	car2.model = "Extremebo Helium";
	car2.price = 39999;
	car2.year = 2129;
	car2.sold = false;

	cout << "Car Information: " << endl;
	cout << "======================================" << endl;
	cout << "Make: " << car2.make << endl;
	cout << "Model: " << car2.model << endl;
	cout << "Year: " << car2.year << endl;
	cout << "Price: $" << car2.price << endl;
	if (car2.sold) {
		cout << "Status: sold out" << endl;
	}
	else {
		cout << "Status: available" << endl;
	}
}


int main()
{
	carexample();
}
