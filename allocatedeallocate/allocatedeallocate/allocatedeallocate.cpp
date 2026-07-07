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


    creature() {
        name = "";
        age = 0;
        numEyes = 0;
        fur = false;
    }

    creature(string* n, double* a, int* e, bool* f) {
        name = *n;
        age = *a;
        numEyes = *e;
        fur = *f;
    }
};



int main()
{

    creature* creatures[5];

    for (int i = 0; i <= 4; i++) {
        creatures[i] = new creature();
    }

    for (int i = 0; i < 5; i++) {
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

        *creatures[i] = creature(name, age, numEyes, fur);

        delete name;
        delete age;
        delete numEyes;
        delete fur;
    }

    for (int i = 0; i < 5; i++) {
        cout << creatures[i].name << endl;
    }
    delete creatures;
}

/*
Make a great UX!
Over comment your code.
Create a program with allocation and deallocation of memory using pointers of 4 primitive data types of your choice on the heap with the new and delete keywords.
Create 5 objects with the new keyword for your example too.
Explain to the user in cout statements allocation and deallocation of memory with examples.
Your program should teach the user about new and delete and the allocation and deallocation of memory.
*/
