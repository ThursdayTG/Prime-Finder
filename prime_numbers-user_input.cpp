//=== inclusions & using directives ============================================

// inclusion of standard headers
#include <iostream>
#include <string>


// inclusion of custom headers
//lorem_ipsum


// using directives
using std::cout;
using std::cin;

using std::string;
using std::stoi;


//==============================================================================


int inputFunction(int inputStage, int comparable)
{
	string input;
	string outputVariable;

	switch(inputStage)
	{
		case 1:
			outputVariable = "lower bound";
			break;

		case 2:
			outputVariable = "upper bound";
			break;

		case 3:
			outputVariable = "amount columns";
			break;

		default:
			outputVariable = "unset";
	}

	do
	{
		cout << " " << outputVariable << ": ";
		cin  >> input;

		if (input == "help")
		{
			return 0;
		}

		if (stoi(input) <= comparable)
		{
			cout << " error: input value MUST NOT be lower than " << comparable << "!";
		}
	}
	while (stoi(input) <= comparable);

	return stoi(input);
}


//=== previous implementation ==================================================


/*
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

			 * recommended values
			 *
			 * max recommended value < 1e+006: 7
			 * max recommended value >= 1e+006: 5
			 * max recommended value >= 1e+014: 4
			 * min recommended value (general): 2
			 *

			cout	<< " amount columns (int): ";
			cin		>> amountColumns;
		}
		while (amountColumns < 1);
*/
