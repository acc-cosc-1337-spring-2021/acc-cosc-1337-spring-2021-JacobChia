//h
#include<string>
#include <vector>
#include <memory>
#include <fstream>
#include "tic_tac_toe.h"
using std::string;
using namespace std;
#ifndef _TTCD_H
#define _TTCD_H
class TicTacToeData {
    public:
        void save_games(const vector<unique_ptr<TicTacToe>>& games);
        vector<unique_ptr<TicTacToe>> get_games();
};
#endif