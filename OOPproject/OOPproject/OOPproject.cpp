// OOPproject.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>

using namespace std;

//Library management app

class Library {
private:

public:
	string name;

	string address;
};

class Loan {
private:

public:
	Book book;

	Person loanie;

	Librarian approver;

	Library home;
};

class Book {
private:

public:

	string title;
};

class Person {
private:

public:
	string name;

	Loan outstanding;
};

class Member : public Person {
private:

public:

};

class Librarian : public Person {
private:

public:

};

class Catalog {
private:

public:

};

int main()
{

}


/*
Class Design:

	Choose a real-world scenario or problem domain for which you will design a system.

	Identify at least seven classes relevant to the problem domain. Clearly define the attributes and behaviors of each class.

Inheritance:

	Implement the necessary example of inheritance in your system. Show how a derived class inherits attributes and behaviors from a base class. Provide a rationale for using inheritance in your design.

Polymorphism:

	Demonstrate polymorphism in your program. This could be achieved through function overloading or using virtual functions. Explain the advantages of using polymorphism in your design.

Encapsulation and Abstraction:

	Utilize encapsulation to protect the internal state of your classes. Make sure to use access specifiers appropriately. Justify your choices in terms of data hiding and encapsulation.

Operator Overloading:

	Overload the necessary operators in your program. Explain how operator overloading enhances the usability and readability of your code.

Exception Handling:

	Implement exception handling to address potential runtime errors in your program. Discuss the types of exceptions you anticipate and how your program will handle them gracefully.

File I/O:

	Include functionality for reading and writing data to files. Show how your program can persistently store and retrieve object data. Discuss the file format and how it aligns with your class design.
*/