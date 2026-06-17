// w5ishd1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <random>
#include <algorithm>


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

	std::random_device rd;
	std::mt19937 gen(rd());

	std::shuffle(fencers, fencers + 6, gen);



}

void listFencers(fencer* fencers) {
	
	std::cout << "The fencers are: " << std::endl;
	for (int i = 0; i < 6; i++) {
		std::cout << fencers[i].name << std::endl;
	}
}


void countRounds(fencer* one, fencer* two, int* length) {
	
	one->score = 0;
	two->score = 0;

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
				std::cout << two->name << " wins!" << std::endl;
				two->wins += 1;
				break;
			}
		}

		std::cout << "Current scores: " << std::endl;
		std::cout << one->name << ": " << one->score << "/" << *length << std::endl;
		std::cout << two->name << ": " << two->score << "/" << *length << std::endl;
	}
}

void displayBracket(fencer* bracket) {
	std::cout << "The bracket its:" << std::endl;
	std::cout << bracket[0].name << " vs " << bracket[1].name << std::endl;
	std::cout << bracket[2].name << " vs " << bracket[3].name << std::endl;
	std::cout << bracket[4].name << " vs " << bracket[5].name << std::endl;
}

void clearBracket(fencer* bracket, fencer* original) {
	for (int i = 0; i < 6; i++) {
		bracket[i] = original[i];
	}
}

int main()
{
	fencer stemble = fencer("Stemble", 0);

	fencer mssck = fencer("Mssck", 0);

	fencer grrlo = fencer("Grrlo", 0);

	fencer bandin = fencer("Bandin", 0);

	fencer clwon = fencer("Clwon", 0);

	fencer zlack = fencer("Zlack", 0);

	fencer originalFencers[6] =
	{
		stemble,
		mssck,
		grrlo,
		bandin,
		clwon,
		zlack
	};

	fencer fencers[6] =
	{
		stemble,
		mssck,
		grrlo,
		bandin,
		clwon,
		zlack
	};


	int roundNorm = 10;

	std::string choice;

	while (true) {
		std::cout << "What would you like to do?" << std::endl;
		std::cout << "1 | list fencers" << std::endl;
		std::cout << "2 | create bracket" << std::endl;
		std::cout << "3 | reset bracket" << std::endl;
		std::cout << "4 | list bracket" << std::endl;
		std::cout << "5 | count points" << std::endl;

		std::cin >> choice;

		if (choice == "1") {

			listFencers(fencers);
		}
		else if (choice == "2") {
			makeBracket(fencers);
		}
		else if (choice == "3") {
			clearBracket(fencers, originalFencers);
		}
		else if (choice == "4") {
			displayBracket(fencers);
		}
		else if (choice == "5") {

			std::string chons;
			std::string chins;

			fencer* one;
			fencer* two;

			while (true) {


				for (int i = 0; i < 6; i++) {
					std::cout << i + 1 << " | " << fencers[i].name << std::endl;
				}
				std::cout << "Fencer 1:" << std::endl;
				std::cin >> chons;


				if (chons == "1") {
					one = &fencers[0];
				}
				else if (chons == "2") {
					one = &fencers[1];
				}
				else if (chons == "3") {
					one = &fencers[2];
				}
				else if (chons == "4") {
					one = &fencers[3];
				}
				else if (chons == "5") {
					one = &fencers[4];
				}
				else if (chons == "6") {
					one = &fencers[5];
				}
				else {
					continue;
				}


				std::cout << "Fencer 2:" << std::endl;
				std::cin >> chins;

				if (chins == "1") {
					two = &fencers[0];
					break;
				}
				else if (chins == "2") {
					two = &fencers[0];
					break;
				}
				else if (chins == "3") {
					two = &fencers[0];
					break;
				}
				else if (chins == "4") {
					two = &fencers[0];
					break;
				}
				else if (chins == "5") {
					two = &fencers[0];
					break;
				}
				else if (chins == "6") {
					two = &fencers[0];
					break;
				}
				else {
					continue;
				}



			}


			countRounds(one, two, &roundNorm);
		}
		else {
			continue;
		}
	}
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