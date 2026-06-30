// newanddelete.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

//struct Employee {
//	int id;
//	string name;
//	int salary;
//};

int* createNumber() {
	int* value = new int(100);
	return value;
}

int main()
{
	//Employee* employee1 = new Employee;
	//employee1->id = 100;
	//employee1->name = "Mike";
	//employee1->salary = 50000;

	//cout << employee1->id << endl;
	//cout << employee1->name << endl;

	//delete employee1
//--------------------------------------------
	//int size;
	//cout << "How many grades? ";
	//cin >> size;
	//int* grades = new int[size];
	//for (int i = 0; i < size; i++) {
	//	cout << "Enter grade: " << i + 1 << ": ";
	//	cin >> grades[i];
	//}
	//cout << endl;
	//cout << "Grades: ";
	//for (int i = 0; i < size; i++) {
	//	cout << grades[i] << " ";
	//}

	//delete[] grades;
//--------------------------------------------------
	
	int* number = createNumber();
	cout << *number << endl;
	delete number;



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
