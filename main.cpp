/*Author: BinaryBills
Creation Date: April 28, 2021
Modifcation Date: May 3, 2021
Purpose: The purpose of this program is to make Tic-Tac-Toe. The player can choose to play against another human, play against a bot, or watch two bots play. 
*/

#include <iostream>
#include "grid.h"
#include "pvp.h"
using namespace std;

void menu();
void playerVsAI(int);
void playerVsplayer(int);
void botVerusBot(int);

int main()
{
	cout << "*************************************************\n";
	cout << "* ------> Welcome to my TicTacToe game! <------ *\n";
	cout << "*************************************************\n\n";
	menu();
	system("pause");
	return 0;
}

void menu()
{
	/*********************************************************
		---------- > The Program's Main Menu <----------
	*********************************************************/

	char choice;
	bool resumeGame = true;
	int currPlayerTurn = 0; //This variable is used to decide which player turn it is.

	while (resumeGame)
	{
		cout << "-----------------------------------------------\n";
		cout << "Main Menu Options\n";
		cout << "-----------------------------------------------\n";
		cout << "1) Player VS Player\n";
		cout << "2) Player VS AI (Easy)\n";
		cout << "3) AI (Easy) VS AI (Easy)\n";
		cout << "4) Exit\n";
		cout << "-----------------------------------------------\n\n";

		cout << "Choose an option: ";
		cin >> choice;

		switch (choice)
		{
		case '1':
			cout << "The Player Verus Player match has began!\n";
			playerVsplayer(currPlayerTurn);
			cout << endl;
			break;
		case '2':
			cout << endl;
			cout << "The Player verus AI match has began!\n";
			playerVsAI(currPlayerTurn);
			break;
		case '3':
			cout << "The AI Verus AI match has began!\n";
			botVerusBot(currPlayerTurn);
			break;
		case '4':
			cout << endl;
			cout << "Thanks for playing my game! Exiting now...\n";
			resumeGame = false;
			break;
		default:
			cout << "Invalid Choice. \n";
			cout << "Choose again: ";
			cin >> choice;
			break;
		}
	}
}

/*Author: BinaryBills
Creation Date: April 28, 2021
Modifcation Date: May 3, 2021
Purpose: This function defines the conditions needed for a player versus an AI match to operate correctly. With each loop, the currPlayerTurn value increments, which decides which player's turn it is. The AI will
choose a randomly generated number within the range of 1-10.*/


void playerVsAI(int currPlayerTurn)
{
	pvp game;
	int userInput;
	
	game.display();
	srand(time(NULL));

	while (game.didPlayerWin() == false && game.didGameEndInStalement() == false)
	{
		currPlayerTurn++;

		cout << "-----------------------------------------------\n\n";
		if (currPlayerTurn % 2 != 0)
		{
			cout << "[Turn " << currPlayerTurn << "] Please choose a location on the grid Player '" << 'X' << "': ";
			cin >> userInput;
			game.playerTurn('X', userInput);
		}
		else
		{
			system("pause");
			int randInput = (rand() % 9 + 1);
			cout << "[Turn " << currPlayerTurn << "] The AI '" << 'O' << "' has chosen the location: " << game.AITEasyTurn(randInput, 'O') << endl;
			cout << endl;
			game.display();
		}
		cout << endl;
	}
}

/*Author: BinaryBills
Creation Date: April 28, 2021
Modifcation Date: May 3, 2021
Purpose: This function defines the conditions needed for a player verus player match to operate correctly. With each loop, the currPlayerTurn value increments, which decides which player's turn it is. T
*/


void playerVsplayer(int currPlayerTurn)
{
	pvp game;
	int userOneInput;
	int userTwoInput;

	game.display();
	srand(time(NULL));

    while(game.didPlayerWin() == false && game.didGameEndInStalement() == false)
	{
		currPlayerTurn++;

		cout << "-----------------------------------------------\n\n";
		if (currPlayerTurn % 2 != 0)
		{
			cout << "[Turn " << currPlayerTurn << "] Please choose a location on the grid Player '" << 'X' << "': ";
			cin >> userOneInput;
			game.playerTurn('X' , userOneInput);
		}
		else
		{
			cout << "[Turn " << currPlayerTurn << "] Please choose a location on the grid Player '" << 'O' << "': ";
			cin >> userTwoInput;
			game.playerTurn('O', userTwoInput);
		}
	}
}

/*Author: BinaryBills
Creation Date: April 28, 2021
Modifcation Date: May 3, 2021
Purpose: This function defines the conditions needed for an AI verus another AI match to operate correctly. With each loop, the currPlayerTurn value increments, which decides which player's turn it is. The AI will
choose a randomlu generated number within the range of 1-10.
*/
void botVerusBot(int currPlayerTurn)
{
	pvp game;
	game.display();
	srand(time(NULL));

	while (game.didPlayerWin() == false && game.didGameEndInStalement() == false)
	{
		int randInput = (rand() % 9 + 1);
		currPlayerTurn++;

		cout << "-----------------------------------------------\n\n";
	
		if (currPlayerTurn % 2 != 0)
		{
			cout << "[Turn " << currPlayerTurn << "] The AI '" << 'X' << "' has chosen the location: " << game.AITEasyTurn(randInput, 'X') << endl;
			game.display();
			game.checkIfWon('X', randInput);
		}
		else
		{
			cout << "[Turn " << currPlayerTurn << "] The AI '" << 'O' << "' has chosen the location: " << game.AITEasyTurn(randInput,'O') << endl;
			game.display();
			game.checkIfWon('O', randInput);
		}
		
		system("pause");
		cout << endl;
	}
}