// w4d2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	ofstream outputFile("students.txt");
	string name;
	int grade;
	for (int i = 1; i <= 3; i++) {
		cout << "Enter student name: ";
		cin >> name;
		cout << endl << "Enter grade: ";
		cin >> grade;
		outputFile << name << " " << grade << endl;
	}
	outputFile.close();
	cout << "Student records saved." << endl;
}

