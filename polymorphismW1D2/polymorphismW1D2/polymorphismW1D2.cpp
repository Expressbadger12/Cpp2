// polymorphismW1D2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
//parent class
class Animal {
public:
    void sound() {
        cout << "Animal makes a sound..." << endl;
    }
};
//child class
class Dog : public Animal {// 1- Inheritance 
public:
    void sound() { //overriding the sound from the parent
                    //2- polymorphism
        cout << "Dogs bark woof woof..." << endl;
    }
};

class Cat : public Animal {
public:
    void sound() {
        cout << "Cat meows meow meow..." << endl;
    }
};


class Car {
public:
    string brand;
    int year;
    //There is already a default constructor 
    //Create a parameterized constructor
    Car(string b, int y) {
        brand = b;
        year = y;
    }
};


class Vehicle {
public:
    void start() {
        cout << "Vehicle is starting....." << endl;
    }

};

class Truck : public Vehicle {
public:
    void start() {
        cout << "Truck is starting grrr grr grr" << endl;
    }
};


int main()
{
    Dog dog1;
    dog1.sound(); // Child instance is using the parent behavior

    Cat cat1;
    cat1.sound();

    Car car1("BMW", 2025);

    Truck truck1;
    truck1.start();
}
