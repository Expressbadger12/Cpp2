// week11.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

template<typename T>
class student {
private:
	T studentID;
	string studentName;
public:
	student(T id, string name) {
		studentID = id;
		studentName = name;
	}
	void display() {
		cout << "Student ID" << studentID << endl;
		cout << "Name " << studentName << endl;
	}
};

//int findMax(int first, int second) {
//	if (first > second) {
//		return first;
//	}
//	else if (first == second) {
//		cout << "Numbers are equal";
//		return 0;
//	}
//	else {
//		return second;
//	}
//}

//template<typename T> 
//T findmax(T first, T second) {
//	if (first > second)
//		return first;
//	else
//		return second;
//} 

int main()
{
//	cout << "Maximum Value: " << findMax(15, 20) << endl;

	//cout << findmax(20, 50);
	//cout << findmax(136, 55);
	//cout << findmax("\x24", "Z");

	//cout << "\x24";

	student<int> student1(100, "Miceal");
	student1.display();
}
