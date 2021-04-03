//h
#include<string>
#include <vector>
using std::string;
using namespace std;
class TicTacToe
{
    private:
        void set_next_player();
        bool check_board_full();
        void clear_board();
        string player;
        vector<string> pegs;
    public:
        bool game_over();
        void start_game(string first_player);
        void mark_board(int position);
        string get_player();
        void display_board();
};