#include <iostream>
#include <string>

#include "../headers/genericFunctions.hpp"


using std::cout;
using std::string;




void printLabel(int amountColumns, int upperBound)
{
	for (int col = 0; col < amountColumns; col++)
	{
		cout << "++++++[ number  ";
		if (upperBound >= 1e+006)
		{
			cout << "\t ";
		}
		cout << "| difference ]++";
	}
}


void printSeparators(int amountSeparators, string separator)
{
	for (int i = 0; i < amountSeparators; i++)
	{
		cout << separator;
	}
	cout << " \n ";
}




void printHeader(int amountColumns, int amountSeparators, int upperBound)
{
	cout
	<< " \n"
	<< " \n prime numbers in given range: \n"
	<< " \n"
	<< " ";

	printLabel(amountColumns, upperBound);
	cout << "++++ \n ";

	printSeparators(amountSeparators, "─");

	cout
	<< " \n"
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

	printSeparators(amountSeparators / 2, "─ ");
}
