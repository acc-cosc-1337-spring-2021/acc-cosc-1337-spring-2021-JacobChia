//h
#include<string>
#include <vector>
#include "tic_tac_toe.h"
using std::string;
using namespace std;
#ifndef _TTC3_H
#define _TTC3_H
class TicTacToe3: public TicTacToe {
    private:
        bool check_column_win();

        bool check_row_win();

        bool check_diagonal_win();
    public:
        TicTacToe3():TicTacToe(3){};
};
#endif