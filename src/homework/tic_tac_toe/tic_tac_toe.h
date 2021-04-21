#include<string>
#include <vector>
#include <memory>
#include <iostream>
using std::string;
using namespace std;
#ifndef _TTC_H
#define _TTC_H
class TicTacToe
{
    protected:
        vector<string> pegs;
        virtual bool check_column_win()
        {
            return false;
        }

        virtual bool check_row_win()
        {
            return false;
        }

        virtual bool check_diagonal_win()
        {
            return false;
        }
    private:
        string player;
        string winner;
        void set_next_player()
        {
            if(get_player() == "X") {
                player = "O";
            } else {
                player = "X";
            } 
        }

        bool check_board_full()
        {
            for (auto it = pegs.begin(); it != pegs.end(); ++it) {
                if (*it == " ") {
                    return false;
                }
            }
            return true;
        }

        void clear_board()
        {
            for (auto it = pegs.begin(); it != pegs.end(); ++it) {
                *it = " ";
            }
        }

        void set_winner()
        {
            if(player == "X")
                winner = "O";
            else
                winner = "X";
        }
    public:
        TicTacToe(int size);
        bool game_over();
        void start_game(string first_player);
        void mark_board(int position);
        string get_player();
        string get_winner();
        friend ostream & operator << (ostream &out, const unique_ptr<TicTacToe> &t);
        friend istream & operator >> (istream &in, unique_ptr<TicTacToe> &t);
};
#endif