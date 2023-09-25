/*
Julio Garcia
Instructor: Lucian Silcox
Date: 05/10/2023

Program: This is the DeckStack header file containing
the function prototypes for Deck.cpp

*/

#ifndef DECK_H
#define DECK_H

#include <string>
#include "YGOCard.h"

class DeckStack
{
	private:
		YGOCard *cards;  // Objects the array stores
		int size;   // Size of the array
		int top = 0;        // Tracks top of stack

	public:
		// Constructor and Destructor for DeckStack()
		DeckStack(int);
		~DeckStack();

		// Function Definitions
		void push(YGOCard);
		void pop(YGOCard*&);
		bool isEmpty();
		void loadDeck();
		void displayDeck();
		void swap(YGOCard&, YGOCard&);
		void shuffleDeck();

		// Classes for exceptions
		class UnderflowException
		{
		public:
			std::string err_msg = "Error: Attempted Underflow.";
		};

		class OverflowException
		{
		public:
			std::string err_msg = "Error: Attempted Overflow.";
		};
		
};


#endif