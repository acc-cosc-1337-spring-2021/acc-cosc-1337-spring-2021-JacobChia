#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "dna.h"
#include <string>
using namespace std;

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Test gc content") {
	string str = "AGCTATAG";
	REQUIRE(get_gc_content(str) == 0.375);
	string str2 = "CGCTATAG";
	REQUIRE(get_gc_content(str2) == 0.5);
}

TEST_CASE("Test reverse string") {
	string str = "AGCTATAG";
	REQUIRE(get_reverse_string(str) == "GATATCGA");
	str = "CGCTATAG";
	REQUIRE(get_reverse_string(str) == "GATATCGC");
}

TEST_CASE("Test dna complement") {
	string str = "AAAACCCGGT";
	REQUIRE(get_dna_complement(str) == "ACCGGGTTTT");
	str = "CCCGGAAAAT";
	REQUIRE(get_dna_complement(str) == "ATTTTCCGGG");
}