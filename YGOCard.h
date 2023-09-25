/*
Julio Garcia
Instructor: Lucian Silcox
Date: 05/10/2023

Program: This is the YGOCard header file containing
the function prototypes for YGOCard.cpp

*/

#ifndef YGOCARD_H
#define YGOCARD_H

#include <string>

class YGOCard
{
	private:
		std::string name;
		int attack;
		int defense;
		
	public:
		// Default Constructor and Destructor
		YGOCard();
		~YGOCard();

		// Overrloaded Constructor
		YGOCard(std::string, int, int);

		// Accessors and Mutators
		std::string getName();
		void setName(std::string);

		int getAttack();
		void setAttack(int);

		int getDefense();
		void setDefense(int);

		// Prototype for toString function
		std::string toString() const;
};

#endif