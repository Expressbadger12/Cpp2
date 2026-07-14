// sctructs.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

struct Student {
	int id;
	string name;
	double gpa;
};

int main()
{
	Student student1;
	student1.id = 001;
	student1.name = "Micheal";
	student1.gpa = 3.78;
	cout << "Student information: " << endl;
	cout << "ID: " << student1.id << endl;
	cout << "Name: " << student1.name << endl;
	cout << "GPA: " << student1.gpa << endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
