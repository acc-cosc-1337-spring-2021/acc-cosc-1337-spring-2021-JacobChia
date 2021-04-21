#include "tic_tac_toe_4.h"
#include<string>
#include <vector>
#include <iostream>
using std::string;
using namespace std;

/*
class function check_column_win
Win by column if and return true if (each column index)
0, 1,  2,  3 
4, 5,  6,  7 
8, 9, 10, 11 
12,13,14, 15 
else
false
*/
bool TicTacToe4::check_column_win()
{
    string last = "X";
    if(get_player() == "X")
        last = "O";
    
    if(pegs[0] == last && pegs[4] == last && pegs[8] == last && pegs[12] == last)
        return true;
    
    if(pegs[1] == last && pegs[5] == last && pegs[9] == last && pegs[13] == last)
        return true;

    if(pegs[2] == last && pegs[6] == last && pegs[10] == last && pegs[14] == last)
        return true;

    if(pegs[3] == last && pegs[7] == last && pegs[11] == last && pegs[15] == last)
        return true;

    return false;
}



/*
class function check_row_win
Win by row if
0, 1,  2,  3 are equal
4, 5,  6,  7 are equal
8, 9, 10, 11 are equal 
12,13,14, 15 are equal
*/
bool TicTacToe4::check_row_win()
{
    string last = "X";
    if(get_player() == "X")
        last = "O";
    
    if(pegs[0] == last && pegs[1] == last && pegs[2] == last && pegs[3] == last)
        return true;
    
    if(pegs[6] == last && pegs[4] == last && pegs[5] == last && pegs[7] == last)
        return true;

    if(pegs[10] == last && pegs[11] == last && pegs[8] == last && pegs[9] == last)
        return true;

    if(pegs[12] == last && pegs[13] == last && pegs[14] == last && pegs[15] == last)
        return true;

    return false;
}


/*
class function check_diagonal_win
Win diagonally
0, 1,  2,  3
4, 5,  6,  7
8, 9, 10, 11
12,13,14, 15

*/
bool TicTacToe4::check_diagonal_win()
{
    string last = "X";
    if(get_player() == "X")
        last = "O";

    if(pegs[0] == last && pegs[5] == last && pegs[10] == last && pegs[15] == last)
        return true;
    
    if(pegs[3] == last && pegs[6] == last && pegs[9] == last && pegs[12] == last)
        return true;

    return false;
}