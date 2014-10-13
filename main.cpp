

#include <cstdlib>
#include <array>
#include <iostream>

#include "game_functions.h"

using namespace std;

// Function Template Definitions

/*
 * function introduces the game
 * 
 * PreConditions: none
 * 
 * PostCondition: output (to cout) describing the game
 */
void introduction();

/*
 * init : array<char, BOARD_SIZE>&
 * 
 * PreConditions: array has been declared
 * 
 * PostConditions: all array elements are set to UNUSED
 */
void init(array<char, BOARD_SIZE>& board);

/*
 * play : array<char, BOARD_SIZE>&, char, int&
 * 
 * PreConditions: array has been declared and has BOARD_SIZE
 *    character elements
 * 
 * PostCondition: the array element corresponding to the player's
 *    move has been changed to that player character;
 *    spacesUsed is increased by 1 (1 additional space used)
 */
void play(array<char, BOARD_SIZE>& board, char player, int& spacesUsed);

/*
 * show : array<char, BOARD_SIZE>
 * 
 * PreConditions: array has been declared and has BOARD_SIZE
 *    character elements
 * 
 * PostCondition: array has been output to cout
 */
void show(array<char, BOARD_SIZE> board);

/*
 * gameOver : array<char, BOARD_SIZE> board -> char
 * 
 * PreConditions: array has been declared and has BOARD_SIZE
 *    character elements
 * 
 * PostCondition: the winning player (char) is returned
 *    if that player has won (3-in-a-row horizontally,
 *    vertically, or diagonally);
 *    UNUSED is returned if neither player has won yet
 */
char gameOver(array<char, BOARD_SIZE> board);

/*
 * program plays the game of tic-tac-toe by alternating
 *   between two player ('X' and 'O')
 * for each player's turn, the player is allowed to
 *   choose an unused space and occupy it
 * the game is either when:
 *    all spaces are occupied, or
 *    once player gets 3-in-a-row (horizontally,
 *       vertically, or diagonally)
 */
int main(int argc, char** argv) {
    
    array<char, BOARD_SIZE> board;
    char currentPlayer = 'X';
    char gameResult = UNUSED;
    int spacesUsed = 0;
    
    introduction();
    
    init(board);
    
    show(board);
        
    do
    {
        cout << "\nIt is now " << currentPlayer
                << "'s turn:";
        
        play(board, currentPlayer, spacesUsed);
        
        show(board);
        
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        
        gameResult = gameOver(board);
    } while (gameResult == UNUSED && spacesUsed < BOARD_SIZE);
    
    if (gameResult == UNUSED)
        cout << "\nGame is a draw";
    else
        cout << "Congratulations, "
                << gameResult << ", you won the game!";

    return 0;
} // end main
