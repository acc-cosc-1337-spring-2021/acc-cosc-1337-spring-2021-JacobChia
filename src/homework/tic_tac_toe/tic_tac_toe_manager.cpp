#include<string>
#include <vector>
#include <iostream>
#include "tic_tac_toe_manager.h"
using std::string;
using namespace std;

TicTacToeManager::TicTacToeManager(TicTacToeData &d)
{
    data = d;
    games = data.get_games();
}

TicTacToeManager::~TicTacToeManager()
{
    data.save_games(games);
}

void TicTacToeManager::save_game(unique_ptr<TicTacToe> &b)
{
    update_winner_count(b->get_winner());
    games.push_back(move(b));
    
}

ostream & operator << (ostream &out, const TicTacToeManager &manager)
{
    for (auto it = manager.games.begin(); it != manager.games.end(); ++it) {
        cout << *it;
    }

    return out;
}

void TicTacToeManager::get_winner_total(int& o, int& w, int& t)
{
    o = o_win;
    w = x_win;
    t = ties;
}