//write include statements
#include "dna.h"
#include <iostream>
#include <string>

//write using statements
using namespace std;

/*
Write code that prompts user to enter 1 for Get GC Content, 
or 2 for Get DNA Complement.  The program will prompt user for a 
DNA string and call either get gc content or get dna complement
function and display the result. Program runs as long as 
user enters a y or Y.
*/
int main() 
{
	char ctn = 'n';
	int opt = 0;
	string dna = "";

	while(1) {
		cout << "Please enter 1 for Get GC Content or 2 for Get DNA Complement\n";
		cin >> opt;

		cout << "Please enter a DNA string\n";
		cin >> dna;

		if(opt == 1) {
			double gc = get_gc_content(dna);
			cout << "GC content: " << gc << "\n";
		} else if(opt == 2) {
			string result = get_dna_complement(dna);
			cout << "DNA complement: " << result << "\n";
		} else {
			cout << "Please only enter 1 or 2 for option";
		}
		
		cout << "Continue?\n";
		cin >> ctn;
		if (ctn != 'Y' and ctn != 'y')
			break;
	}

	return 0;
}