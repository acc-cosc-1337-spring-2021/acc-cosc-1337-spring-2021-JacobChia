#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "tic_tac_toe_manager.h"
#include <memory>
#include "tic_tac_toe_3.h"
#include "tic_tac_toe_4.h"
#include <string>
using std::string;

TEST_CASE("Test game over if 9 slots are selected.") {
	unique_ptr<TicTacToe> ttc;
	ttc = make_unique<TicTacToe3>();
	string player = "X";
	ttc->start_game(player);

	ttc->mark_board(1);
	ttc->mark_board(2);
	ttc->mark_board(3);
	ttc->mark_board(4);
	ttc->mark_board(5);
	ttc->mark_board(7);
	ttc->mark_board(6);
	ttc->mark_board(9);
	ttc->mark_board(8);
	REQUIRE(ttc->game_over() == true);
	REQUIRE(ttc->get_winner() == "C");
}

TEST_CASE("Test first player set to X") {
	unique_ptr<TicTacToe> ttc;
	ttc = make_unique<TicTacToe3>();
	ttc->start_game("X");
	REQUIRE(ttc->get_player() == "X");
}

TEST_CASE("Test first player set to O") {
	unique_ptr<TicTacToe> ttc;
	ttc = make_unique<TicTacToe3>();
	ttc->start_game("O");
	REQUIRE(ttc->get_player() == "O");
}

TEST_CASE("Test win by first column") {
	unique_ptr<TicTacToe> ttc;
	ttc = make_unique<TicTacToe3>();
	ttc->start_game("X");

	ttc->mark_board(1);
	ttc->mark_board(2);
	ttc->mark_board(4);
	ttc->mark_board(5);
	ttc->mark_board(7);

	REQUIRE(ttc->game_over() == true);
}

TEST_CASE("Test win by second column") {
	unique_ptr<TicTacToe> ttc;
	ttc = make_unique<TicTacToe3>();
	ttc->start_game("X");

	ttc->mark_board(2);
	ttc->mark_board(1);
	ttc->mark_board(5);
	ttc->mark_board(6);
	ttc->mark_board(8);

	REQUIRE(ttc->game_over() == true);
}

TEST_CASE("Test win by third column and get winner function") {
	unique_ptr<TicTacToe> ttc;
	ttc = make_unique<TicTacToe3>();
	ttc->start_game("X");

	ttc->mark_board(3);
	ttc->mark_board(2);
	ttc->mark_board(6);
	ttc->mark_board(4);
	ttc->mark_board(9);

	REQUIRE(ttc->game_over() == true);
	REQUIRE(ttc->get_winner() == "X");
}

TEST_CASE("Test win by first row") {
	unique_ptr<TicTacToe> ttc;
	ttc = make_unique<TicTacToe3>();
	ttc->start_game("X");

	ttc->mark_board(1);
	ttc->mark_board(4);
	ttc->mark_board(2);
	ttc->mark_board(5);
	ttc->mark_board(3);

	REQUIRE(ttc->game_over() == true);
}

TEST_CASE("Test win by second row") {
	unique_ptr<TicTacToe> ttc;
	ttc = make_unique<TicTacToe3>();
	ttc->start_game("X");

	ttc->mark_board(4);
	ttc->mark_board(1);
	ttc->mark_board(5);
	ttc->mark_board(3);
	ttc->mark_board(6);

	REQUIRE(ttc->game_over() == true);
}

TEST_CASE("Test win by third row") {
	unique_ptr<TicTacToe> ttc;
	ttc = make_unique<TicTacToe3>();
	ttc->start_game("X");

	ttc->mark_board(7);
	ttc->mark_board(2);
	ttc->mark_board(8);
	ttc->mark_board(4);
	ttc->mark_board(9);

	REQUIRE(ttc->game_over() == true);
}

TEST_CASE("Test win diagonally from top left") {
	unique_ptr<TicTacToe> ttc;
	ttc = make_unique<TicTacToe3>();
	ttc->start_game("X");

	ttc->mark_board(1);
	ttc->mark_board(2);
	ttc->mark_board(5);
	ttc->mark_board(3);
	ttc->mark_board(9);

	REQUIRE(ttc->game_over() == true);
}

TEST_CASE("Test win diagonally from bottom left") {
	unique_ptr<TicTacToe> ttc;
	ttc = make_unique<TicTacToe3>();
	ttc->start_game("X");

	ttc->mark_board(7);
	ttc->mark_board(2);
	ttc->mark_board(5);
	ttc->mark_board(4);
	ttc->mark_board(3);

	REQUIRE(ttc->game_over() == true);
}

TEST_CASE("Test TicTacToe Manager") {
	TicTacToeManager manager;
	unique_ptr<TicTacToe> ttc;
	ttc = make_unique<TicTacToe3>();

	ttc->start_game("X");
	ttc->mark_board(7);
	ttc->mark_board(2);
	ttc->mark_board(5);
	ttc->mark_board(4);
	ttc->mark_board(3);
	REQUIRE(ttc->game_over() == true);
	manager.save_game(ttc);

	ttc = make_unique<TicTacToe3>();
	ttc->start_game("X");
	ttc->mark_board(7);
	ttc->mark_board(2);
	ttc->mark_board(5);
	ttc->mark_board(4);
	ttc->mark_board(3);
	REQUIRE(ttc->game_over() == true);
	manager.save_game(ttc);

	ttc = make_unique<TicTacToe3>();
	ttc->start_game("X");
	ttc->mark_board(7);
	ttc->mark_board(2);
	ttc->mark_board(5);
	ttc->mark_board(4);
	ttc->mark_board(3);
	REQUIRE(ttc->game_over() == true);
	manager.save_game(ttc);
	int x, o, t;
	manager.get_winner_total(o, x, t);
	REQUIRE(x == 3);
}

// for size 4*4
TEST_CASE("Test game over if 9 slots are selected. 4") {
	unique_ptr<TicTacToe> ttc;
	ttc = make_unique<TicTacToe4>();
	string player = "X";
	ttc->start_game(player);

	ttc->mark_board(1);
	ttc->mark_board(2);
	ttc->mark_board(3);
	ttc->mark_board(4);
	ttc->mark_board(8);
	ttc->mark_board(7);
	ttc->mark_board(6);
	ttc->mark_board(5);
	ttc->mark_board(9);
	ttc->mark_board(10);
	ttc->mark_board(11);
	ttc->mark_board(12);
	ttc->mark_board(13);
	ttc->mark_board(14);
	ttc->mark_board(15);
	ttc->mark_board(16);
	REQUIRE(ttc->game_over() == true);
	REQUIRE(ttc->get_winner() == "C");
}

TEST_CASE("Test first player set to X 4") {
	unique_ptr<TicTacToe> ttc;
	ttc = make_unique<TicTacToe4>();
	ttc->start_game("X");
	REQUIRE(ttc->get_player() == "X");
}

TEST_CASE("Test first player set to O 4") {
	unique_ptr<TicTacToe> ttc;
	ttc = make_unique<TicTacToe4>();
	ttc->start_game("O");
	REQUIRE(ttc->get_player() == "O");
}

TEST_CASE("Test win by first column 4") {
	unique_ptr<TicTacToe> ttc;
	ttc = make_unique<TicTacToe4>();
	ttc->start_game("X");

	ttc->mark_board(1);
	ttc->mark_board(2);
	ttc->mark_board(5);
	ttc->mark_board(3);
	ttc->mark_board(9);
	ttc->mark_board(4);
	ttc->mark_board(13);

	REQUIRE(ttc->game_over() == true);
}

TEST_CASE("Test win by second column 4") {
	unique_ptr<TicTacToe> ttc;
	ttc = make_unique<TicTacToe4>();
	ttc->start_game("X");

	ttc->mark_board(2);
	ttc->mark_board(1);
	ttc->mark_board(6);
	ttc->mark_board(3);
	ttc->mark_board(10);
	ttc->mark_board(4);
	ttc->mark_board(14);

	REQUIRE(ttc->game_over() == true);
}

TEST_CASE("Test win by third column and get winner function 4") {
	unique_ptr<TicTacToe> ttc;
	ttc = make_unique<TicTacToe4>();
	ttc->start_game("X");

	ttc->mark_board(3);
	ttc->mark_board(1);
	ttc->mark_board(7);
	ttc->mark_board(2);
	ttc->mark_board(11);
	ttc->mark_board(4);
	ttc->mark_board(15);

	REQUIRE(ttc->game_over() == true);
	REQUIRE(ttc->get_winner() == "X");
}

TEST_CASE("Test win by first row 4") {
	unique_ptr<TicTacToe> ttc;
	ttc = make_unique<TicTacToe4>();
	ttc->start_game("X");

	ttc->mark_board(1);
	ttc->mark_board(5);
	ttc->mark_board(2);
	ttc->mark_board(6);
	ttc->mark_board(3);
	ttc->mark_board(7);
	ttc->mark_board(4);

	REQUIRE(ttc->game_over() == true);
}

TEST_CASE("Test win by second row 4") {
	unique_ptr<TicTacToe> ttc;
	ttc = make_unique<TicTacToe4>();
	ttc->start_game("X");

	ttc->mark_board(5);
	ttc->mark_board(1);
	ttc->mark_board(6);
	ttc->mark_board(2);
	ttc->mark_board(7);
	ttc->mark_board(3);
	ttc->mark_board(8);

	REQUIRE(ttc->game_over() == true);
}

TEST_CASE("Test win by third row 4") {
	unique_ptr<TicTacToe> ttc;
	ttc = make_unique<TicTacToe4>();
	ttc->start_game("X");

	ttc->mark_board(9);
	ttc->mark_board(1);
	ttc->mark_board(10);
	ttc->mark_board(2);
	ttc->mark_board(11);
	ttc->mark_board(3);
	ttc->mark_board(12);

	REQUIRE(ttc->game_over() == true);
}

TEST_CASE("Test win diagonally from top left 4") {
	unique_ptr<TicTacToe> ttc;
	ttc = make_unique<TicTacToe4>();
	ttc->start_game("X");

	ttc->mark_board(1);
	ttc->mark_board(3);
	ttc->mark_board(6);
	ttc->mark_board(2);
	ttc->mark_board(11);
	ttc->mark_board(4);
	ttc->mark_board(16);

	REQUIRE(ttc->game_over() == true);
}

TEST_CASE("Test win diagonally from bottom left 4") {
	unique_ptr<TicTacToe> ttc;
	ttc = make_unique<TicTacToe4>();
	ttc->start_game("X");

	ttc->mark_board(4);
	ttc->mark_board(3);
	ttc->mark_board(7);
	ttc->mark_board(2);
	ttc->mark_board(10);
	ttc->mark_board(1);
	ttc->mark_board(13);

	REQUIRE(ttc->game_over() == true);
}

TEST_CASE("Test TicTacToe Manager 4") {
	TicTacToeManager manager;
	unique_ptr<TicTacToe> ttc;
	ttc = make_unique<TicTacToe4>();

	ttc->start_game("X");
	ttc->mark_board(4);
	ttc->mark_board(3);
	ttc->mark_board(7);
	ttc->mark_board(2);
	ttc->mark_board(10);
	ttc->mark_board(1);
	ttc->mark_board(13);
	REQUIRE(ttc->game_over() == true);
	manager.save_game(ttc);

	ttc = make_unique<TicTacToe4>();
	ttc->start_game("X");
	ttc->mark_board(4);
	ttc->mark_board(3);
	ttc->mark_board(7);
	ttc->mark_board(2);
	ttc->mark_board(10);
	ttc->mark_board(1);
	ttc->mark_board(13);
	REQUIRE(ttc->game_over() == true);
	manager.save_game(ttc);

	ttc = make_unique<TicTacToe4>();
	ttc->start_game("X");
	ttc->mark_board(4);
	ttc->mark_board(3);
	ttc->mark_board(7);
	ttc->mark_board(2);
	ttc->mark_board(10);
	ttc->mark_board(1);
	ttc->mark_board(13);
	REQUIRE(ttc->game_over() == true);
	manager.save_game(ttc);
	int x, o, t;
	manager.get_winner_total(o, x, t);
	REQUIRE(x == 3);
}