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
public:	
	string name;
	int health = 25;
	int speed = 100;

	void attack() {
		cout << name << " springs fourth. Armed with ninja stars." << endl;
	}

	void ThrowStars() {
		cout << name << ": 'I am throwing my throwing stars!' " << endl;
	}

	ninja(string n) {
		name = n;
	}
};

class pirate : public fighter {
public:	
	string name;
	int health = 75;
	int speed = 50;

	void attack() {
		cout << name << " leaps from the mast and draws his cutlass." << endl;
	}

	void UseSword() {
		cout << name << ": 'Yarrr! I'm swooshing my sword!" << endl;
	}

	pirate(string n) {
		name = n;
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
	printLine();
}

int main()
{
	sickIntro();


	string pname;
	string nname;

	cout << "Name your Pirate: ";
	cin >> pname;

	cout << endl;

	cout << "Name your Ninja: ";
	cin >> nname;


	//back in the day the names were hard coded
	// there were Ninjohnson and WarefareBeard. 
	//This doesn't matter at all, I just really liked those names so I don't want them to disapear forever.

	ninja Ninja = ninja(nname);
	pirate Pirate = pirate(pname);


	Pirate.attack();
	cout << endl;
	Ninja.attack();
	cout << endl;

	Pirate.UseSword();
	cout << endl;

	Ninja.ThrowStars();
	cout << endl;


	//whoever has the longer name wins. It's kinda funny that way
	
	if (Ninja.name.length() > Pirate.name.length()) {
		cout << Ninja.name << " wins the duel!" << endl;
	}
	else if (Ninja.name.length() < Pirate.name.length()) {
		cout << Pirate.name << " wins the duel!" << endl;
	}
	else {
		cout << "It's a tie!" << endl;
	}
}