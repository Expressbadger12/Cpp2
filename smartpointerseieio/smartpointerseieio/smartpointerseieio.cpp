// smartpointerseieio.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

class item {
public: 
    string name;

    item(string n) {
        name = n;
        cout << name << " was created" << endl;
    }

    void print() {
        cout << "This is a " << name << endl;
    }
};

int main()
{
    unique_ptr<item> sword(new item("sword"));

    unique_ptr<item> potion(new item("potion"));

    string choice;

    cout << "Would you like to replace the sword with a bow? y/n: ";
    
    cin >> choice;

    if (choice == "y") {

    }
    else if (choice == "n") {

    }
    else {
        cout << "Bad response" << endl;
    }
}

/*
Over comment all your code for the future you in your own words.
Make a great UX. (This can be accomplished with lots of cout statements letting the user know what is going on.)
Your program should do something, in addition, to clearly demonstrating smart pointers.
You need at least one type of smart pointer. A unique_ptr, or shared_ptr, or weak_ptr.
Demonstrate when the pointers go out of scope and therefore the values are deleted.
Hint: Use cout to print something to show when the pointers go out of scope and therefore the values are deleted.
*/