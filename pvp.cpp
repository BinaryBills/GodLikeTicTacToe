#include "grid.h"
#include "pvp.h"
#include <iostream>

pvp::pvp()
{
	initializeGrid();
}


/******************************************************
   1) Determine which player turn it is
******************************************************/


void pvp::playerTurn(char symbol, int userInput)
{
	userInput = validateUserInputIsWithinBounds(userInput); //Validates the user's input
	int row = rowSearch(userInput); //Returns Row that the user input was found in and stores it into row variable
	int col = colSearch(row, userInput); //Returns Col that the user input was found in and stores it into col variable

	if (chartArray[row][col].isTaken == true)
	{
		cerr << "The position that you specified has already been filled" << endl;
		cin >> userInput;
		playerTurn(symbol, userInput);
	}

//If it is not taken, the player can place their symbol onto that position. 
	else
	{
		chartArray[row][col].data = symbol;
		chartArray[row][col].isTaken = true;
		numOfTakenSpots++;
		display();
		checkIfWon(symbol, userInput);
	}
}

int pvp::AITEasyTurn(int randInput, char player)
{
	int row = rowSearch(randInput); //Returns row that the AI picked
	int col = colSearch(row, randInput); //Returns col that the AI picked

	if (chartArray[row][col].isTaken == true) //If it is taken, the random number generator will choose another number
	{
		randInput = (rand() % 9 + 1);
		AITEasyTurn(randInput, player);
	} 
	else //If it is not taken, the AI will place its symbol onto the position. 
	{
		chartArray[row][col].data = player;
		chartArray[row][col].isTaken = true;
		numOfTakenSpots++;
		return randInput;
	}
}

/******************************************************
   2) Validate User Input
******************************************************/

int pvp::validateUserInputIsWithinBounds(int userInput)
{
	while (cin.fail() || userInput <= 0 || userInput > 9)
	{
		cin.clear();
		cin.ignore(256, '\n');
		cerr << "ERROR: HAS TO BE BETWEEN 1-9" << endl;
		cout << "Enter a valid number: ";
		cin >> userInput;
	}
	return userInput;
}

/******************************************************
	3) Game-Ending Conditions
******************************************************/

void pvp::checkIfWon(char p, int userInput)
{
	if (winByHorziontalLine(p, userInput) == true)
		winner = true;
	else if (winByVerticalLine(p, userInput) == true)
		winner = true;
	else if (winByDiagonalLine(p) == true)
		winner = true;
	else if (stalement() == true)
		tie = true;
	else
		winner = false;
}