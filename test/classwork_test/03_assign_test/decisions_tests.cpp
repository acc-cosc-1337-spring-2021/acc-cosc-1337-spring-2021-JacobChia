#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "decision.h"
#include <string>
using std::string;

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("TEST IF") {
	string ans = get_letter_grade_using_if(95);
	REQUIRE(ans.compare("A") == 0);
	ans = get_letter_grade_using_if(85);
	REQUIRE(ans.compare("B") == 0);
	ans = get_letter_grade_using_if(75);
	REQUIRE(ans.compare("C") == 0);
	ans = get_letter_grade_using_if(65);
	REQUIRE(ans.compare("D") == 0);
	ans = get_letter_grade_using_if(50);
	REQUIRE(ans.compare("F") == 0);
}

TEST_CASE("TEST SWITCH") {
	string ans = get_letter_grade_using_switch(95);
	REQUIRE(ans.compare("A") == 0);
	ans = get_letter_grade_using_switch(85);
	REQUIRE(ans.compare("B") == 0);
	ans = get_letter_grade_using_switch(75);
	REQUIRE(ans.compare("C") == 0);
	ans = get_letter_grade_using_switch(65);
	REQUIRE(ans.compare("D") == 0);
	ans = get_letter_grade_using_switch(50);
	REQUIRE(ans.compare("F") == 0);
}