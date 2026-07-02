// 7_2pract.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;

struct Student {
    int id;
    string name;
    double gpa;
};

int main()
{
    int numberOfStudents;
    cout << "Please enter number of students: ";
    cin >> numberOfStudents;

    Student* students = new Student[numberOfStudents];
    for (int i = 0; i < numberOfStudents; i++) {
        cout << "\nStudent " << i + 1 << endl;
        cout << "ID: ";
        cin >> students[i].id;
        cout << "Name: ";
        cin >> students[i].name;
        cout << "GPA: ";
        cin >> students[i].gpa;
    }

    cout << endl;
    cout << "====================" << endl;
    cout << "Student List: "; 
    for (int i = 0; i < numberOfStudents; i++) {
        cout << students[i].id << " " << students[i].name << " " << students[i].gpa << endl;
    }

    delete students;
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
