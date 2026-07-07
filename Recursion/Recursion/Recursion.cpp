// Recursion.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

void countdown(int n) {
	if (n == 0) {
		return;
	}
	cout << n << " ";
	countdown(n - 1);
}

int factorial(int n) {
	if (n == 0) {
		return 1;
	}
	return n * factorial(n - 1);

}

int sum(int n) {
	if (n == 1) {
		return 1;
	}
	return n + sum(n - 1);
}

int main()
{
//	countdown(10);
	int number;
	cout << "Please enter a poisitive integer: ";
	cin >> number;
	if (number < 0) {
		cout << "Factorial is not defined for negative numbers" << endl;
	}
	else {
		int result = factorial(number);
		cout << "Factorial of " << number << " is: " << result << endl;
	}


cout<<	sum(5);
}

