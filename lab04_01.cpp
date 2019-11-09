/*
Student Name: Chamod Gamage
Student Number:  20830088
SYDE 121 Lab: 04
Assignment: 01
Filename: lab04_01.cpp
I hereby declare that this code, submitted for credit for the course SYDE121,
is a product of my own efforts.  This coded solution has not been plagiarized
from other sources and has not been knowingly plagiarized by others.
Project:  TIC TAC TOE
Purpose:  Run a text-based two-player tic tac toe game
Due Date: Tuesday, October 22, 2019
*/

/*
Testing:
The program was run over a dozen times
User input system was not broken by any invalid input (non-integers, non-empty cells, integers out-of-bounds, etc.)
Ties were recorded correctly
Diagonal wins were recorded correctly
Row and column wins were recorded correctly
Final statistics were aggregated correctly
*/

#include <iostream>
#include <string>
#include <numeric>

using namespace std;

void run_tic_tac_toe();
// PURPOSE: Begins the simulation of a 4x4 tic tac toe game with multiple rounds and outputs statistics when user decides to exit
// INPUTS: None
// RETURNS: Outputs final statistics to console upon exit

int run_round(char PLAYER_ONE, char PLAYER_TWO);
// PURPOSE: Runs a round of 4x4 tic-tac-toe and returns the resulting winner (or tie)
// INPUTS: player_one (char containing player to go first in given round (X or O))
//         player_two (char containing player to go second in given round(X or O))
// RETURNS: Outputs result of round to console and returns results as int to function call (0 for X, 1 for O, 2 for tie)

bool check_placement(const string USER_INPUT, const int CURRENT_BOARD[4][4]);
// PURPOSE: Determines whether user has inputted valid location for X or O placement given current state of board
// INPUTS: user_input (string containing what user has inputted to the console when asked for position to place X or O)
//         current_board (2D 4x4 int array containing current state of board (split by row and then cell) 
//						  with -1 representing X, 1 representing O, and 0 representing an empty cell)
// RETURNS: Returns true if an X or an O can be placed in the position entered by the user

char check_board_result(int CURRENT_BOARD[4][4]);
// PURPOSE: Determines whether the game has resulted in a win for a player or a tie given the current state of the board
// INPUTS:  current_board (2D 4x4 int array containing current state of board (split by row and then cell) 
//						  with -1 representing X, 1 representing O, and 0 representing an empty cell)
// RETURNS: Returns X if X has won, O if O has won, T if board is full with no winner (a tie), and N if game is not over yet

void display_board(int CURR_BOARD[4][4]);
// PURPOSE: Outputs tic-tac-toe board to console as a 4x4 grid of positions numbered 1-16
// INPUTS: curr_board (2D 4x4 int array containing current state of board (split by row and then cell) 
//					  with -1 representing X, 1 representing O, and 0 representing an empty cell)
// RETURNS: Outputs tic-tac-toe board to console as a 4x4 grid of positions numbered 1-16

void display_final_stats(int RESULT_TALLY[3]);
// PURPOSE: Outputs final statistics of series of 4x4 tic-tac-toe rounds (# of wins per player and ties)
// INPUTS: result_tally (int array containing number of wins by player X, number of wins by player O, and number of ties, in that order)
// RETURNS: Outputs final statistics to console in text format

bool check_full_board(int CURRENT_BOARD_STATE[4][4]);
// PURPOSE: Determines whether board has been filled up with no winner (a tie)
// INPUTS: current_board)state (2D 4x4 int array containing current state of board (split by row and then cell) 
//						  with -1 representing X, 1 representing O, and 0 representing an empty cell)
// RETURNS: Returns true if board is filled with X and O but none in a series of 4








int main()
{
	run_tic_tac_toe();
	return 0;

}

void run_tic_tac_toe() {

	//SETUP
	int results[3] = { 0,0,0 }; //Array containing wins for X, wins for O, and ties (in that order)
	bool play_again = true; //bool representing whether user would like to play game again (first game starts automatically)
	bool x_first = true; //bool representing whether player X goes first in a given game (alternates every game)
	string input; //string used multiple times to hold user input values
	

	//PROCESSING
	cout << "WELCOME TO 4X4 TIC-TAC-TOE!";
	while (play_again == true) {

		cout << "\n Game #" << results[0] + results[1] + results[2] + 1 << ":\n"; //Outputs game number for reference
		
		//Runs the round (depending on which player is to have the first turn) and records the result in the result array
		if (x_first) { 
			results[run_round('X', 'O')]++;
		}
		else {
			results[run_round('O', 'X')]++;
		}



		x_first = !x_first; //Switches player turns

		//Continues to next round if user wants to play again; exits out of loop if not
		cout << "To play again, enter y. To exit, enter anything else.\n";
		input = "";
		cin >> input;
		cout << "********************************************************";
		if (input != "y") {
			play_again = false;
		}
	}

	//OUTPUT
	cout << "\nThanks for playing. Here are your final statistics.";
	display_final_stats(results); //Calls function to print final statistics to console
	
}

int run_round(char PLAYER_ONE, char PLAYER_TWO) {

	//SETUP
	int board[4][4] = { {0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0} }; //Array containing each row of board 
	//																(each row an array with -1 representing X, 0 representing empty, and 1 representing O)
	string input; //string used multiple times to hold user input values
	char curr_player = PLAYER_ONE; //char containing the player whose turn it is (X or O)
	int position; //int representing position where user would like to place marker



	//PROCESSING
	display_board(board); //Display initial state of board to console

	while (check_board_result(board) == 'N') { //Loop runs while game is still unfinished
		
		

		do { //Do-while loop ensuring that user inputs valid location for marker
			
			cout << "\nSelect valid position to place " << curr_player << ".\n";
			cin >> input;


		} while (check_placement(input, board) == false);

		position = stoi(input); //Converting user input to integer for marker placement

		if (curr_player == 'X') { //Places X marker at given position if it is X's turn
			board[int((position - 1) / 4)][(position-1) % 4] = -1;
		}
		else { //Places O at given position if it is O's turn
			board[int((position - 1) / 4)][(position-1) % 4] = 1;
		}

		display_board(board); //Displays new state of board


		//Switch player
		if (curr_player == PLAYER_ONE) {
			curr_player = PLAYER_TWO;
		}
		else {
			curr_player = PLAYER_ONE;
		}

	}

	//OUTPUT
	//Outputs result of round to console, and returns corresponding value to location of function call
	if (check_board_result(board) == 'X') {
		cout << "\nPLAYER X HAS WON THIS ROUND!\n";
		return 0;
	} 
	else if (check_board_result(board) == 'O') {
		cout << "\nPLAYER O HAS WON THIS ROUND!\n";
		return 1;
	}
	else {
		cout << "\nIT'S A TIE!\n";
		return 2;
	}
	

}

void display_board(int CURR_BOARD[4][4]) {

	//SETUP
	int position = 0; //int representing position within board corresponding to position within nested for loops below

	//PROCESSING & OUTPUT
	cout << "\n";


	for (int row = 0; row < 4; row++) {
		for (int cell = 0; cell < 4; cell++) {
			
			position += 1;

			if (CURR_BOARD[row][cell] == 0) { //Prints location of cell if it's empty
				cout << position << "    ";
				if (position < 10) {
					cout << " ";
				}
			}

			else if (CURR_BOARD[row][cell] == 1) { //Prints O when O marker is at this location
				cout << "O     ";
			}

			else { //Prints X since X marker must be at this location (process of elimination)
				cout << "X     ";
			}
		}
		cout << "\n";

	}
}

bool check_placement(const string USER_INPUT, const int CURRENT_BOARD[4][4]) {

	//SETUP
	int location; //Location of marker placement to be checked for validity

	//PROCESSING & OUTPUT


	if (USER_INPUT.length() > 2) { //Ensures input is string of length less than two
		return false;
	}
	else if (USER_INPUT.length() > 0 && !(isdigit(USER_INPUT[0]))) { //Ensures first char in string is a digit
		return false;
	}
	else if (USER_INPUT.length() == 2 && !(isdigit(USER_INPUT[1]))) { //Ensures second char in string is a digit (if applicable)
		return false;
	}

	location = stoi(USER_INPUT); //Since user input can be converted to a two-digit number, it is converted as such

	if (location < 1 || location > 16) { //Ensures user input was a number in range [1,16] (inclusive)
		return false;
	}

	if (CURRENT_BOARD[int((location - 1) / 4)][(location-1) % 4] != 0) { //Ensures location is empty
		return false;
	}

	//Location is valid
	return true;
	
	

}

char check_board_result(int CURRENT_BOARD[4][4]) {

	//SETUP
	int row_sum[4] = { 0,0,0,0 }; //Will contain sum of values in each row
	int column_sum[4] = { 0,0,0,0 }; //Will contain sum of values in each column

	

	//PROCESSING

	//Check diagonals for sum of 4 (O wins) or -4 (X wins)
	if (CURRENT_BOARD[0][0] + CURRENT_BOARD[1][1] + CURRENT_BOARD[2][2] + CURRENT_BOARD[3][3] == 4 ||
		CURRENT_BOARD[0][3] + CURRENT_BOARD[1][2] + CURRENT_BOARD[2][1] + CURRENT_BOARD[3][0] == 4) {

		return('O');
	}
	else if (CURRENT_BOARD[0][0] + CURRENT_BOARD[1][1] + CURRENT_BOARD[2][2] + CURRENT_BOARD[3][3] == -4 ||
		CURRENT_BOARD[0][3] + CURRENT_BOARD[1][2] + CURRENT_BOARD[2][1] + CURRENT_BOARD[3][0] == -4) {


		return('X');
	}

	//Add up sums for rows and columns
	for (int row = 0; row < 4; row++) {
		for (int cell = 0; cell < 4; cell++) {
			row_sum[row] += CURRENT_BOARD[row][cell];
			column_sum[cell] += CURRENT_BOARD[row][cell];
			
		}

		//Check for row sum of -4 or 4
		if (row_sum[row] == 4) {
			
			return('O');
		}
		else if (row_sum[row] == -4) {
			
			return('X');
		}
	
	}

	//Check for column sum of 4 or -4
	for (int column = 0; column < 4; column++) {
		if (column_sum[column] == 4) {

			return('O');
		}
		else if (column_sum[column] == -4) {

			return('X');
		}

	}

	//Check for tie
	if (check_full_board(CURRENT_BOARD)) {
		return('T');
	}

	//Game is not complete
	return('N');
		
}

bool check_full_board(int CURRENT_BOARD_STATE[4][4]) {

	//PROCESSING AND OUTPUT

	//For loop iterates through board cells checking for empty cell
	for (int row = 0; row < 4; row++) {
		for (int cell = 0; cell < 4; cell++) {
			if (CURRENT_BOARD_STATE[row][cell] == 0) {
				return false;
			}
		}
	}

	//Board is full
	return true;

}

void display_final_stats(int RESULT_TALLY[3]) {


	//OUTPUT
	cout << "\nWins by player X: " << RESULT_TALLY[0];
	cout << "\nWins by player Y: " << RESULT_TALLY[1];
	cout << "\nTies:             " << RESULT_TALLY[2];


}