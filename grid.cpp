#include "grid.h"
#include <iostream>
#include <iomanip>
#include <sstream>
using namespace std;



/******************************************************
  1) Tic-Tac-Toe Helper Functions
******************************************************/
void grid::initializeGrid()
{
	for (int i = 0; i < 3; i++)//Rows
	{
		for (int j = 0; j < 3; j++)//Columns
		{
			spaces location;
			gridSpacesCount++;

			location.posNum = gridSpacesCount;
			location.data = (gridSpacesCount + '0');
			chartArray[i][j] = location;
		}
	}
}

void grid::display()
{
	cout << "-----------\n";
	cout << chartArray[0][0].data << setw(3) << "| " << chartArray[0][1].data << setw(4) << "| " << chartArray[0][2].data << endl;
	cout << "--" << setw(3) << "|----|---\n";
	cout << chartArray[1][0].data << setw(3) << "| " << chartArray[1][1].data << setw(4) << "| " << chartArray[1][2].data << endl;
	cout << "--" << setw(3) << "|----|---\n";
	cout << chartArray[2][0].data << setw(3) << "| " << chartArray[2][1].data << setw(4) << "| " << chartArray[2][2].data << endl;
	cout << "-----------\n";
}


/***************************************************************
  2) Search Algorithms for locating specific spaces on the board
***************************************************************/

int grid::rowSearch(int userInput)
{
	if (userInput - 3 <= 0)
		return 0;
	else if (userInput - 3 > 0 && userInput - 3 < 4)
		return 1;
	else if (userInput - 3 >= 4)
		return 2;
}

int grid::colSearch(int row, int userInput)
{

	if (chartArray[row][0].posNum == userInput)
		return 0;
	else if (chartArray[row][1].posNum == userInput)
		return 1;
	else if (chartArray[row][2].posNum == userInput)
		return 2;
}

/******************************************************
3) Conditions that ends the game
******************************************************/

bool grid::winByHorziontalLine(char p, int prevInput)
{
	int row = rowSearch(prevInput);
	if (chartArray[row][0].data == p && chartArray[row][1].data == p && chartArray[row][2].data == p)
	{
		cout << "Player '" << p << "' has won with a horziontal line\n";
		return true;
	}
	else
		return false;
}

bool grid::winByVerticalLine(char p, int prevInput)
{
	int row = rowSearch(prevInput);
	int col = colSearch(row, prevInput);

	if (chartArray[0][col].data == p && chartArray[1][col].data == p && chartArray[2][col].data == p)
	{
		cout << "Player '" << p << "' has won with a vertical line\n";
		return true;
	}
	else
		return false;
}

bool grid::winByDiagonalLine(char p)
{
	if (chartArray[0][0].data == p && chartArray[1][1].data == p && chartArray[2][2].data == p)
	{
		cout << "Player '" << p << "' has won with a diagonal line\n";
		return true;
	}
	else if (chartArray[0][2].data == p && chartArray[1][1].data == p && chartArray[2][0].data == p)
	{
		cout << "Player '" << p << "' has won with a diagonal line\n";
		return true;
	}
	else
		return false;
}

bool grid::stalement()
{
	if (numOfTakenSpots == 9)
	{
		cout << "The game ended in a stalement\n";
		return true;
	}
	else
		return false;
}

