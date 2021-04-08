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
        string winner;
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

        bool check_column_win()
        {
            string last = "X";
            if(player == "X")
                last = "O";
            
            if(pegs[0] == last && pegs[3] == last && pegs[6] == last)
                return true;
            
            if(pegs[1] == last && pegs[4] == last && pegs[7] == last)
                return true;

            if(pegs[2] == last && pegs[5] == last && pegs[8] == last)
                return true;

            return false;
        }

        bool check_row_win()
        {
            string last = "X";
            if(player == "X")
                last = "O";
            
            if(pegs[0] == last && pegs[1] == last && pegs[2] == last)
                return true;
            
            if(pegs[3] == last && pegs[4] == last && pegs[5] == last)
                return true;

            if(pegs[6] == last && pegs[7] == last && pegs[8] == last)
                return true;

            return false;
        }
        
        bool check_diagonal_win()
        {
            string last = "X";
            if(player == "X")
                last = "O";

            if(pegs[0] == last && pegs[4] == last && pegs[8] == last)
                return true;
            
            if(pegs[2] == last && pegs[4] == last && pegs[6] == last)
                return true;

            return false;
        }

        void set_winner()
        {
            if(player == "X")
                winner = "O";
            else
                winner = "X";
        }

    public:
        bool game_over();

        void start_game(string first_player);

        void mark_board(int position);

        string get_player();

        void display_board();

        string get_winner();
};

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

string TicTacToe::get_player()
{
    return player;
}

string TicTacToe::get_winner()
{
    return winner;
}