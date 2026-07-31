// threading.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>

using namespace std;

//void calculateSum(int number[], int size) {
//	int sum = 0;
//	for (int i = 0; i < size; i++) {
//		sum += number[i];
//	}
//	cout << "Sum = " << sum << endl;
//}

/*
void cookBurger() {
	cout << "Cooking Burger.." << endl;
	this_thread::sleep_for(chrono::seconds(3));
	cout << "Burger ready!" << endl;
}

void cookPizza() {
	cout << "Cooking pizza..." << endl;
	this_thread::sleep_for(chrono::seconds(4));
	cout << "Pizza ready" << endl;
}

void makeDring() {
	cout << "Preparing frink" << endl;
	this_thread::sleep_for(chrono::seconds(1));
	cout << "drink is ready" << endl;
}
*/
mutex mtx;
void printChar(char ch, int count) {
	mtx.lock();
	for (int i = 0; i < count; i++) {
		cout << ch;
	}
	mtx.unlock();
}

int main()
{
	thread t1(printChar, "%", 50);

	thread t2(printChar, "*", 50);

	t1.join();
	t2.join();




	/*
	thread burger(cookBurger);
	thread pizza(cookPizza);
	thread fring(makeDring);

	burger.join();
	pizza.join();
	fring.join();

	cout << "Customer order completed!" << endl;
	*/



}

//
//int array1[] = { 1,2,3,4,5,6,7,8,9 };
//int array2[] = { 10,20,30,40,50,60,70,80,90 };
//
//thread t1(calculateSum, array1, 9);
//thread t2(calculateSum, array2, 9);
//
//t1.join();
//t2.join();
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
