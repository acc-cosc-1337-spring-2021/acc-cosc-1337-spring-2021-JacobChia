#include "tic_tac_toe_3.h"
#include<string>
#include <vector>
#include <iostream>
using std::string;
using namespace std;


/*
class function check_column_win
Win by column if and return true if
0,3, and 6 are equal
1, 4, and 7
2, 5, and 8
else
false
*/

bool TicTacToe3::check_column_win()
{
    string last = "X";
    if(get_player() == "X")
        last = "O";
    
    if(pegs[0] == last && pegs[3] == last && pegs[6] == last)
        return true;
    
    if(pegs[1] == last && pegs[4] == last && pegs[7] == last)
        return true;

    if(pegs[2] == last && pegs[5] == last && pegs[8] == last)
        return true;

    return false;
}

/*
class function check_row_win
Win by row if
0, 1, 2 are equal
3,4,5 are equal
6,7,8 are equal
*/
bool TicTacToe3::check_row_win()
{
    string last = "X";
    if(get_player() == "X")
        last = "O";
    
    if(pegs[0] == last && pegs[1] == last && pegs[2] == last)
        return true;
    
    if(pegs[3] == last && pegs[4] == last && pegs[5] == last)
        return true;

    if(pegs[6] == last && pegs[7] == last && pegs[8] == last)
        return true;

    return false;
}


/*
class function check_diagonal_win
Win diagonally
0 1 2
3 4 5
6 7 8

*/
bool TicTacToe3::check_diagonal_win()
{
    string last = "X";
    if(get_player() == "X")
        last = "O";

    if(pegs[0] == last && pegs[4] == last && pegs[8] == last)
        return true;
    
    if(pegs[2] == last && pegs[4] == last && pegs[6] == last)
        return true;

    return false;
}