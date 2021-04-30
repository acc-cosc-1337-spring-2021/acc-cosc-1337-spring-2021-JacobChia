#include<string>
#include <vector>
#include <iostream>
#include <memory>
#include "tic_tac_toe.h"
using std::string;
using namespace std;

TicTacToe::TicTacToe(int size)
{
    size *= size;
    for (int i=0;i<size;i++) {
        pegs.push_back(" ");
    }
}

TicTacToe::TicTacToe(vector<string> p, string win)
{
    pegs = p;
    winner = win;
}

bool TicTacToe::game_over()
{
    if (check_row_win() || check_column_win() || check_diagonal_win()) {
        set_winner();
        return true;
    }

    if(check_board_full()) {
        winner = "C";
        return true;
    }

    return false;
}

void TicTacToe::start_game(string first_player)
{
    player = first_player;
    clear_board();
}

void TicTacToe::mark_board(int position)
{
    pegs[position - 1] = player;
    set_next_player();
}

istream & operator >> (istream &in, unique_ptr<TicTacToe> &t)
{
    int pos;
    if (t->pegs.size() == 9) {
        cout << "Enter position from 1 to 9: ";
        cin >> pos;
        t->mark_board(pos);
    } else {
        cout << "Enter position from 1 to 16: ";
        cin >> pos;
        t->mark_board(pos);
    }
    return in;
}

ostream & operator << (ostream &out, const unique_ptr<TicTacToe> &t)
{
    int idx = 0;
    if (t->pegs.size() == 9) {
        for (auto it = t->pegs.begin(); it != t->pegs.end(); ++it) {
            cout << *it;
            if(idx % 3 != 2) {
                cout << "|";
            } else {
                cout << "\n";
            }
            idx++;
        }
    } else {
        for (auto it = t->pegs.begin(); it != t->pegs.end(); ++it) {
            cout << *it;
            if(idx % 4 != 3) {
                cout << "|";
            } else {
                cout << "\n";
            }
            idx++;
        }
    }
    return out;
}

string TicTacToe::get_player()
{
    return player;
}

string TicTacToe::get_winner()
{
    return winner;
}

vector<string> const TicTacToe::get_pegs()
{
    return pegs;
}