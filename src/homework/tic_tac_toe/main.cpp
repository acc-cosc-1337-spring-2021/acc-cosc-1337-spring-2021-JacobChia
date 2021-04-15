#include<string>
#include <vector>
#include <iostream>
#include "tic_tac_toe_manager.h"

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
	TicTacToeManager manager;
	TicTacToe ttc;
	ttc.start_game(player);
	cout << ttc;
	
	int o_win = 0;
	int x_win = 0;
	int tie = 0;

	while(true) {
		cin >> ttc;
		cout << ttc;

		if(ttc.game_over()) {
			cout << "Winner: " + ttc.get_winner() + "\n";
			manager.save_game(ttc);
			
			manager.get_winner_total(o_win, x_win, tie);
			cout << "Wins:\n";
			cout << "O: ";
			cout << o_win;
			cout << ", X: ";
			cout << x_win;
			cout << ", Ties: ";
			cout << tie;
			cout << "\n";

			cout << "Do you want to quit? Enter Y or N: ";
			cin >> con;

			if(con == "N") {
				cout << "Game restart.\n";
				ttc.start_game(player);
				cout << ttc;
			} else {
				break;
			}
		}
	}
	cout << "Game over.\n";
	cout << manager;

	return 0;
}