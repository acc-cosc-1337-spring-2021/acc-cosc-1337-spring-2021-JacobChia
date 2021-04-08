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
	REQUIRE(ttc.get_winner() == "C");
}

TEST_CASE("Test first player set to X") {
	TicTacToe ttc;
	ttc.start_game("X");
	REQUIRE(ttc.get_player() == "X");
}

TEST_CASE("Test first player set to O") {
	TicTacToe ttc;
	ttc.start_game("O");
	REQUIRE(ttc.get_player() == "O");
}

TEST_CASE("Test win by first column") {
	TicTacToe ttc;
	ttc.start_game("X");

	ttc.mark_board(1);
	ttc.mark_board(2);
	ttc.mark_board(4);
	ttc.mark_board(5);
	ttc.mark_board(7);

	REQUIRE(ttc.game_over() == true);
}

TEST_CASE("Test win by second column") {
	TicTacToe ttc;
	ttc.start_game("X");

	ttc.mark_board(2);
	ttc.mark_board(1);
	ttc.mark_board(5);
	ttc.mark_board(6);
	ttc.mark_board(8);

	REQUIRE(ttc.game_over() == true);
}

TEST_CASE("Test win by third column") {
	TicTacToe ttc;
	ttc.start_game("X");

	ttc.mark_board(3);
	ttc.mark_board(2);
	ttc.mark_board(6);
	ttc.mark_board(4);
	ttc.mark_board(9);

	REQUIRE(ttc.game_over() == true);
}

TEST_CASE("Test win by first row") {
	TicTacToe ttc;
	ttc.start_game("X");

	ttc.mark_board(1);
	ttc.mark_board(4);
	ttc.mark_board(2);
	ttc.mark_board(5);
	ttc.mark_board(3);

	REQUIRE(ttc.game_over() == true);
}

TEST_CASE("Test win by second row") {
	TicTacToe ttc;
	ttc.start_game("X");

	ttc.mark_board(4);
	ttc.mark_board(1);
	ttc.mark_board(5);
	ttc.mark_board(3);
	ttc.mark_board(6);

	REQUIRE(ttc.game_over() == true);
}

TEST_CASE("Test win by third row") {
	TicTacToe ttc;
	ttc.start_game("X");

	ttc.mark_board(7);
	ttc.mark_board(2);
	ttc.mark_board(8);
	ttc.mark_board(4);
	ttc.mark_board(9);

	REQUIRE(ttc.game_over() == true);
}

TEST_CASE("Test win diagonally from top left") {
	TicTacToe ttc;
	ttc.start_game("X");

	ttc.mark_board(1);
	ttc.mark_board(2);
	ttc.mark_board(5);
	ttc.mark_board(3);
	ttc.mark_board(9);

	REQUIRE(ttc.game_over() == true);
}

TEST_CASE("Test win diagonally from bottom left") {
	TicTacToe ttc;
	ttc.start_game("X");

	ttc.mark_board(7);
	ttc.mark_board(2);
	ttc.mark_board(5);
	ttc.mark_board(4);
	ttc.mark_board(3);

	REQUIRE(ttc.game_over() == true);
}