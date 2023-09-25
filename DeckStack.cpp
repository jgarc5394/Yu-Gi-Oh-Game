/*
Julio Garcia
Instructor: Lucian Silcox
Date: 05/10/2023

Program: This is the DeckStack.cpp file containing
the function defintions for DeckStack.h

*/

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "YGOCard.h";
#include "DeckStack.h";


// Default Constructor and Destructor
DeckStack::DeckStack(int s)
{
	size = s;
	cards = new YGOCard[size];
}

DeckStack::~DeckStack() {};

// Function Definitions for utility functions
void DeckStack::push(YGOCard c)
{
	// Check if stack is full comparing top to size
	if (top == size)
	{
		try 
		{
			throw OverflowException();
		}
		catch (OverflowException ex)
		{
			std::cout << std::endl;
			std::cout << ex.err_msg << std::endl;
		}
	}
	// Assigns object to top of the stack
	cards[top] = c;
}

void DeckStack::pop(YGOCard* &card)
{
	// Check top for underflow
	if (top == 0)
	{
		// throw the UnderflowException() and print an
		// appropriate Error message.
		try
		{
			throw UnderflowException();
		}
		catch (UnderflowException ex)
		{
			std::cout << std::endl;
			std::cout << ex.err_msg << std::endl;
		}
	}
	else
	{
		// Set Attributes to address pointer variable card.
		card->setName(cards[top - 1].getName());
		card->setAttack(cards[top - 1].getAttack());
		card->setDefense(cards[top - 1].getDefense());

		top--; // Decrement top.
	}
}

bool DeckStack::isEmpty()
{
	// Checks top value to see if stack is empty
	if (top == 0)
		return true;
	else
		return false;
}

// This function loads the deck with card data from a text file.
void DeckStack::loadDeck()
{
	// Open file with read only access
	std::ifstream input;
	input.open("Cards.txt");
	int temp; 

	// Check if file was opened, if not then close program
	if (!input)
	{
		std::cout << "Failure to open file -- Cards.txt" << std::endl;
		exit(0);
	}
	else
	{
		std::string line; // Variable used to hold each line.
		
		while (std::getline(input, line))
		{
			YGOCard c; 

			c.setName(line);
			// Read next line and store in temp int variable
			getline(input, line);
			temp = stoi(line);
			// Store temp in attack attribute
			c.setAttack(temp);

			getline(input, line);
			temp = stoi(line);

			c.setDefense(temp);
			
			push(c);

			top++;
		}
	}
	input.close(); // closes file stream
}

void DeckStack::displayDeck()
{
	// Iterates through stack and prints formatted output
	// by calling YGOCard toString function.
	for (int i = top - 1; i >= 0; i--)
	{
		std::cout << cards[i].toString() << std::endl;
	}
}

void DeckStack::swap(YGOCard &c1, YGOCard &c2)
{
	// Swaps values 
	YGOCard temp = c1;
	c1 = c2;
	c2 = temp;
}

void DeckStack::shuffleDeck()
{
	// seed the random generator
	srand(time(0));

	// Assign x so modulo operator result is between 0 and 19
	int x = top - 1;
	
	// Iterate through stack swapping random values
	for (int i = x; i >= 0; i--)
	{
		int j = rand() % (i + 1);

		// Function call for swap.
		swap(cards[i], cards[j]);
	}
}
