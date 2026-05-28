// w3d2fr.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

double divideNumbers(int a, int b) {
    if (b == 0) {
        throw "Math ERROR: Cannot divide by zero!";
    }
    return static_cast<double>(a) / b;
}

//Function to validate age
void checkAge(int age) {
    if (age < 0) {
        throw age;
    }
    if (age < 18) {
        throw "Access Denied: You must be at least 18 years old!";
    }
    cout << "Access Granted!" << endl;
}

//Function to access array elements safely
int getElement(int arr[], int size, int index) {
    if (index < 0 || index >= size) {
        throw out_of_range("Array index is out of bounds!");
    }
    return arr[index];
}
//Function to validate password length
void checkPassword(string password) {
    if (password.length() < 6) {
        throw "Password must contain at least 6 characters";
    }
    cout << "Password accepted!" << endl;
}

int main()
{
    try {
        int num1, num2;
        cout << "Division test!" << endl;
        cout << "Enter your first number: ";
        cin >> num1;
        cout << endl;
        cout << "Enter your second number: ";
        cin >> num2;
        cout << endl;
        double result = divideNumbers(num1, num2);
        cout << "Result = " << result << endl;
    }
    catch (const char* errorMessage) {
        cout << errorMessage << endl;
    }

    //Age validation
    try{
        int age;
          cout << "Age Validation test: " << endl;
          cout << "Enter your age: ";
          cin >> age;
          checkAge(age);
    }
    catch (int invalidAge) {
        cout << "Invalid age entered: " << invalidAge << endl;
    }
    catch (const char* message) {
        cout << message << endl;
    }
    // Array exception
    try {
        int numbers[5] = { 10, 20, 30, 40,50 };
        int index;
        cout << "Array Acess Test: " << endl;
        cout << "Enter array index (0-4): ";
        cin >> index;
        cout << endl;
        int value = getElement(numbers, 5, index);
        cout << "Value of index: " << index << " = " << value << endl;
    }
    catch (const out_of_range& error) {
        cout << "Out of Range Exception: " << error.what() << endl;
    }
    //validate a password
    try {
        string password; 
        cout << "Password Test: " << endl;
        cout << "Enter password: ";
        cin >> password;
        checkPassword(password);
    }
    catch (const char* message) {
        cout << "Password Error: " << message;
    }
}
