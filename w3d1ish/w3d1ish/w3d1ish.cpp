// w3d1ish.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
using namespace std;


int main()
{
	ifstream inputFile("data.txt");
	if (!inputFile) {
		cout << "Error opening file!" << endl;
		return 1;
	}
	string line;
	cout << "Content of the file: " << endl;
	//Read line by line
	while (getline(inputFile, line)) {
		cout << line << endl;
	}
	inputFile.close();

	
	
	
	ifstream input("numbers.txt");
	int number;
	int sum = 0;
	while (input >> number) {
		cout << "Read: " << number << endl;
		sum += number;
	}
	cout << "Sum = " << sum << endl;
	input.close();


	ofstream outputFile("data.txt");
	if (!outputFile) {
		cout << "Error creating file!" << endl;
		return 1;
	}
	outputFile << "Hello, welcome to our class" << endl;
	outputFile << "Today we will review file I/O" << endl;
	outputFile << "Thank you for attending the class today" << endl;
	outputFile.close();
}

