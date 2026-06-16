// IOEX.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>

using namespace std;

void readFile(string name) {

	try {
		string text;

		ifstream File(name);

		if (!File) {
			throw runtime_error("No such file or you don't have permissions");
		}

		while (getline(File, text)) {
			cout << text << endl;
		}

		File.close();
	}
	catch (const exception& e) {
		cout << "Exception caught: " << e.what() << endl;
	}
}

void writeFile(string name) {
	cout << "Enter the text you would like to write to the file (press ; and enter to end writing):" << endl;
	try {
		string text;
		int length;
		string last;

		ofstream File(name);

		if (!File) {
			throw runtime_error("No such file or you don't have permissions");
		}

		while (true) {
			getline(cin, text);
			length = text.length();
			if (length - 1 < 0) {
				throw runtime_error("Must enter some text");
				break;
			}
			last = text[length - 1];


			File << text << endl;

			if (last == ";") {
				break;
			}
		}

		File.close();
	}
	catch (const exception& e) {
		cout << "Exception caught: " << e.what() << endl;
	}
}

int main()
{
	writeFile("file.txt");

	cout << "You wrote: " << endl;

	readFile("file.txt");
}


/*
Writes data to a file

	Prompt the user to enter multiple lines of text (until they type a keyword like "STOP").

	Save all entered lines into a text file (e.g., data.txt).

Reads data from the file

	After writing, open the same file and display its contents back to the user.

	Implements proper exception handling

Handle common file I/O errors such as:

	File not found

	Permission denied

	Input/output errors

	Handle invalid user input gracefully.
 */