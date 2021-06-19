#pragma once
#include "grid.h"
using namespace std;

/*Author: BinaryBills
Creation Date: April 28, 2021
Modifcation Date: May 5, 2021
Purpose: This header file allows each player to make their selection on the board and checks if they won. Moreover, it also ensures that the player inputted a valid character. 
*/

class pvp :public grid
{
protected:
	bool winner = false;
	bool tie = false;

public:

	pvp();

/******************************************************
   1) Allows User/Bot to select a position on the board
******************************************************/

	void playerTurn(char, int);
	int AITEasyTurn(int, char);

/******************************************************
   2) Validate User Input
******************************************************/
	int validateUserInputIsWithinBounds(int);
	

/******************************************************
	3) Game-Ending Conditions
******************************************************/
	void checkIfWon(char, int);
	bool didPlayerWin() { return winner; }
	bool didGameEndInStalement() { return tie; }
};
