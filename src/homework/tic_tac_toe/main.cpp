#include<string>
#include <vector>
#include <iostream>
#include "tic_tac_toe.h"
#include "tic_tac_toe_manager.h"
#include "tic_tac_toe_3.h"
#include "tic_tac_toe_4.h"
#include "tic_tac_toe_data.h"
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
	TicTacToeData data;
	TicTacToeManager manager = TicTacToeManager(data);
	unique_ptr<TicTacToe> ttc;

	cout << "Enter 3 or 4: ";
	int game_type;
	cin >> game_type;
	while (game_type != 3 && game_type != 4) {
		cout << "Has to be 3 or 4. Enter 3 or 4: ";
		cin >> game_type;
	}

	if (game_type == 3) {
		ttc = make_unique<TicTacToe3>();
	} else {
		ttc = make_unique<TicTacToe4>();
	}

	ttc->start_game(player);
	cout << ttc;
	
	int o_win = 0;
	int x_win = 0;
	int tie = 0;

	while(true) {
		cin >> ttc;
		cout << ttc;

		if(ttc->game_over()) {
			cout << "Winner: " + ttc->get_winner() + "\n";
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
				if (game_type == 3) {
					ttc = make_unique<TicTacToe3>();
				} else {
					ttc = make_unique<TicTacToe4>();
				}

				ttc->start_game(player);
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