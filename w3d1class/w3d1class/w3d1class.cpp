// w3d1class.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <exception>

using namespace std;
// Function to divide two numbers
//double divide(int a, int b) {
//	if (b == 0) {
//		throw "Error: Cannot divide by zero.";
//	}
//	return a / b; 
//}

void checkGrade(int grade) 
{
	if (grade < 0) {
		throw "ErrorL Grade cannot be negative!";
	}
	if (grade > 100) {
		throw "Error: Grade cannot be greater thab 1ii!";
	}
	cout << "Valid grade found: " << endl;
}


int main()
{

	int grade;
	cout << "Please enter a grade: ";
	cin >> grade;
	try {
		checkGrade(grade);
	}
	catch (const char* errorMessage) {
		cout << errorMessage << endl;
	}


	//int num1, num2;
	//cout << "Please enter first number: ";
	//cin >> num1;
	//cout << endl << "Please enter second number: ";
	//cin >> num2;

	//try {
	//	double result = divide(num1, num2);

	//	cout << endl << "The result is: " << result << endl;
	//}
	//catch (const char* errorMessage) {
	//	cout << errorMessage << endl;
	//}

}
