// inclusion of libraries
	#include <iostream>
	#include <chrono>

// inclusion of files
	#include "prime_numbers_header-b001-v1_0_0.hpp"



/*	main function	*/

int main() {

	/*	local variable declaration	*/
	bool	restartOperator;
		// used in queryRestart(); function to determine whether do-while loop(s) should be repeated manually
	/**/

	int mem2;

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
		float	amountNumbers = 0;	// used to count amount of prime numbers
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



		/*	local variable declaration - execution & output	*/
		int		dividend;
		int		quotient;
		int		amountDivisions = 0;
			// divisor = dividend / quotient

		int		amountColumns		= 5;
		int		amountSeparators	= 0;

		int		memory	= 0;
		int		newLine	= 1;

		int		dividendIncrement = 1;
		/*	local variable declaration - execution & output	*/

		/*	output - header	*/
		cout	<< " \n\n prime numbers in given range: \n\n ";

		if	(upperBound < 1e+006) {
			for	(	int col	= 0;
					col		< amountColumns;
					col++) {
				cout << "++++++[ number  | difference ]++";
			}

			cout	<< "++++ \n ";
			amountSeparators = amountColumns * 32 + 4;
		}
		else {
			for	(	int col	= 0;
					col		< amountColumns;
					col++) {
				cout << "++++++[ number  \t | difference ]++";
			}

			cout	<< "++++ \n ";
			amountSeparators = amountColumns * 40 + 4;
		}

		for	(	int sep	= 0;
				sep		< amountSeparators;
				sep++) {
			cout	<< "-";
		}

		cout	<< " \n\n\n ";
		/*	output - header	*/

		/*	primary execution block	*/
		memory = lowerBound;
			// makes first output of difference the difference to lowerBound; otherwise would be difference to 0

		if	(	lowerBound	<=	2
			&&	upperBound	>=	2) {

		int		lowerBoundI = lowerBound;
		int		upperBoundI = 2;

		for	(	dividend	=	lowerBoundI;
				dividend	<=	upperBoundI;
				dividend	+=	dividendIncrement) {

			for	(	quotient	=	1;
					quotient	<=	dividend;
					quotient++) {

				if	(dividend % quotient == 0) {
					amountDivisions++;

					if	(amountDivisions > 2)
						break;
					// breaks quotient loop when a number can't be a prime number
				}
			}

			if	(amountDivisions == 2) {
				// amountDivisions == 2 only happens if a number could be divided by 1 and itself

				cout	<< "++++++[ "
						<< dividend;

				if	(	dividend	<	1e+006
					&&	upperBound	>=	1e+006)
					cout	<< "\t";
				// renders tables that go beyond 7 digit long prime numbers more cohesively
				// because 7 digit long prime numbers cause further indentation

				cout	<< "\t | "
						<< dividend - memory
						<< "\t      ]++";

				memory = dividend;

				if	(newLine < amountColumns)
					newLine++;
				else {
					newLine = 1;
					cout	<< "++++\n ";
				}

				amountNumbers++;
			}

			amountDivisions = 0;
		}

		}

		mem2 = lowerBound;
		lowerBound			= 3;
		dividendIncrement	= 2;

		for	(	dividend	=	lowerBound;
				dividend	<=	upperBound;
				dividend	+=	dividendIncrement) {

			for	(	quotient	=	1;
					quotient	<=	dividend;
					quotient++) {

				if	(dividend % quotient == 0) {
					amountDivisions++;

					if	(amountDivisions > 2)
						break;
					// breaks quotient loop when a number can't be a prime number
				}
			}

			if	(amountDivisions == 2) {
				// amountDivisions == 2 only happens if a number could be divided by 1 and itself

				cout	<< "++++++[ "
						<< dividend;

				if	(	dividend	<	1e+006
					&&	upperBound	>=	1e+006)
					cout	<< "\t";
				// renders tables that go beyond 7 digit long prime numbers more cohesively
				// because 7 digit long prime numbers cause further indentation

				cout	<< "\t | "
						<< dividend - memory
						<< "\t      ]++";

				memory = dividend;

				if	(newLine < amountColumns)
					newLine++;
				else {
					newLine = 1;
					cout	<< "++++\n ";
				}

				amountNumbers++;
			}

			amountDivisions = 0;
		}

		if	(	newLine <=	amountColumns
			&&	newLine >	1		)
			cout	<< "++";

		lowerBound -= mem2;
		/*	primary execution block	*/

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



		/*	end block	*/
		restartOperator = queryRestart();	// asks user whether current section of program should be looped
		cls();								// clears screen
		/*	end block	*/

	}	while (restartOperator == true);

	return 0;

}

/*	using C++ compiler from GCC via console

	compile for debug:
g++ -Og prime_numbers-b014.cpp -o prime_numbers-newest.debug

	clear and compile as final executable:
clear && g++ -O0 prime_numbers-b014.cpp -o prime_numbers-newest.release

	clear console, compile debug executable, compile release executable, and run program:
g++ -Og prime_numbers-b014.cpp -o prime_numbers.debug && g++ -O3 prime_numbers-b014.cpp -o prime_numbers-newest.release && clear && ./prime_numbers-newest.release

   g++ -Og prime_numbers-b014.cpp -o prime_numbers-newest.debug
&& g++ -O3 prime_numbers-b014.cpp -o prime_numbers-newest.release
&& clear
&& prime_numbers-newest.release
*/
