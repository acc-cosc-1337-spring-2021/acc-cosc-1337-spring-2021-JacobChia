#include<string>
#include <vector>
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
        string get_winner();
        friend ostream & operator << (ostream &out, const TicTacToe &t);
        friend istream & operator >> (istream &in, TicTacToe &t);
};