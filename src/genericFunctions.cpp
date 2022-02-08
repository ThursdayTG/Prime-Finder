#include <iostream>
#include <string>


using std::cout;
using std::cin;

using std::string;




void clearScreen()
{
	cout.flush();
	cout << "\033[2J\033[1;1H";

	/**
	 * flushes cout and outputs a string of special characters
	 * that will translate to a clear screen command in the console.
	 * should work on any OS.
	 */
}


void printHeader()
{
	clearScreen();

	cout << " \n";
}


bool queryRestart()
{
	string restartOperator;

	cout << " \n"
		 << " \n"
		 << " \n restart? (0/1): ";
	cin  >> restartOperator;

	if (    restartOperator == "1"
	     || restartOperator == "y"    || restartOperator == "Y"
	     || restartOperator == "t"    || restartOperator == "T"
	     || restartOperator == "true" || restartOperator == "not false"
	)  {
		return true;
	}
	else
	{
		return false;
	}
}
