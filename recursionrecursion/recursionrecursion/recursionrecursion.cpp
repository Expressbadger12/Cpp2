// recursionrecursion.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include <string>

using namespace std;


void makeMaze(int x, int y) {
	if (y <= 0) {
		return;
	}

	for (int i = x; i > 0; i--) {
		int num = rand() % 2;
		if (num == 0) {
			cout << " ";
		}
		else {
			cout << "#";
		}
	}
	cout << endl;


	return makeMaze(x, (y - 1));
}


int main()
{
	string choice;
	int size = 1;

	while (true){
		cout << "Enter an integer for the size of your maze: ";
		cin >> size;
		
		if (!cin) {
			cout << "Please enter an integer greater than 0" << endl; //something's going wrong here. It doesn't wait for cin to hit again.
			cin.clear(); // Clear the fail state
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			continue;
		}

		if (size > 0) {
			makeMaze(size, size);
		}
		else {
			cout << "Please enter an integer greater than 0" << endl;
		}
	}

}

/*
Using Direct Recursion, write a program to auto-create and display the following mazes with the following dimensions below from user input, Your maze should not be hardcoded!
Your maze should display on a console window using ASCII characters.
Your maze should be 2D. Extra credit for 3D Mazes
It should include ASCII characters as walls and blank spaces as paths.  It does not have to be a solvable maze, however, extra credit for a solvable maze.
*/