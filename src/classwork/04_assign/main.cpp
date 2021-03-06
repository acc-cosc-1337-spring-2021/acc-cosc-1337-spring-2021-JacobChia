//write includes statements

//write using statements for cin and cout
#include <string>
#include <iostream>
#include <loops.h>

//Write namespace using statements for cout and cin
using std::string; 
using std::cout;
using std::cin;

/*
Use a do while loop to prompt the user for 
a number, call the factorial function, and display the number's
factorial.  Also, loop continues as long as user wants to.
*/
int main() 
{
	int num;
	do{
		cout << "Please enter a number from 1 to 10: ";
		cin >> num;
		if(num > 10 or num < 1){
			cout << "The number should be from 1 to 10.\n";
			continue;
		}
		cout << factorial(num) << "\n";
	}while(1);

	return 0;
}