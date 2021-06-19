#pragma once

/*Author: BinaryBills
Creation Date: April 28, 2021
Modifcation Date: May 5, 2021
Purpose: This header file encapsulates the essential features of a tic-tac-toe grid and includes search algorithms for locating specific spaces on the board.
Furthermore, this header file also defines the conditions required for a tic-tac-toe game to end(Player wins or a tie ensues).
*/

struct spaces
{
	int posNum; //There is a total of nine spaces on a 3x3 Grid. This variable keeps track of the exact space number of each object.
	char data;
	bool isTaken;
};

class grid
{
protected:
	spaces chartArray[3][3];
	int gridSpacesCount = 0;
	int numOfTakenSpots = 0;

public:
/******************************************************
	  1) Tic-Tac-Toe Helper Functions
******************************************************/
	void initializeGrid();
	void display();

/***************************************************************
  2) Search Algorithms for locating specific spaces on the board
***************************************************************/
	int rowSearch(int);
	int colSearch(int, int);

/******************************************************
 3) Conditions that ends the game
******************************************************/
	bool winByHorziontalLine(char, int);
	bool winByVerticalLine(char, int);
	bool winByDiagonalLine(char);
	bool stalement();
};

