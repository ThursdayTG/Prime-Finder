//=== inclusions & using directives ============================================

// inclusion of standard headers
#include <iostream>
#include <cmath>


// inclusion of custom headers
//lorem_ipsum


// using directives
using std::cout;
using std::cin;

using std::string;


//=== main function ============================================================


// function prototyping
int inputFunction(int, int);

void cls();           // std::cout << "\033[2J\033[1;1H";
void pause();         // std::cin.ignore(); std::cin.get();
bool queryRestart();


// main function
int main()
{
	bool restartOperator;	// used to determine whether do-while loop should be repeated manually

	do
	{
		cout	<< "\n";

		//=== user input ===
		int lowerBound = 0;
		int upperBound = 0;
		int amountColumns = 0;

		{
		int inputStage = 0; // used to control std::couts of inputFunction()

		inputStage++;
		lowerBound = inputFunction(inputStage, 0);

		inputStage++;
		upperBound = inputFunction(inputStage, lowerBound);

		inputStage++;
		amountColumns = inputFunction(inputStage, 1);
		}

		//=== output of corrected user input ===
		cls();



		//=== output - header ===
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


		//=== local variable declaration - execution ===
		int		dividend;
		int		divisor;
		int		amountDivisions = 0;
			// quotient = dividend / divisor

		int		memory	= lowerBound;
		int		newLine	= 1;

		float	amountPrimes = 0;


		//=== primary function - finding prime numbers in given range ===
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


		//=== output - footer ===
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


		//=== end block ===
		restartOperator = queryRestart();	// asks user whether current section of program should be looped
		cls();								// clears screen

	}	while (restartOperator == true);

	return 0;
}


//=== function definitions =====================================================


void cls()
{
	cout << "\033[2J\033[1;1H";

	/* derived from `system("cls")`
	 *
	 * string of special characters that will translate to a clear screen command in the console.
	 * should work on any OS.
	 */
}

void pause()
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

bool queryRestart()
{
	string restartOperator = "0";
		// default value tries to prevent infinite loop repetition on unexpected error

	cout << "\n\n restart? (0/1): ";
	cin  >> restartOperator;

	if		(	restartOperator == "1"
			||	restartOperator == "y"		||	restartOperator == "Y"
			||	restartOperator == "t"		||	restartOperator == "T"
			||	restartOperator == "true"	||	restartOperator == "not false")
		return true;
	else
		return false;
}
