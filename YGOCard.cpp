/*
Julio Garcia
Instructor: Lucian Silcox
Date: 05/10/2023

Program: This is the YGOCard.cpp file containing
the function defintions for YGOCard.h

*/

#include <string>
#include <iostream>
#include <sstream>
#include "YGOCard.h";

using namespace std;

// Default Constructor
YGOCard::YGOCard()
{
	name = "None";
	attack = 0;
	defense = 0;
}

// Default Destructor
YGOCard::~YGOCard() {};

// Overloaded Constructor
YGOCard::YGOCard(string n, int a, int d)
{
	name = n;
	attack = a;
	defense = d;
}

// Function Definitions for Accessors/Mutators
string YGOCard::getName()
{
	return name;
}

void YGOCard::setName(string n)
{
	name = n;
}

int YGOCard::getAttack()
{
	return attack;
}

void YGOCard::setAttack(int a)
{
	attack = a;
}

int YGOCard::getDefense()
{
	return defense;
}

void YGOCard::setDefense(int d)
{
	defense = d;
}

// Function Definition for toString()
string YGOCard::toString()const
{
	// Declare string stream object for formatted output.
	ostringstream output;

	output << "Monster Name: " << name << "\n" << "Attack: " << attack
		   << "\n" << "Defense: " << defense << endl;

	return output.str();
}