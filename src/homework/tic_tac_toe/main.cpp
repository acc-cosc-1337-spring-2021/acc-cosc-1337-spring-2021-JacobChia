#include<string>
#include <vector>
#include <iostream>
#include "tic_tac_toe.h"

using std::string;
using namespace std;

int main() 
{
	string player = "";
	string con = "";

	cout << "Enter X or O: ";
	cin >> player;
	while(player != "X" && player != "O") {
		cout << "Has to be X or O. Enter X or O: ";
		cin >> player;
	}

	TicTacToe ttc;
	ttc.start_game(player);
	ttc.display_board();
	int pos;
	while(true) {
		cout << "Enter position from 1 to 9: ";
		cin >> pos;
		ttc.mark_board(pos);
		ttc.display_board();

		if(ttc.game_over()) {
			cout << "Winner: " + ttc.get_winner() + "\n";
			cout << "Do you want to quit? Enter Y or N: ";
			cin >> con;

			if(con == "N") {
				cout << "Game restart.\n";
				ttc.start_game(player);
				ttc.display_board();
			} else {
				break;
			}
		}
	}
	cout << "Game over.\n";

	return 0;
}