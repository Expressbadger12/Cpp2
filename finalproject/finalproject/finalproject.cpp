// finalproject.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//Boone Stewart
//space trader game


#include <iostream>
#include <vector>

using namespace std;

class product {
public:
    string name;
    float startingPrice;
    int quantity;
    int shelfLife;
    string units;


};

class ship {

    virtual void specalAbility() {

    }
};

class cargoShip : ship {

};

class explorer : ship {

};

class company {
public: 
    string name;
    float worth;
    vector<product> supply;
    int caution;
    float trickiness;
};

void printLine() {
    cout << "=============================================" << endl;
}

void checkInventory(vector<product>& storage) {
    printLine();
    cout << "You currently have: " << endl;
    for (int i = 0; i < storage.size(); i++) {
        cout << storage[i].quantity << " " << storage[i].units << " of " << storage[i].name << endl;
    }
}

void listEvents() {
//this function will list out the recent events that happened for the player's reference (including recent trades, disasters, and whatnot)
}

void proposeTrade() {
//Player will choose a other company and suggest a trade, if the company accepts, it will trigger the trade function. 
}

void advanceTime() {
//This function will randomly select an event or trade to occur. This will effect the prices of items or the actions of other companies. This function will be called after the player takes an action or the player can call it manually
}

void passiveEffects() {
//This function will regularly run on another thread, it will change the prices of items on certain planets and facilitate the expiration of certain goods while the player is navigating the menus
}

void trade() {
//This function will either be called in the background by the advancetime function or it can be called manually by the player. It will faciliated the trade of goods and services between companies.
}

void disaster() {
//This function has a chance to be called by the advance Time function. It will pick one of three unique events that can occur. This will cause some kind of change in the world.
}

void save() {
//this function will write the player's current wealth, name, and inventory to a txt file. 
}

void findRoute() {
//This function will recursivly find the quickest route from the planet the player is currently in orbit of to a given destination planet. The function will then calculate how much fuel the trip will take.
}

void travel() {
//This function will move the player from one planet to another. 
}

void listMarket() {
    //This function will list the prices of goods on each planet.
}

void intro() {
    printLine();
    cout << "Welcome, merchant! Are you ready to make your fortune? Travel the stars and trade goods to amass wealth!" << endl;
    cout << "What is the name of your company?" << endl;
    string name;
    cin >> name; // later I will replace the line with one that will enable the player to have multiple words in their name
    cout << endl;

    cout << "Welcome to the solar system, " << name << ". You're currently in orbit of Earth" << endl;
}

int main()
{
    intro();

    cout << "What would you like to do? " << endl;

    cout << "Enter '1' to list market" << endl;

    cout << "Enter '2' to list inventory" << endl;

    cout << "Enter '3' to list competitors" << endl;

    cout << "Enter '4' to list recent events" << endl;

    cout << "Enter '5' to travel" << endl;

    cout << "Enter '6' to advance time" << endl;

    cout << "Enter '7' to save" << endl;
}
