// allocatedeallocate.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;


class creature {
private:

public:
    string name;
    double age;
    int numEyes;
    bool fur;

    creature(string* n, double* a, int* e, bool* f) {
        name = *n;
        age = *a;
        numEyes = *e;
        fur = *f;
    }
};



int main()
{
    int howm;

    cout << "How many creatures would you like to make? ";
    cin >> howm;



    for (int i = 0; i < howm; i++) {
        string* name = new string;
        double* age = new double;
        int* numEyes = new int;
        bool* fur = new bool;

        cout << "Name: ";
        cin >> *name;
        cout << endl;

        cout << "Age: ";
        cin >> *age;
        cout << endl;

        cout << "Number of Eyes: ";
        cin >> *numEyes;
        cout << endl;

        cout << "Fur? (true or false): ";
        cin >> *fur;
        cout << endl;

        creature(n, a, e, f) {
            name = *n;
            age = *a;
            numEyes = *e;
            fur = *f;
        }

        delete name;
        delete age;
        delete numEyes;
        delete fur;
    }
}

/*
Make a great UX!
Over comment your code.
Create a program with allocation and deallocation of memory using pointers of 4 primitive data types of your choice on the heap with the new and delete keywords.
Create 5 objects with the new keyword for your example too.
Explain to the user in cout statements allocation and deallocation of memory with examples.
Your program should teach the user about new and delete and the allocation and deallocation of memory.
*/
