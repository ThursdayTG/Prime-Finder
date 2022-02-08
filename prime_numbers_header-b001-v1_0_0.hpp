// inclusion of libraries
	#include <iostream>



void cls() {		// cls, clear screen -	derived from system("cls")

	/*	string of special characters that will translate to a clear screen command in the console. should work on any OS.	*/
	std::cout	<< "\033[2J\033[1;1H";
	/**/

}


void pause() {		// 						derived from system("pause")

	/*	use this block to pause progress in console, unpauses on pressing any button input.	*/
	std::cin.ignore();	// may not always be necessary. in that case, use 'cin.get();' instead of 'pause();'.
	std::cin.get();
	/**/

}


bool queryRestart() {

	std::string	restartOperator = "0";		// tries to prevent do-while loop from repeating in case of unexpected error
	std::cout	<< "\n\n restart? (0/1): ";
	std::cin	>> restartOperator;

	if		(	restartOperator == "1"
			||	restartOperator == "one"	||	restartOperator == "One"	||	restartOperator == "oNE"	||	restartOperator == "ONE"
			||	restartOperator == "un"		||	restartOperator == "Un"		||	restartOperator == "uN"		||	restartOperator == "UN"
			||	restartOperator == "uno"	||	restartOperator == "Uno"	||	restartOperator == "uNO"	||	restartOperator == "UNO"
			||	restartOperator == "juan"	||	restartOperator == "Juan"	||	restartOperator == "jUAN"	||	restartOperator == "JUAN"	// "one" if you're mexican, lol

			||	restartOperator == "y"		||	restartOperator == "Y"
			||	restartOperator == "ye"		||	restartOperator == "Ye"		||	restartOperator == "yE"		||	restartOperator == "YE"
			||	restartOperator == "yes"	||	restartOperator == "Yes"	||	restartOperator == "yES"	||	restartOperator == "YES"

			||	restartOperator == "t"		||	restartOperator == "T"
			||	restartOperator == "tru"	||	restartOperator == "Tru"	||	restartOperator == "tRU"	||	restartOperator == "TRU"
			||	restartOperator == "true"	||	restartOperator == "True"	||	restartOperator == "tRUE"	||	restartOperator == "TRUE"

			||	restartOperator == "not untrue" || restartOperator == "not false")
		return true;
	else
		return false;

}
