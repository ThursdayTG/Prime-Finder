// inclusion of libraries
#include <iostream>
#include <string>

// using directives
using std::cout;
using std::cin;
using std::string;



inline void cls()
{
	cout	<< "\033[2J\033[1;1H";

	/* derived from `system("cls")`
	 *
	 * string of special characters that will translate to a clear screen command in the console.
	 * should work on any OS.
	 */
}

inline void pause()
{
	cin.ignore();
	cin.get();

	/* derived from `system("pause")`
	 *
	 * use this block to pause progress in console.
	 * unpauses on pressing any button input.
	 * `cin.ignore()` may not always be necessary,
	 * in that case use `cin.get()` instead of `pause();`
	 */
}

inline bool queryRestart()
{
	string	restartOperator = "0";
		// default value tries to prevent infinite loop repetition on unexpected error

	cout	<< "\n\n restart? (0/1): ";
	cin		>> restartOperator;

	if		(	restartOperator == "1"
			||	restartOperator == "y"		||	restartOperator == "Y"
			||	restartOperator == "t"		||	restartOperator == "T"
			||	restartOperator == "true"	||	restartOperator == "not false")
		return true;
	else
		return false;
}
