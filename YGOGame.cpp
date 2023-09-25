/*
Julio Garcia
Instructor: Lucian Silcox
Date: 05/10/2023

Program: This is a menu-driven program that allows the player
to play against a computer in a speed duel variant of Yu-Gi-Oh!
Each player draws a card from the top of the deck and battle it 
out with their monsters. The deck is a stack that decrements and
shuffles with each turn, making every game random.

*/

#include <iostream>
#include <string>
#include "DeckStack.h"
#include "YGOCard.h"

using namespace std;

// Function Protoypes
void menu();
void gameMenu();
void vsDisplay(YGOCard* &p, YGOCard* &c);
void calculateLifePoints(YGOCard* &p, YGOCard* &c, int &lp, int &cp);
void checkWinner(int &lp, int &lc, int &gameChoice, DeckStack &cards);

int main()
{
	// Instantiate cards for player's draws
	YGOCard* player = new YGOCard();
	YGOCard* computer = new YGOCard();

	int choice = 0; // Variable to hold user input
	int gameChoice = 0;

	while (choice != 3)
	{
		// Variable holding players lifePoints
		// Declared in while loop, so life points 
		// reset when in the main menu.
		int lpScore1 = 2000;
		int lpScore2 = 2000;

		bool reDraw = false; // flag to keep track of reDraw option.

		// gameChoice variable is reset
		int gameChoice = 0;

		// Function call for loadDeck()
		// Deck is reloaded from text file when
		// in main menu to reset the game.
		// Instantiate a DeckStack of YGOCard Objects
		int count = 20;
		DeckStack cards(count);
		cards.loadDeck();

		// Function call for menu().
		menu();
		cin >> choice; 

		switch (choice)
		{
			case 1:
			{
				while (gameChoice != 4)
				{
					cout << endl;

					// Function call for gameMenu()
					gameMenu();
					cin >> gameChoice;

					// Function call for shuffleDeck(), makes the pool random each turn with cards 
					cards.shuffleDeck();

					switch (gameChoice)
					{
						case 1:
						{
							cout << endl;
						
							if (player->getAttack() != 0)
							{
								cout << "You already drew a card!" << endl;
								
								break;
							}
							else 
							{
								// Each player draws from the top of the deck.
								// the pop() function takes on card off the stack for each
								// draw.
								cards.pop(player);
								cards.pop(computer);

								// Checks if the stack is empty declares winner to whoever has the most 
								// life points remaining.
								checkWinner(lpScore1, lpScore2, gameChoice, cards);

								// Display the card drawn
								cout << player->toString() << endl;

								// Function call for shuffleDeck(), makes the pool random each turn with cards 
								cards.shuffleDeck();

								break;
							}
							
						}
						case 2:
						{
							cout << endl;
							if (player->getAttack() == 0)
							{
								cout << "Draw a new card!" << endl;
								break;
							}
							else
							{
								// Function calls for vsDisplay(), caculateLifePoints(), and checkWinner()
								vsDisplay(player, computer);
								calculateLifePoints(player, computer, lpScore1, lpScore2);
								checkWinner(lpScore1, lpScore2, gameChoice, cards);

								// Reset cards to constructor defaults
								player = new YGOCard();
								computer = new YGOCard();
								
								break;
							}
						}
						case 3:
						{
							cout << endl;
							// Checks flag to see if redraw was already used. 
							if (reDraw == false)
							{
								// If redraw turns out to be false, player draws new card.
								cards.pop(player);

								checkWinner(lpScore1, lpScore2, gameChoice, cards);
								// Display the card drawn
								cout << player->toString() << endl;
								
								// Function call for shuffleDeck(), makes the pool random each turn with cards 
								cards.shuffleDeck();

								reDraw = true;
								break;
							}
							else
							{
								cout << "You already used your redraw!" << endl;
							}

							break;
						}
						default:
						{
							break;
						}
					}
					
				}
				
				break;
			}
			case 2:
			{
				// Function call for displayDeck()
				cout << endl;
				cards.displayDeck();
				break;
			}
			default:
			{
				break;
			}

		}
	}

	system ("pause");
	return 0;
}

// Function Definition for menu()
void menu()
{
	cout << "***********************************" << endl;
	cout << "|           Main Menu             |" << endl;
	cout << "| 1) Duel Against the Computer    |" << endl;
	cout << "| 2) Display Deck                 |" << endl;
	cout << "| 3) Quit Game                    |" << endl;
	cout << " >> ";
}

// Function Definition for gameMenu()
void gameMenu()
{
	cout << "***********************************" << endl;
	cout << "|           Duel Menu             |" << endl;
	cout << "| 1) Draw a Card                  |" << endl;
	cout << "| 2) Battle                       |" << endl;
	cout << "| 3) One Time ReDraw              |" << endl;
	cout << "| 4) Return to Main Menu          |" << endl;
	cout << " >> ";
}
// Function vsDisplay()
void vsDisplay(YGOCard* &p, YGOCard* &c)
{
	// Check which card had strong attack.
	if (p->getAttack() > c->getAttack())
	{
		// Print vs screen format
		cout << p->getName() << " " << p->getAttack() << " vs " << c->getName() << " " << c->getAttack() << endl;
		cout << c->getName() << " was Destroyed!!!" << endl;
	}
	else if(p->getAttack() < c->getAttack())
	{
		// Print vs screen format
		cout << p->getName() << " " << p->getAttack() << " vs " << c->getName() << " " << c->getAttack() << endl;
		cout << p->getName() << " was Destroyed!!!" << endl;
	}
	else
	{
		// Print vs screen format
		cout << p->getName() << " " << p->getAttack() << " vs " << c->getName() << " " << c->getAttack() << endl;
		cout << "Both Monsters were Destroyed!!!" << endl;
	}
	cout << endl;
}

// Function definition for checkRound()
void calculateLifePoints(YGOCard* &p, YGOCard* &c, int &lp, int &lc)
{
	// Variable to hold the calculation
	int difference;

	// Check which card had strong attack.
	if (p->getAttack() > c->getAttack())
	{
		// Calcuate new life points score
		difference = p->getAttack() - c->getAttack();
		lc = lc - difference;

		// Print current score.
		cout << "Life Points" << endl;
		cout << "Player: " << lp << endl;
		cout << "Computer: " << lc << endl;
	}
	else if (p->getAttack() < c->getAttack())
	{
		// Calcuate new life points score
		difference = c->getAttack() - p->getAttack();
		lp = lp - difference;

		// Print current score.
		cout << "Life Points" << endl;
		cout << "Player: " << lp << endl;
		cout << "Computer: " << lc << endl;
	}
	else
	{
		// Calcuations for draws
		difference = c->getAttack() - p->getAttack();
		lp = lp - difference;
		lc = lc - difference;
		
		// Print current score.
		cout << "Life Points" << endl;
		cout << "Player: " << lp << endl;
		cout << "Computer: " << lc << endl;
	}
	cout << endl;
}

// Function for checkWinner()
void checkWinner(int &lp, int &lc, int &gameChoice, DeckStack &cards)
{
	// Conditional statements verifying winners
	if (lp <= 0)
	{
		cout << "Computer Wins...Better Luck Next Time." << endl;
		gameChoice = 4;
	}
	else if (lc <= 0)
	{
		cout << "Player Wins!!!" << endl;
		gameChoice = 4;
	}
	else if (cards.isEmpty())
	{
		if (lp > lc)
		{
			cout << "Player Wins!!!" << endl;
			gameChoice = 4;
		}
		else if (lp < lc)
		{
			cout << "Computer Wins...Better Luck Next Time." << endl;
			gameChoice = 4;
		}
		else
		{
			cout << "It's a Draw!!!" << endl;
			gameChoice = 4;
		}
	}
	else
		return;

}