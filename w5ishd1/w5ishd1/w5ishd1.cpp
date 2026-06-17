// w5ishd1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <random>


//I was going to do a calculator but then I realized that all my functions were just taking doubles

class fencer {
public:
	std::string name = "doe";

	int score = 0;

	int wins = 0;

	fencer(std::string n, int s) {
		name = n;
		score = s;
	}
};

void makeBracket(fencer* fencers) {
	std::random_device r;
}

void listFencers(fencer* fencers) {
	
	std::cout << "The fencers are: " << std::endl;
	for (int i = 0; i < (sizeof(fencers)); i++) {
		std::cout << fencers[i].name << std::endl;
	}
}


void countRounds(fencer* one, fencer* two, int* length) {
	
	std::cout << "counting rounds" << std::endl;

	while (true){
		std::string winner;
		std::cout << "Who's point?" << std::endl;
		std::cout << "1 | " << one->name << std::endl;
		std::cout << "2 | " << two->name << std::endl;
		std::cout << "3 | Double"  << std::endl;
		std::cout << "4 | No point" << std::endl;

		std::cin >> winner;

		if (winner == "1") {
			one->score += 1;
		}
		else if (winner == "2") {
			two->score += 1;
		}
		else if (winner == "3") {
			one->score += 1;
			two->score += 1;
		}
		else {
			continue;
		}

		if (one->score >= *length || two->score >= *length) {
			if (one->score - two->score > 1) {
				std::cout << one->name << " wins!" << std::endl;
				one->wins += 1;
				break;
			}
			else if (two->score - one->score > 1) {
				std::cout << one->name << " wins!" << std::endl;
				two->wins += 1;
				break;
			}
		}

		std::cout << "Current scores: " << std::endl;
		std::cout << one->name << ": " << one->score << "/" << *length << std::endl;
		std::cout << two->name << ": " << two->score << "/" << *length << std::endl;
	}
}

void displayBracket() {

}

void clearBracket(fencer* stemble, fencer* mssck, fencer* grrlo, fencer* bandin, fencer* clwon, fencer* zlack, fencer* fencers) {
	fencers[6] = {*stemble, *mssck, *grrlo, *bandin, *clwon, *zlack};
}

int main()
{
	fencer stemble = fencer("Stemble", 0);

	fencer mssck = fencer("Mssck", 0);

	fencer grrlo = fencer("Grrlo", 0);

	fencer bandin = fencer("Bandin", 0);

	fencer clwon = fencer("Clwon", 0);

	fencer zlack = fencer("Zlack", 0);

	fencer fencers[6] = {stemble, mssck, grrlo, bandin, clwon, zlack};

	listFencers(fencers);

	std::cout << "This line runs" << "\n";
	int roundNorm = 10;

	makeBracket(fencers);

	listFencers(fencers);

	//countRounds(&stemble, &mssck, &roundNorm);
}
/*
Create a new application of your choice.
Your application must have at least 5 functions that take a variety of Arguments and types.
Make all your parameters pointers.
Over comment your code.
Your application must do something interesting besides demo pointers and speed.
Make a great UX.
*/