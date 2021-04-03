#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "tic_tac_toe.h"
#include <string>
using std::string;

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Test game over if 9 slots are selected.") {
	TicTacToe ttc;
	string player = "X";
	ttc.start_game(player);

	ttc.mark_board(1);
	ttc.mark_board(2);
	ttc.mark_board(3);
	ttc.mark_board(4);
	ttc.mark_board(5);
	ttc.mark_board(7);
	ttc.mark_board(6);
	ttc.mark_board(9);
	ttc.mark_board(8);
	REQUIRE(ttc.game_over() == true);
}