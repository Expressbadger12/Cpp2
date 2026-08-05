// mutexlamnda.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>

using namespace std;

mutex mtx;

void writeOnBoard(string name) {
    mtx.lock();
    cout << name << " is writing on the board." << endl;
    for (int i = 1; i <= 5; i++) {
        cout << name << " writes line " << i << endl;
    }
    cout << name << " finished writing" << endl;
    mtx.unlock();
}

//parking garage: only one car can enter the parking garage at a time
void enterGarage(string car) {
    mtx.lock();
    cout << car << " enters the garage." << endl;
    cout << car << " parks successfully." << endl;
    mtx.unlock();
}

int main()
{

    thread car1(enterGarage, "Red Sonata");
    thread car2(enterGarage, "Blue Ford");
    thread car3(enterGarage, "Grey Honda");

    car1.join();
    car2.join();
    car3.join();


    auto greet = []() {
        cout << "Welcome to C++2 lambda" << endl;
        };

    greet();
    //thread student1(writeOnBoard, "Micheal");
    //thread student2(writeOnBoard, "Alice");
    ////do not forget to join

    //student1.join();
    //student2.join();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
