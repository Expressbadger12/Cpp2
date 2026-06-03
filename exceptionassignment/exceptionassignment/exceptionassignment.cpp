// exceptionassignment.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;
//silly little budget app

double getIncome() {
	try {
		double income;
		string input;
		cout << "Enter your monthly income :";
		cin >> input;
		cout << endl;

		income = stod(input); //stod turns it into double methinks

		if (income < 0) {
			throw runtime_error("Negatives are for expenses");
		}
		return income;
	}
	catch (invalid_argument) {
		cout << "Enter a number!" << endl;
	} 
	catch (runtime_error& e) {
		cout << e.what() << endl;
	}
	catch (out_of_range) {
		cout << "That number is too large!" << endl;
	}
}

double getExpenses() {
	try {
		double debt;
		string input;
		cout << "Enter your monthly expenses :";
		cin >> input;
		cout << endl;

		debt = stod(input);

		if (debt < 0) {
			throw runtime_error("Negative debt? Put that in income!");
		}
		return debt;
	}
	catch (invalid_argument) {
		cout << "Enter a number!" << endl;
	}
	catch (runtime_error& e) {
		cout << e.what() << endl;
	}
	catch (out_of_range) {
		cout << "That number is too large! if you've got debt like that. You're cooked" << endl;
	}
}

void calculateStatus(double income, double expense) {
	if (income - expense < 0) {
		cout << "You're cooked" << endl;
	}
	else if (income - expense > 0) {
		cout << "You'll be fine" << endl;
	}
	else {
		cout << "I don't know. You'll probably be okay." << endl;
	}
}

int main()
{
	double income = -1;

	double expenses = -1;

	string choice;

	while (true) {
		cout << "Press 1 to enter income" << endl;
		cout << "Press 2 to enter expenses" << endl;
		cout << "Press 3 to calculate status" << endl;
		cout << ">:";
		cin >> choice;

		if (choice == "1") {
			income = getIncome();
		}
		else if (choice == "2") {
			expenses = getExpenses();
		}
		else if (choice == "3") {
			
			if (income > 0 && expenses > 0) {
				calculateStatus(income, expenses);
			}
			else {
				cout << "Cannot calculate status before you enter your income and expenses" << endl;
			}
		}
		else {
			cout << "Invalid choice" << endl;
		}
	}
}

/*
Your program must have a clear functional purpose and be useful, it must not be just a demo of exceptions.
Display a description of the program and how to use it for the user when your app starts.
Write an app that demonstrates the try/catch exception handler blocks for a minimum of 4 different exceptions, not more than one try/catch block in each method.
Handle the exception and include sufficient output to indicate the exception and the condition that caused it.
Use more than one catch type.
Over comment your code!
Your app should have a good UX.
*/