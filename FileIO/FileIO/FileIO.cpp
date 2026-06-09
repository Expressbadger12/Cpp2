// FileIO.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>

using namespace std;


void write() {
	ofstream outputFile("text.txt");
	string text;
	cout << "What would you like to write to the file?" << endl;
	getline(std::cin, text);
	outputFile << text;
	cout << "Written: '" << text << "'" << endl;

	outputFile.close();
	cout << "Saved" << endl;
}

void read() {
	string text; 
	ifstream file("text.txt");

	while (getline(file, text)) {
		cout << text;
	}
}

int main()
{	
	string choice;
	while (true) {
		cout << endl;
		cout << "Would you like to " << endl;
		cout << "1 | Read the file" << endl;
		cout << "2 | write to the file" << endl;

		getline(cin, choice);

		if (choice == "1") {
			read();
		}
		else if (choice == "2") {
			write();
		}
	}
}

/*
Your app should have a good UX.
Over comment your code!
Display a description of the program and how to use it for the user when your app starts.
Your app must be able to write the same contents to a text file and the screen at the same time.
Your app must be able to read the data from a text file and then write the contents to the display.
*/