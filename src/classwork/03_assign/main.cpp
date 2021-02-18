//Write the include statement for decisions.h here
#include <string>
#include <iostream>
#include <decision.h>

//Write namespace using statements for cout and cin
using std::string; 
using std::cout;
using std::cin;


int main() 
{
	int grade;
	string letter;

	cout << "Please enter your grade (if): ";
	cin >> grade;

	letter = get_letter_grade_using_if(grade);
	cout << "Your letter grade is: " << letter << "\n";

	cout << "Please enter your grade (switch): ";
	cin >> grade;

	letter = get_letter_grade_using_switch(grade);
	cout << "Your letter grade is: " << letter << "\n";

	return 0;
}

