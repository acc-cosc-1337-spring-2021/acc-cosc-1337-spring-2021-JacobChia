#include<string>
#include <memory>
#include <vector>
#include "tic_tac_toe.h"
using std::string;
using namespace std;
class TicTacToeManager
{
    private:
        int x_win = 0;
        int o_win = 0;
        int ties = 0;
        vector<unique_ptr<TicTacToe>> games;
        void update_winner_count(string winner)
        {
            if (winner == "X")
                x_win++;
            else if (winner == "O")
                o_win++;
            else
                ties++;
        }
    public:
        void save_game(unique_ptr<TicTacToe> &b);
        void get_winner_total(int& o, int& w, int& t);
        friend ostream & operator << (ostream &out, const TicTacToeManager &manager);
};