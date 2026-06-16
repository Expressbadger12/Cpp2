// w5ishd1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    // &variable is the memory address of a variable
    //datatype* name is declaring a pointer variable that stores the address for a given datatype
    //datatype* ptr = &variable creates a pointer called ptr that stores the memory address of variable. 
    // printing ptr will print the long address
    // printing *ptr will print the value of the variable who's address is being stored in the pointer
    // *ptr = 100 will change the value of the original number

    int* ptr = new int;
    *ptr = 75;
    cout << *ptr;
    delete ptr; //I don't know what new and delete do

}
/*
Create a new application of your choice.
Your application must have at least 5 functions that take a variety of Arguments and types.
Make all your parameters pointers.
Over comment your code.
Your application must do something interesting besides demo pointers and speed.
Make a great UX.
*/