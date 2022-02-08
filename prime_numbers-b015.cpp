// inclusion of libraries
	#include <iostream>
	#include <cmath>

// inclusion of files
	#include "prime_numbers_header-b001-v1_0_0.hpp"



/*	main function	*/

int main() {

	/*	local variable declaration	*/
	bool	restartOperator;
		// used in queryRestart(); function to determine whether do-while loop(s) should be repeated manually
	/**/


	do {

		/**/
		using	std::cout;
		using	std::cin;
		/**/

		cout	<< "\n";

		/*	local variable declaration - input	*/
		bool	errorMessage = false;
			// used to determine whether error message clean-ups need to be done after user inputs

		float	lowerBound;
		float	upperBound;
			// these variables need to be floats for later calculations
		/*	local variable declaration - input	*/

		/*	user input - lower bound	*/
		do	{

			lowerBound = 1;
				// setting default value to prevent getting stuck inside loop on unexpected input

			cout	<< " lower bound (int): ";
			cin		>> lowerBound;

			if	(lowerBound < 0) {		// error message
				cout	<< " lower bound value must be an integer of at least 0! \n\n";
				errorMessage = true;
			}

		}	while (lowerBound < 0);

		if	(errorMessage == true) {	// clean-up of error messages
			errorMessage = false;
			cls();
			cout	<< " \n"
					<< " lower bound (int): " << lowerBound << "\n";
		}
		/*	user input - lower bound	*/

		/*	user input - upper bound	*/
		do	{

			upperBound = 3.40282e+038;
				// setting default value to prevent getting stuck inside loop on unexpected input

			cout	<< " upper bound (int): ";
			cin		>> upperBound;

			if	(upperBound <= lowerBound) {	// error message
				cout	<< " upper bound value must be an integer greater than lower bound value! \n\n";
				errorMessage = true;
			}

		}	while (upperBound <= lowerBound);

		if	(errorMessage == true) {	// clean-up of error messages
			errorMessage = false;
			cls();
			cout	<< " \n"
					<< " lower bound (int): " << lowerBound << "\n"
					<< " upper bound (int): " << upperBound << "\n";
		}
		/*	user input - upper bound	*/

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

		/*	local variable declaration - output	*/
		int		amountColumns		= 2;
		int		amountSeparators	= 0;
		/*	local variable declaration - output	*/

		/*	output - header	*/
		cout	<< " \n\n prime numbers in given range: \n\n ";

		if	(upperBound < 1e+006) {
			for	(	int col	= 0;
					col		< amountColumns;
					col++) {
				cout << "++++++[ number  | difference ]++";
			}

			amountSeparators = (amountColumns * 32) + 4;
		}
		else {
			for	(	int col	= 0;
					col		< amountColumns;
					col++) {
				cout << "++++++[ number  \t | difference ]++";
			}

			amountSeparators = (amountColumns * 40) + 4;
		}

		cout	<< "++++ \n ";

		for	(	int sep	= 0;
				sep		< amountSeparators;
				sep++) {
			cout	<< "-";
		}

		cout	<< " \n\n\n ";
		/*	output - header	*/

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

		/*	local variable declaration - execution	*/
		int		dividend;
		int		divisor;
		int		amountDivisions = 0;
			// quotient = dividend / divisor

		int		memory	= lowerBound;
		int		newLine	= 1;

		float	amountNumbers = 0;	// used to count amount of prime numbers
		/*	local variable declaration - execution	*/

		/*	primary function - finding prime numbers in given range	*/
		for	(	dividend	=	lowerBound;
				dividend	<=	upperBound;
				dividend++) {

			for	(	divisor	=	1;
					divisor	<=	sqrt(dividend);
					divisor++) {

				if	(dividend % divisor == 0) {
					amountDivisions++;

					if	(amountDivisions > 1)
						break;
					// breaks divisor loop when a number can't be a prime number
				}
			}

			if	(amountDivisions == 1) {
				// amountDivisions == 1 only happens if a number could be divided by 1 and itself

				cout	<< "++++++[ "
						<< dividend;

				if	(	dividend	<	1e+006
					&&	upperBound	>=	1e+006)
					cout	<< "\t";
				// makes tables that end at 7 or more digits more coherent

				cout	<< "\t | "
						<< dividend - memory
						<< "\t      ]++";

				memory = dividend;

				if	(newLine < amountColumns)
					newLine++;
				else {
					newLine = 1;
					cout	<< "++++ \n ";
				}

				amountNumbers++;
			}

			amountDivisions = 0;
		}

		if	(	newLine <=	amountColumns
			&&	newLine >	1)
			cout	<< "++";
		/*	primary function - finding prime numbers in given range	*/

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

		/*	output - footer	*/
		cout	<< " \n\n ";

		for	(	int sep	= 0;
				sep		< amountSeparators;
				sep++) {
			cout	<< "-";
		}

		cout	<< " \n ";

		if	(upperBound < 1e+006) {
			for	(	int col	= 0;
					col		< amountColumns;
					col++) {
				cout << "++++++[ number  | difference ]++";
			}
		}
		else {
			for	(	int col	= 0;
					col		< amountColumns;
					col++) {
				cout << "++++++[ number  \t | difference ]++";
			}
		}

		cout	<< "++++"
				<< " \n\n "

				<< " \n amount of numbers checked:"
				<< " \t\t\t\t "
				<< upperBound - lowerBound + 1

				<< " \n absolute amount of prime numbers in given range:"
				<< " \t "
				<< amountNumbers

				<< " \n percentage of prime numbers in given range:"
				<< " \t\t "
				<< amountNumbers / (upperBound - lowerBound + 1) * 100 << "%"
				<< " \n ";
		/*	output - footer	*/

		/*	end	*/
		restartOperator = queryRestart();	// asks user whether current section of program should be looped
		cls();								// clears screen
		/*	end	*/

	}	while (restartOperator == true);

	return 0;
}

/*	using C++ compiler from GCC via console

	compile for debug:
g++ -Og prime_numbers-b016-v1_7_0.cpp -o prime_numbers-newest.debug

	clear and compile as final executable:
clear && g++ -O0 prime_numbers-b016-v1_7_0.cpp -o prime_numbers-newest.release

	clear console, compile debug executable, compile release executable, and run program:
g++ -Og prime_numbers-b016-v1_7_0.cpp -o prime_numbers.debug && g++ -O3 prime_numbers-b016-v1_7_0.cpp -o prime_numbers-newest.release && clear && ./prime_numbers-newest.release

   g++ -Og prime_numbers-b016-v1_7_0.cpp -o prime_numbers-newest.debug
&& g++ -O3 prime_numbers-b016-v1_7_0.cpp -o prime_numbers-newest.release
&& clear
&& prime_numbers-newest.release
*/
