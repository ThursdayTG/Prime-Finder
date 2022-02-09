#include <iostream>
#include <string>

#include "../headers/genericFunctions.hpp"


using std::cout;
using std::string;




void printLabel(int amountColumns, int upperBound)
{
	cout << " \n ";

	for (int col = 0; col < amountColumns; col++)
	{
		cout << "++++++[ number  ";
		if (upperBound >= 1e+006)
		{
			cout << "\t ";
		}
		cout << "| difference ]++";
	}

	cout << "++++ \n ";
}


void printSeparators(int amountSeparators, string separator)
{
	for (int i = 0; i < amountSeparators; i++)
	{
		cout << separator;
	}
}




void printHeader(int amountColumns, int amountSeparators, int upperBound)
{
	cout
	<< " \n"
	<< " \n prime numbers in given range: \n"
	<< " ";

	printLabel(amountColumns, upperBound);

	printSeparators(amountSeparators, "─");

	cout
	<< " \n"
	<< " \n"
	<< " ";
}


void printFooter(int amountColumns, int amountSeparators, int upperBound)
{
	cout
	<< " \n"
	<< " \n"
	<< " ";

	printSeparators(amountSeparators, "─");

	printLabel(amountColumns, upperBound);
}
