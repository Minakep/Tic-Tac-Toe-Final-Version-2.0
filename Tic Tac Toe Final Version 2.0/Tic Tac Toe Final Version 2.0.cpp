#include<iostream>
#include<string>
#include<vector>

char table[9] = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };	// Array. This decides the values you see on the screen.
char current_marker;												// Variable.
int current_player;													// Variable.

void board()		// Function for the board.
{
	std::cout << table[0] << "   |   " << table[1] << "   |   " << table[2] << std::endl;
	std::cout << table[3] << "   |   " << table[4] << "   |   " << table[5] << std::endl;
	std::cout << table[6] << "   |   " << table[7] << "   |   " << table[8] << std::endl;
}

void swapplayerandmarker()		// Function to alternate between O and X, and player one and two.
{
	if (current_marker == 'X') current_marker = 'O';	// If the current marker is X, change it to O.
	else current_marker = 'X';							// If the current marker is not X, change it to X.

	if (current_player == 1) current_player = 2;		// Same as above but with player number instead.
	else (current_player = 1);
}


void choosesquare(int slot)			// Function for choosing a square.
{									// Since an array starts from 0, not 1, you have to subtract 
	int square = slot - 1;			//		1 from the number you enter to get the right square.
	table[square] = current_marker;	// Will place the marker that is currently selected.
}


int gamewon()					// Function to check if the game is won.
{								// When everything in a row, collumn or diagonal line equals the same, the game has been won.
								// Return current_player will either be 1 or 2 which comes in to play further down in the code
								// If none of the conditions has been fulfilled, then the return value is 0.
	if (table[0] == table[1] && table[1] == table[2]) return current_player;
	if (table[3] == table[4] && table[4] == table[5]) return current_player;
	if (table[6] == table[7] && table[7] == table[8]) return current_player;
	if (table[0] == table[3] && table[3] == table[6]) return current_player;
	if (table[1] == table[4] && table[4] == table[7]) return current_player;
	if (table[2] == table[5] && table[5] == table[8]) return current_player;
	if (table[0] == table[4] && table[4] == table[8]) return current_player;
	if (table[2] == table[4] && table[4] == table[6]) return current_player;


	return 0;
}

int main()
{
	std::cout << "Welcome to Tic Tac Toe!" << std::endl;
	std::cout << "To start the game, please have Player 1 choose X or O." << std::endl;
	std::cout << "(It has to be upper case.)" << std::endl;		// Generic friendly text.

	char playeronemarker;				// Option to choose whether you want to start the game with O or X.
	std::cin >> playeronemarker;		// Doesn't matter which you choose because of the swapplayerandmarker function.

	current_player = 1;					// Sets the first player as player 1, could have included the option to choose, but it would be kind of weird if the first player was player 2.
	current_marker = playeronemarker;	// Depending on the user is either x or O. Takes the users input and defines the starting value of current_marker.

	board();										// Prints the board under the text.


	int player_won;									// Variable

	for (int turns = 0; turns < 9; turns++)			// Loops 9 times.
	{
		std::cout << "Player " << current_player << ". Please chose a square.	";		// Generic text to inform the players of whoose turn it is.
		int slot;
		std::cin >> slot;							// Allowing the user to enter a number that later gets put in the choosesquare function, which choses the right square on the board

		choosesquare(slot);							// Calling the choosesquare function and running the users inout through it.

		board();									// Prints the "updated" board with the appropriate Xs and Os depending on the users inout and number of turns.

		player_won = gamewon();						// Defines the variable as the return value from the gamewon function.

		if (player_won == 1)						// If the return value from the gamewon function is equal to 1, player one has won the game and the loop breaks.
		{
			std::cout << "Congratulaations Player 1! You won the game!";
			break;
		}
		if (player_won == 2)						// Same as above, but with player 2 instead.
		{
			std::cout << "Congratulaations Player 2! You won the game!";
			break;
		}
		swapplayerandmarker();						// Calls the function to swap between player 1 and player 2, and X and O.

	}
	if (player_won == 0)							// If there have been 9 turns and the winning condition has not been fulfilled,
	{												// this would mean that the return value from the gamwon function is 0, the game ended in a draw.
		std::cout << "It's a draw! Which kind of means that you are both great at this game!" << std::endl;
	}

	return 0;
}