//h
#include<string>
#include <vector>
#include "tic_tac_toe.h"
using std::string;
using namespace std;
#ifndef _TTC4_H
#define _TTC4_H
class TicTacToe4: public TicTacToe {
    private:
        bool check_column_win();

        bool check_row_win();

        bool check_diagonal_win();
    public:
        TicTacToe4():TicTacToe(4){};
        TicTacToe4(vector<string> p, string winner):TicTacToe(p, winner){};
};
#endif