// multithreadingspace.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>

using namespace std;

bool rocketPadisincharge = false;

bool blabort = false;

mutex consoleMutex;

void printLine() {
    cout << "======================================================" << endl;
}

void rocketOne() {
    printLine();
    {
        std::lock_guard<std::mutex> lock(consoleMutex);
        cout << "Preparing to launch Rocket 1" << endl;
    }
    this_thread::sleep_for(chrono::seconds(1));
    {
        std::lock_guard<std::mutex> lock(consoleMutex);
        cout << "Fuel checks are green" << endl;
    }
    this_thread::sleep_for(chrono::seconds(1));
    {
        std::lock_guard<std::mutex> lock(consoleMutex);
        cout << "Atmospheric conditions accounted for" << endl;
    }
    this_thread::sleep_for(chrono::seconds(1));
    {
        std::lock_guard<std::mutex> lock(consoleMutex);
        cout << "Dynotherms connected" << endl;
        cout << "Ready for launch" << endl;
        cout << "Launch in 3" << endl;
    }
    this_thread::sleep_for(chrono::seconds(1));
    {
        std::lock_guard<std::mutex> lock(consoleMutex);
        cout << "Launch in 2" << endl;
    }
    this_thread::sleep_for(chrono::seconds(1));
    {
        std::lock_guard<std::mutex> lock(consoleMutex);
        cout << "Launch in 1" << endl;
    }
    this_thread::sleep_for(chrono::seconds(1));
    {
        std::lock_guard<std::mutex> lock(consoleMutex);
        cout << "We have liftoff!" << endl;
    }
    cout << "Launch 1 successful, transfering control to the rocket launch pad" << endl;
    cout << "Press ENTER to abort the mission" << endl;

    this_thread::sleep_for(chrono::seconds(3));
    rocketPadisincharge = true;
}

void nextRocket() {

    while (!rocketPadisincharge) {
        this_thread::sleep_for(chrono::milliseconds(500));
    }

    for (int i = 2; i < 11; i++) {
        if (blabort == true) {
            cout << "abort command recieved. Shutting down rocket launchpad" << endl;
            break;
        }
        {
            std::lock_guard<std::mutex> lock(consoleMutex);
            cout << "Preparing to launch Rocket " << i << endl;
        }
        this_thread::sleep_for(chrono::seconds(1));
        {
            std::lock_guard<std::mutex> lock(consoleMutex);
            cout << "Fuel checks are green" << endl;
        }
        this_thread::sleep_for(chrono::seconds(1));
        {
            std::lock_guard<std::mutex> lock(consoleMutex);
            cout << "Atmospheric conditions accounted for" << endl;
        }
        this_thread::sleep_for(chrono::seconds(1));
        {
            std::lock_guard<std::mutex> lock(consoleMutex);
            cout << "Dynotherms connected" << endl;
            cout << "Ready for launch" << endl;
            cout << "Launch in 3" << endl;
        }
        this_thread::sleep_for(chrono::seconds(1));
        {
        std::lock_guard<std::mutex> lock(consoleMutex);
        cout << "Launch in 2" << endl;
        }
        this_thread::sleep_for(chrono::seconds(1));
        {
            std::lock_guard<std::mutex> lock(consoleMutex);
            cout << "Launch in 1" << endl;
        }
        this_thread::sleep_for(chrono::seconds(1));
        {
            std::lock_guard<std::mutex> lock(consoleMutex);
            cout << "We have liftoff!" << endl;
        }
        this_thread::sleep_for(chrono::seconds(3));
    }

}


int main()
{
    thread t1(rocketOne);
    thread t2(nextRocket);

    cin.get();
    {
        std::lock_guard<std::mutex> lock(consoleMutex);

        cout << endl;
        cout << "OVERRIDE PRESSED" << endl;
        cout << "ABORTING MISSION" << endl;

    }
    
    blabort = true;

    t1.join();
    t2.join();
}

