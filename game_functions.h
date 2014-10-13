

#include <array>
#include <iostream>
#include <cmath>

using namespace std;

// Global Constants

const int BOARD_SIZE = 9;   // # of places on the board
const int BOARD_LEN = 3;    // length of one side of tha board
const char UNUSED='-';

/*
 *
 * introduction
 *
 * function introduces the game
 * 
 * PreConditions: none
 * 
 * PostCondition: output (to cout) describing the game
 *
 * FUNCTION STUB: CODE MUST BE ADDED
 */
	void introduction()
	{
		cout << "Welcome to the game of tic-tac-toe"
			<< "\nThis is a 2-player game that alternates\n between X and O (X goes first)\n\n";

	}
/*
 * init : array<char, BOARD_SIZE>&
 *
 * function initializes the given (referenced) array
 * 
 * PreConditions: array has been declared
 * 
 * PostConditions: all array elements are set to UNUSED
 *
 * FUNCTION STUB: CODE MUST BE ADDED
 */
	void init(array<char, BOARD_SIZE>& board)
	{
		board[0] = '1';
		board[1] = '2';
		board[2] = '3';
		board[3] = '4';
		board[4] = '5';
		board[5] = '6';
		board[6] = '7';
		board[7] = '8';
		board[8] = '9';

	}

/*
 * play : array<char, BOARD_SIZE>&, char, int&
 *
 * function allows the given player ('X' or 'O') to
 *  play one move of the game
 * function keeps prompting for a move as long as player:
 *    enters a move outside range {1, ..., 9}
 *    enter a move already played
 * 
 * PreConditions: array has been declared and has BOARD_SIZE
 *    character elements
 * 
 * PostCondition: the array element corresponding to the player's
 *    move has been changed to that player character;
 *    spacesUsed is increased by 1 (1 additional space used)
 *
 * FUNCTION STUB: CODE MUST BE ADDED
 */
		void play(array<char, BOARD_SIZE>& board, char player, int& spacesUsed)
		{
			int move;

			do
			{
			cout << "What space do you wish to occupy (1...9) ";
			cin >> move;
			} while(move < 1 || move > 9 || board[move -1] == 'X' || board[move - 1] == 'O'); //end while

			board[move - 1] = player;
			spacesUsed ++;
		}

/*
 * show : array<char, BOARD_SIZE>
 *
 * function outputs the given board (array) to the screen
 *  as a 3x3 grid (SEE SAMPLE OUTPUT)
 * 
 * PreConditions: array has been declared and has BOARD_SIZE
 *    character elements
 * 
 * PostCondition: array has been output to cout
 *
 * FUNCTION STUB: CODE MUST BE ADDED
 */
		void show(array<char, BOARD_SIZE> board)
		{
			cout << "\n " << board[0] << " " << board[1] << " " << board[2];
			cout << "\n " << board[3] << " " << board[4] << " " << board[5];
			cout << "\n " << board[6] << " " << board[7] << " " << board[8];
			cout << endl;
		}

/*
 * gameOver : array<char, BOARD_SIZE> board -> char
 *
 * function determines whether the game is over:
 *   if the game is over winning player ('X' or 'O')
 *     is returned
 *   otherwise, UNUSED is returned
 * 
 * PreConditions: array has been declared and has BOARD_SIZE
 *    character elements
 * 
 * PostCondition: the winning player (char) is returned
 *    if that player has won (3-in-a-row horizontally,
 *    vertically, or diagonally);
 *    UNUSED is returned if neither player has won yet
 *
 * FUNCTION STUB: CODE MUST BE ADDED
 */
		char gameOver(array<char, BOARD_SIZE> board)
		{
			if(board[0]==board[1] && board[0]==board[2])
			{
				return board[0];
			}
			else if(board[3]==board[4] && board[3]==board[5])
			{
				return board[3];
			}
			else if(board[6]==board[7] && board[6]==board[8])
			{
				return board[6];
			}
			else if(board[0]==board[3] && board[0]==board[6])
			{
				return board[1];
			}
			else if(board[1]==board[4] && board[1]==board[7])
			{
				return board[1];
			}
			else if(board[2]==board[5] && board[2]==board[8])
			{
				return board[2];
			}
			else if(board[0]==board[4] && board[0]==board[8])
			{
				return board[0];
			}
			else if(board[2]==board[4] && board[2]==board[6])
			{
				return board[4];
			}
			else 
			{
				return UNUSED;
			}
					
			
		}
