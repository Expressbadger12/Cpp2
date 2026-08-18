// finalproject.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//Boone Stewart
//space trader game


#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <chrono>
#include <thread>
#include <fstream>

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

    company(string n, float w, float t, int c) {
        name = n;
        worth = w;
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

planet* currentPlanet;

void printLine() {
    cout << "=============================================" << endl;
}

void checkInventory(const vector<product>& market, company& player) {
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
        player.worth += market[pnim - 1].startingPrice * quin;

    }
    else {
        return;
    }

}


void passiveEffects(planet* earth, planet* mars, planet* venus, bool skip) {
//This function will regularly run on another thread, it will change the prices of items on certain planets and facilitate the expiration of certain goods while the player is navigating the menus
   
    for (int i = 0; i < earth->market.size(); i++) {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> distr(1, 100);
        int rond = distr(gen);
        float perct = rond / 100.0f;

        earth->market[i].startingPrice *= perct;
    }
    for (int i = 0; i < mars->market.size(); i++) {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> distr(1, 100);
        int rond = distr(gen);
        float perct = rond / 100.0f;

        mars->market[i].startingPrice *= perct;
    }
    for (int i = 0; i < venus->market.size(); i++) {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> distr(1, 100);
        int rond = distr(gen);
        float perct = rond / 100.0f;

        venus->market[i].startingPrice *= perct;
    }

    if (!skip) {
        this_thread::sleep_for(chrono::seconds(20));
    }
}


void advanceTime(planet* earth, planet* mars, planet* venus) {
    //This function will randomly select an event or trade to occur. This will effect the prices of items or the actions of other companies. This function will be called after the player takes an action or the player can call it manually
    passiveEffects(earth, mars, venus, true);
    passiveEffects(earth, mars, venus, true);
    passiveEffects(earth, mars, venus, true);
    cout << "You have waited 3 days" << endl;
}

void save() {
//this function will write the player's current wealth, name, and inventory to a txt file. 
}

void travel(planet* current, planet* earth, planet* mars, planet* venus, company& player) {
//This function will move the player from one planet to another. 

    string choice;

    cout << "You are on " << current->name << endl;
    cout << "Would you like to travel to: " << endl;
    cout << "(1) Earth" << endl;
    cout << "(2) Mars" << endl;
    cout << "(3) Venus" << endl;

    cin >> choice;

    string destination;

    int dir;

    try {
        dir = stoi(choice);
    }
    catch (const invalid_argument& e) {
        cout << "Nice try" << endl;
        return;
    }

    switch (dir) {
    case 1:
        destination = "Earth";
        break;
    case 2:
        destination = "Mars";
        break;
    case 3:
        destination = "Venus";
        break;
    default:
        cout << "Invalid selection. Warp jump aborted" << endl;
        return;
    }

    if (destination == current->name) {
        cout << "You're already here!" << endl;
        return;
    }

    if (player.supply[0].quantity - 20 < 0) {
        cout << "Not enough fuel" << endl;
        return;
    }

    player.supply[0].quantity -= 20;
    switch (dir) {
    case 1:
        currentPlanet = earth;
        break;
    case 2:
        currentPlanet = mars;
        break;
    case 3:
         currentPlanet = venus;
         break;
    default:
        cout << "Invalid selection. Warp jump aborted" << endl;
        return;
    }

}

void listMarket(const vector<product>& market, company& player) {
    //This function will list the prices of goods on each planet.
    cout << "You are in orbit of " << currentPlanet->name << "." << endl;

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

void passage(planet* earth, planet* mars, planet* venus) {
    
    while (playing) {
        passiveEffects(earth, mars, venus, false);
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

void loadSave(company& player) {
    cout << "Would you like to load the save? y/n" << endl;
    string who;
    cin >> who;
    if (who == "y") {
        ifstream inFile("saveData.txt");

        if (!inFile) {
            cout << "Could not load save. You're screwed" << endl;
            return;
        }

        getline(inFile, player.name);
        inFile >> player.worth;
        inFile >> player.supply[0].quantity;
        inFile >> player.supply[1].quantity;
        inFile >> player.supply[2].quantity;

        inFile.close();

        cout << "Save loaded" << endl;
    }
    else {
        cout << "Save not loaded" << endl;
        return;
    }

}

int main()
{
    string pname = intro();

    company player = company(pname, 4000, 0, 0);

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

    planet earth;
    earth.name = "Earth";
    earth.market.push_back(product("Fuel", "gallons", 50));
    earth.market.push_back(product("Water", "gallons", 25));
    earth.market.push_back(product("Unobtainium", "pounds", 80));

    planet mars;
    mars.name = "Mars";
    mars.market.push_back(product("Fuel", "gallons", 20));
    mars.market.push_back(product("Water", "gallons", 30));
    mars.market.push_back(product("Unobtainium", "pounds", 100));

    planet venus;
    venus.name = "Venus";
    venus.market.push_back(product("Fuel", "gallons", 20));
    venus.market.push_back(product("Water", "gallons", 40));
    venus.market.push_back(product("Unobtainium", "pounds", 100));

    loadSave(player);

    currentPlanet = &earth;

    thread t1(passage, &earth, &mars, &venus);

    while (playing) {
        string choice;
        checkBalance(player);
        if (!playing) {
            break;
        }

        cout << "What would you like to do? " << endl;

        cout << "Enter '1' to list market" << endl;

        cout << "Enter '2' to list inventory" << endl;

        cout << "Enter '3' to travel" << endl;

        cout << "Enter '4' to advance time" << endl;

        cout << "Enter '5' to save" << endl;
        
        cin >> choice;

        if (choice == "1") {
            listMarket(currentPlanet->market, player);
        }
        else if (choice == "2") {
            checkInventory(currentPlanet->market, player);
        }
        else if (choice == "3") {
            travel(currentPlanet, &earth, &mars, &venus, player);
        }
        else if (choice == "4") {
            advanceTime(&earth, &mars, &venus);
        }
        else if (choice == "5") {
            ofstream outFile("saveData.txt");

            if (!outFile.is_open()) {
                cout << "could not open file. You're screwed" << endl;
                continue;
            }
            outFile << player.name << endl;
            outFile << player.worth << endl;
            outFile << player.supply[0].quantity << endl;
            outFile << player.supply[1].quantity << endl;
            outFile << player.supply[2].quantity << endl;

            cout << "Saved!" << endl;
        }
    }
    t1.join();
   
}
