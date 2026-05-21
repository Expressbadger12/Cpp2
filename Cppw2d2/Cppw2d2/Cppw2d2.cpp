// Cppw2d2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

class GameStructure {
    
};

class Character : public GameStructure {
    int health;
};


int main()
{

}


/*
Using Classes
    
    Create a class called GameStructure.

Using Abstraction
    
    If you have not already, then, create one private property called Health in the Character superclass. (Encapsulation)
    
    Create getter and setter public methods in the superclass to access and update this private Health property. (Abstraction)
    
    In the setter method check health before setting the value, if the new Health value will be less than zero, then set the property Health to zero and display "Character has Expired..." to the screen.

Using Polymorphism
    
    Create a second method named Talk using Overloading Polymorphism in the Character class.
    
    Give this new other Talk this method signature:  void Talk(string name, string stuffToSay)
    
    Make both Talk methods say their name then stuff to say.
    
    Create a virtual attack method in the Character class that returns 10 hit points.
    
    Create an override attack method in both subclasses of the Character class using Overriding Polymorphism and set their attack return values at 25 hit points.

Abstraction

    Create a pure virtual method called Help in the GameStructure class. (Abstraction)
    
    Override the Help method in the Character class.
    
    Override the Help method in both character classes.
*/

