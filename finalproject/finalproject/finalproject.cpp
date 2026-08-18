// finalproject.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//Boone Stewart
//space trader game


#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool playing = true;

class product {
public:
    string name;
    float startingPrice;
    int quantity;
    int shelfLife;
    string units;

    product(string n, string u, float p) {
        name = n;
        units = u;
        startingPrice = p;
        quantity = 0; 
        shelfLife = 0;
}
};

class ship {
protected:
    string name;
    float efficiency;
    int capacity;
public:
    virtual void specialAbility() {
        cout << "click click click click" << endl;
    }
};

class CargoShip : public ship {
public:
    CargoShip() {
        name = "Cargo Ship";
        efficiency = 0.8;
        capacity = 300;
    }

    void specialAbility() override {
        cout << "" << endl;
    }
};

class Explorer : public ship {
public:
    Explorer() {
        name = "Explorer";
        efficiency = 1.1;
        capacity = 200;
    }

    void specialAbility() override {
        cout << "" << endl;
    }
};

class company {
public: 
    string name;
    float worth;
    vector<product> supply;
    int caution;
    float trickiness;
    string location;

    company(string n, float w, string loc, float t, int c) {
        name = n;
        worth = w;
        location = loc;
        trickiness = t;
        caution = c;
        
    }
};

class Event {
protected:
    string name;
    string description;
public:
    virtual void fallout() {
        cout << "Nothing happens" << endl;
    }
};

class planet {
public:
    string name;
    vector<product> market;
};

void printLine() {
    cout << "=============================================" << endl;
}

void checkInventory(company& player) {
    printLine();

    vector<product>& storage = player.supply;
    cout << "You currently have: " << endl;
    for (int i = 0; i < storage.size(); i++) {
        cout << "(" << i+1 << ") " << storage[i].quantity << " " << storage[i].units << " of " << storage[i].name << endl;
    }

    cout << "You have $" << player.worth << endl;

    string choice;
    cout << "Would you like to sell something? (y/n)" << endl;
    cin >> choice;
    if (choice == "y") {
        string prod;
        int pnim;
        cout << "Enter which product you would like to buy (1/2/3)" << endl;
        cin >> prod;
        try {
            pnim = stoi(prod);
        }
        catch (const invalid_argument& e) {
            cout << "Nice try" << endl;
            pnim = 0;
        }

        if (pnim <= 0) {
            return;
        }
        if (pnim >= 4) {
            return;
        }

        string quan;
        int quin;
        cout << "How many " << player.supply[pnim - 1].units << " would you like to sell?" << endl;
        cin >> quan;

        try {
            quin = stoi(quan);
        }
        catch (const invalid_argument& e) {
            cout << "Nice try" << endl;
            return;
        }

        if (quin > player.supply[pnim - 1].quantity) {
            quin = player.supply[pnim - 1].quantity;
        }
        if (quin < 0) {
            quin = 0;
        }

        player.supply[pnim - 1].quantity -= quin;
        player.worth ++= player.supply[pnim - 1].startingPrice * quin;

    }
    else {
        return;
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

void listMarket(const vector<product>& market, company& player) {
    //This function will list the prices of goods on each planet.
    for (int i = 0; i < market.size(); i++) {
        cout << "(" << i + 1 << ") " << market[i].name << " - $" << market[i].startingPrice << " per " << market[i].units << endl;
    }

    string choice;
    cout << "Would you like to make a purchase? (y/n)" << endl;
    cin >> choice;
    if (choice == "y") {
        string prod;
        int pnim;
        cout << "Enter which product you would like to buy (1/2/3)" << endl;
        cin >> prod;
        try {
            pnim = stoi(prod);
        }
        catch (const invalid_argument& e) {
            cout << "Nice try" << endl;
            pnim = 0;
        }

        if (pnim <= 0) {
            return;
        }
        if (pnim >= 4) {
            return;
        }
        
        cout << "How many " << market[pnim - 1].units << " would you like to purchase?" << endl;
        string quan;
        cin >> quan;
        int quin;
        try {
            quin = stoi(quan);
        }
        catch (const invalid_argument& e) {
            cout << "Nice try" << endl;
            return;
        }
        if (quin < 0) {
            return;
        }
        
        player.supply[pnim - 1].quantity += quin;
        player.worth -= (market[pnim - 1].startingPrice * quin);

    }
    else {
        return;
    }

}

string intro(){
    printLine();
    cout << "Welcome, merchant! Are you ready to make your fortune? Travel the stars and trade goods to amass wealth!" << endl;
    cout << "What is the name of your company?" << endl;
    string name;
    cin >> name; // later I will replace the line with one that will enable the player to have multiple words in their name
    cout << endl;

    cout << "Welcome to the solar system, " << name << ". You're currently in orbit of Earth" << endl;

    return name;
}


void checkBalance(company& player) {
    if (player.worth <= 0) {
        cout << "You've gone bankrupt! You lose!" << endl;
        playing = false;
    }
}

int main()
{
    string pname = intro();

    company player = company(pname, 4000, "Earth", 0, 0);

    product fuel = product("fuel", "gallons", 50);

    product water = product("water", "gallons", 25);

    product unobtainium = product("unobtainium", "pounds", 80);

    vector<product> market;
    market.push_back(fuel);
    market.push_back(water);
    market.push_back(unobtainium);
        
    player.supply.push_back(fuel);
    player.supply.push_back(water);
    player.supply.push_back(unobtainium);


    while (playing) {
        string choice;
        checkBalance(player);
        if (!playing) {
            break;
        }

        cout << "What would you like to do? " << endl;

        cout << "Enter '1' to list market" << endl;

        cout << "Enter '2' to list inventory" << endl;

        cout << "Enter '3' to list competitors" << endl;

        cout << "Enter '4' to list recent events" << endl;

        cout << "Enter '5' to travel" << endl;

        cout << "Enter '6' to advance time" << endl;

        cout << "Enter '7' to save" << endl;
        
        cin >> choice;

        if (choice == "1") {
            listMarket(market, player);
        }
        else if (choice == "2") {
            checkInventory(player);
        }
    }
   
}
