#include<string>
#include <vector>
#include <iostream>
#include "tic_tac_toe.h"

using std::string;
using namespace std;

int main() 
{
	string player = "";
	cout << "Enter X or O: ";
	cin >> player;

	TicTacToe ttc;
	ttc.start_game(player);
	ttc.display_board();
	int pos;
	while(ttc.game_over() == false) {
		cout << "Enter position from 1 to 9: ";
		cin >> pos;
		ttc.mark_board(pos);
		ttc.display_board();
	}
	cout << "Game over.\n";

	return 0;
}