// piratesVninjas.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class GameStructure {
public:
	virtual void Help() {

	}
};


class fighter : public GameStructure {
private:
	int health = 400;
	int speed = 400;

public:
	string name;

	virtual int attack() {
		cout << "The character attacks!" << endl;
		return 10;
	};

	//setter
	void setHealth(int h) {
		if (health - h <= 0) {
			health = 0;
			cout << name << " has died." << endl;
		}
		else {
			health = health - h;
		}
	}


	//getter
	int getHealth() {
		return health;
	}

	void talk() {
		cout << name << ": You're going down!" << endl;
	}

	void talk(string n, string message) {
		cout << n << ": " << message << endl;
	}

	void Help() {

	}


};

class ninja : public fighter {
private:
	int health = 25;
	int speed = 100;

public:	
	string name;

	int attack() override {
		cout << name << " springs fourth. Armed with ninja stars." << endl;

		return 25;
	}

	void ThrowStars() {
		cout << name << ": 'I am throwing my throwing stars!' " << endl;
	}

	ninja(string n) {
		name = n;
	}

	void Help() {
		cout << "Ninjas are fast and deal a lot of damage, but they don't have very many hit points" << endl;
	}

	void talk() {
		cout << name << ": You're going down!" << endl;
	}

	void talk(string n, string message) {
		cout << n << ": " << message << endl;
	}


};

class pirate : public fighter {
private:
	int health = 75;
	int speed = 50;
public:	
	string name;


	int attack() override {
		cout << name << " leaps from the mast and draws his cutlass." << endl;
		return 15;
	}

	void UseSword() {
		cout << name << ": 'Yarrr! I'm swooshing my sword!" << endl;
	}

	pirate(string n) {
		name = n;
	}

	void Help() {
		cout << "Pirates are pretty well-rounded in their skills. They're experts at nothing but they can do a lot." << endl;
	}

	void talk() {
		cout << name << ": You're going down!" << endl;
	}

	void talk(string n, string message) {
		cout << n << ": " << message << endl;
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

	cout << "They can say a default line: " << endl;
	Pirate.talk();
	cout << "Or they can say a custom message: " << endl;
	Pirate.talk(Pirate.name, "Yar har fiddle dee dee");

	cout << "Here's the help text for both: " << endl;

	Pirate.Help();
	Ninja.Help();












	//whoever has the longer name wins. It's kinda funny that way
	
	//if (Ninja.name.length() > Pirate.name.length()) {
	//	cout << Ninja.name << " wins the duel!" << endl;
	//}
	//else if (Ninja.name.length() < Pirate.name.length()) {
	//	cout << Pirate.name << " wins the duel!" << endl;
	//}
	//else {
	//	cout << "It's a tie!" << endl;
	//}
}