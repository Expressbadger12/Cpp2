// piratesVninjas.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class fighter {
public:
	string name;
	int health;
	int speed;

	void attack() {
		cout << "The character attacks!" << endl;
	};
};

class ninja : public fighter {
	string name = "Ninjohnson";
	int health = 25;
	int speed = 100;

	void attack() {
		cout << name << " springs fourth. Armed with ninja stars." << endl;
	}

	void ThrowStars() {
		cout << name << ": 'I am throwing my throwing stars!' " << endl;
	}
};

class pirate : public fighter {
	string name = "WarfareBeard";
	int health = 75;
	int speed = 50;

	void attack() {
		cout << name << " leaps from the mast and draws his cutlass." << endl;
	}

	void UseSword() {
		cout << name << ": 'Yarrr! I'm swooshing my sword!" << endl;
	}
};



void printLine() {
	cout << "=========================================================================" << endl;
}

void sickIntro() {
	//ascii art found here, I'm no artist : https://www.asciiart.eu/weapons/explosives 
	printLine();
	cout << "" << endl;

	cout << "     _.-^^---....,, --" << endl;
	cout << " _--                  --_" << endl;
	cout << "<                        >)" << endl;
	cout << "|                         |" << endl;
	cout << " \._                   _./" << endl;
	cout << "    ```--. . , ; .--'''       " << endl;
	cout << "          | |   |" << endl;
	cout << "       .-=||  | |=-." << endl;
	cout << "       `-=#$%&%$#=-'   " << endl;
	cout << "          | ;  :|" << endl;
	cout << " _____.,-#%&$@%#&#~,._____" << endl;


	cout << "" << endl;
	cout << "WELCOME TO PIRATES VERSES NINJAS!" << endl;
}

int main()
{
	
	sickIntro();
}

/*
[CHECK]		Add a method to your main.cpp file and call it from the main function to display a cool intro to the game.
[CHECK]		Create a class called Character class.
[CHECK]  	Create a public property in the Character class and call it Name.
[CHECK] 	Create 2 classes that inherit from the Character class.  (examples, ninja, and pirate).
[CHECK] 	Create a method called ThrowStars in the Ninja class which outputs the phrase to the screen "I am throwing stars!";
[CHECK] 	Create a method called UseSword in the Pirate class which outputs to the screen "I am Swooshing my Sword!".
			Create a constructor for both subclasses of the  Character class to initialize all public and private properties in the Character class and subclasses. (Hint: The constructor is only needed in the Ninja and Pirate classes)
			This must have a great user experience.
			The more features, classes, and objects, you add to this simulation, the better your grade will be.
			Using your own comments, comment on each line of code with the exception of cout statements unless it is at the top of a block of them.

*/