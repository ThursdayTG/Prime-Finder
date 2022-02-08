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

void pause()
{
	cin.ignore();
	cin.get();
}

bool queryRestart()
{
	std::string restartOperator = "0";  // default value tries to prevent infinite loop repetition on unexpected error

	cout << "\n\n restart? (0/1): ";
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
