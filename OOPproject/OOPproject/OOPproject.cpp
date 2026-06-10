// OOPproject.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <stdexcept>

using namespace std;

//Library management app

class Library {
private:
	string name;

	string address;

	int LibraryID;
public:
	string getname() {
		return name;
	}
	string getaddress() {
		return address;
	}
	int getLibraryID() {
		return LibraryID;
	}

	Library(string n, string a, int ID) {
		address = a;
		name = n;
		LibraryID = ID;
	}
};

class Book {
private:
	string title;

	string author;

	int isbn;

	bool isavailable;
public:
	string gettitle() {
		return title;
	}
	string getauthor(){
		return author;
	}
	int getisbn() {
		return isbn;
	}
	bool getisavailable() {
		return isavailable; 
	}
	void displayInfo() {
		cout << "Title: " << title << endl;
		cout << "Author: " << author << endl;
		cout << "ISBN number: " << isbn << endl;

		if (isavailable) {
			cout << "This book is available" << endl;
		}
		else {
			cout << "This book is currently checked out" << endl;
		}
	}
	void checkOut() {
		cout << "Checking out " << title << endl;
		if (!isavailable)
		{
			throw runtime_error("Book already checked out.");
		}

		isavailable = false;
	}
	bool operator==(const Book& other) //to check if books are identical
	{
		return isbn == other.isbn;
	}
	void returnBook() {
		if (isavailable)
		{
			throw runtime_error("Book is not checked out");
		}

		isavailable = true;
	}
	Book(string t, string a, int i) {
		title = t;
		author = a;
		isbn = i;
		isavailable = true;
	}
};

class Person {
private:
	string name;

	int numloans;
public:
	string getname() {
		return name;
	}
	int getloans() {
		return numloans;
	}
	virtual void displayInfo() {
		cout << "Name: " << name << endl;
		cout << "Number of outstanding loans: " << numloans << endl;
	}

	Person(string n, int l){
		name = n;
		numloans = l;
	}
};

class Member : public Person { //members are people
private:
	int memberID;

public:
	int getmemberID() {
		return memberID;
	}
	Member(string n, int l, int id)
		: Person(n, l)
	{
		memberID = id;
	}
	void displayInfo() override {
		cout << "Name: " << getname() << endl;
		cout << "Member ID: " << memberID << endl;
		cout << "Number of outstanding loans: " << getloans() << endl;
	}
};

class Librarian : public Person { //librarians are people
private:
	int brarianID;
public:
	int getbrarianID() {
		return brarianID;
	}
	Librarian(string n, int l, int id)
		: Person(n, l)
	{
		brarianID = id;
	}
	void displayInfo() override {
		cout << "Name: " << getname() << endl;
		cout << "Librarian ID: " << brarianID << endl;
		cout << "Number of outstanding loans: " << getloans() << endl;
	}
};

class Catalog {
private:
	vector<Book> books;

public:
	void addBook(Book b)
	{
		books.push_back(b);
	}
	void saveToFile()
	{
		ofstream file("books.txt");

		for (Book& book : books)
		{
			file << book.gettitle() << ","
				<< book.getauthor() << ","
				<< book.getisbn() << endl;
		}

		file.close();
	}


	void displayBooks()
	{
		for (Book& book : books)
		{
			book.displayInfo();
		}
	}

};

class Loan {
private:
	int book;

	int loanie;

	int approver;

	int home;
public:

	int getbook() {
		return book;
	}
	int getloanie(){
		return loanie;
	}
	int getapprover() {
		return approver;
	}
	int gethome() {
		return home;
	}
	Loan(int b, int l, int a, int h){
		book = b;
		loanie = l;
		approver = a;
		home = h;
	}
};

int main()
{
	Member trandor("trandor", 0, 10);
	Librarian alice("alice", 0, 4);

	Book dune("Dune", "Frank Herbert", 12345);
	Book hobbit("The Hobbit", "J.R.R. Tolkien", 67890);
	Book foundation("Foundation", "Isaac Asimov", 11111);

	Catalog catalog;

	catalog.addBook(dune);
	catalog.addBook(hobbit);
	catalog.addBook(foundation);

	cout << "Welcome to my little library app!" << endl;
	cout << "We have a librarian, alice" << endl;
	alice.displayInfo();
	cout << "And a member, Trandor" << endl;
	trandor.displayInfo();
	cout << "We can see what books we have available by checking the catalogue" << endl;
	catalog.displayBooks();
	cout << "And we can save the catalog to a file: " << endl;
	catalog.saveToFile();
	cout << "You cant's see from here, but it worked. It's saved to books.txt" << endl;

	cout << "To display error handling, I will try to checkout the same book twice" << endl;
	try
	{
		dune.checkOut();
		dune.checkOut();
	}
	catch (exception& exep)
	{
		cout << exep.what() << endl;
	}



}

//

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