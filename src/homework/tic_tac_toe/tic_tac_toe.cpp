#include<string>
#include <vector>
#include <iostream>
using std::string;
using namespace std;
class TicTacToe
{
    private:
        string player;
        vector<string> pegs;
        void set_next_player()
        {
            if(player == "X") {
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

    public:
        bool game_over();

        void start_game(string first_player);

        void mark_board(int position);

        string get_player()
        {
            return player;
        }

        void display_board();
};

bool TicTacToe::game_over()
{
    return check_board_full();
}

void TicTacToe::start_game(string first_player)
{
    player = first_player;
    pegs = {" ", " ", " ", " ", " ", " ", " ", " ", " "};
    clear_board();
}

void TicTacToe::mark_board(int position)
{
    pegs[position - 1] = player;
    set_next_player();
}

void TicTacToe::display_board()
{
    int idx = 0;
    for (auto it = pegs.begin(); it != pegs.end(); ++it) {
        cout << *it;
        if(idx % 3 != 2) {
            cout << "|";
        } else {
            cout << "\n";
        }
        idx++;
    }
}