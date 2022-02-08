// inclusion of libraries
#include <iostream>
#include <cmath>

// inclusion of files
#include "prime_numbers-header.hpp"

// using directives
using std::cout;
using std::cin;



// main function
int main()
{
	bool	restartOperator;	// used to determine whether do-while loop should be repeated manually

	do
	{
		cout	<< "\n";

		// local variable declaration - user input
		bool	errorMessage = false;	// determines whether error message clean-ups need to be done after user inputs


		// user input - lower bound
		float	lowerBound;		// needs to be float for later calculations

		do
		{
			lowerBound = 1;		// setting default value to prevent getting stuck inside loop on unexpected input

			cout	<< " lower bound (int): ";
			cin		>> lowerBound;

			if (lowerBound < 0)
			{
				cout	<< " lower bound value must be an integer of at least 0! \n\n";
				errorMessage = true;
			}	// error message
		}
		while (lowerBound < 0);

		if	(errorMessage == true)
		{
			errorMessage = false;
			cls();
			cout	<< " \n"
					<< " lower bound (int): " << lowerBound << "\n";
		}	// clean-up of error messages


		// user input - upper bound
		float	upperBound;		// needs to be float for later calculations

		do
		{
			upperBound = 3.40282e+038;	// default value tries to prevent infinite loop repetition on unexpected error

			cout	<< " upper bound (int): ";
			cin		>> upperBound;

			if	(upperBound <= lowerBound)
			{
				cout	<< " upper bound value must be an integer greater than lower bound value! \n\n";
				errorMessage = true;
			}	// error message
		}
		while (upperBound <= lowerBound);

		if (errorMessage == true)
		{
			errorMessage = false;
			cls();
			cout	<< " \n"
					<< " lower bound (int): " << lowerBound << "\n"
					<< " upper bound (int): " << upperBound << "\n";
		}	// clean-up of error messages


		// user input - amount columns
		int		amountColumns;

		do
		{
			amountColumns = 1;		// setting default value to prevent getting stuck inside loop on unexpected input

			/* recommended values
			 *
			 * max recommended value < 1e+006: 7
			 * max recommended value >= 1e+006: 5
			 * max recommended value >= 1e+014: 4
			 * min recommended value (general): 2
			 */

			cout	<< " amount columns (int): ";
			cin		>> amountColumns;
		}
		while (amountColumns < 1);


		// output - header
		int		amountSeparators = 0;

		cout	<< " \n\n prime numbers in given range: \n\n ";

		for (int col = 0; col < amountColumns; col++)
		{
			cout	<< "++++++[ number  ";
			if (upperBound >= 1e+006)
			{
				cout	<< "\t ";
			}
			cout	<< "| difference ]++";
		}

		amountSeparators = amountColumns * 32;
		if (upperBound >= 1e+006)
		{
			amountSeparators *= 1.25;
		}
		amountSeparators += 4;

		cout	<< "++++ \n ";
		for (int sep = 0; sep < amountSeparators; sep++)
		{
			cout	<< "-";
		}
		cout	<< " \n\n\n ";


		// local variable declaration - execution
		int		dividend;
		int		divisor;
		int		amountDivisions = 0;
			// quotient = dividend / divisor

		int		memory	= lowerBound;
		int		newLine	= 1;

		float	amountPrimes = 0;


		// primary function - finding prime numbers in given range
		for (dividend = lowerBound; dividend <= upperBound; dividend++)
		{
			for (divisor = 1; divisor <= sqrt(dividend); divisor++)
			{
				if (dividend % divisor == 0)
				{
					amountDivisions++;

					if (amountDivisions > 1)
					{
						break;
					}
				}
			}

			if (amountDivisions == 1)
			{
				cout	<< "++++++[ "
						<< dividend;

				if	(	dividend	<	1e+006
					&&	upperBound	>=	1e+006)
				{
					cout	<< "\t";	// makes tables that end at 7 or more digits more coherent
				}

				cout	<< "\t | "
						<< dividend - memory
						<< "\t      ]++";

				memory = dividend;

				if	(newLine < amountColumns)
				{
					newLine++;
				}
				else
				{
					newLine = 1;
					cout	<< "++++ \n ";
				}

				amountPrimes++;
			}

			amountDivisions = 0;
		}

		if	(	newLine <=	amountColumns
			&&	newLine >	1)
		{
			cout	<< "++";
		}


		// output - footer
		cout	<< " \n\n ";

		for (int sep = 0; sep < amountSeparators; sep++)
		{
			cout	<< "-";
		}
		cout	<< " \n ";

		for (int col = 0; col < amountColumns; col++)
		{
			cout	<< "++++++[ number  ";
			if (upperBound >= 1e+006)
			{
				cout	<< "\t ";
			}
			cout	<< "| difference ]++";
		}

		cout	<< "++++"
				<< " \n\n "

				<< " \n amount of numbers checked:"
				<< " \t\t\t\t "
				<< upperBound - lowerBound + 1

				<< " \n absolute amount of prime numbers in given range:"
				<< " \t "
				<< amountPrimes

				<< " \n percentage of prime numbers in given range:"
				<< " \t\t "
				<< amountPrimes / (upperBound - lowerBound + 1) * 100 << "%"
				<< " \n\n ";

		for (int sep = 0; sep < amountSeparators / 2; sep++)
		{
			cout	<< "- ";
		}


		// end block
		restartOperator = queryRestart();	// asks user whether current section of program should be looped
		cls();								// clears screen

	}	while (restartOperator == true);

	return 0;
}
