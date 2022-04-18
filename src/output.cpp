#include <iostream>
#include <string>

#include "../headers/genericFunctions.hpp"




void printTableHeader(int amountColumns, int upperBound)
{
    using std::cout;


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


void printSeparators(int amountSeparators, std::string separator)
{
    for (int i = 0; i < amountSeparators; i++)
    {
        std::cout << separator;
    }
}




void printHeader(int amountColumns, int amountSeparators, int upperBound)
{
    std::cout
    << " \n"
    << " \n prime numbers in given range: \n"
    << " \n"
    << " ";

    printTableHeader(amountColumns, upperBound);

    printSeparators(amountSeparators, "-");

    std::cout
    << " \n"
    << " ";
}


void printFooter(int amountColumns, int amountSeparators, int upperBound)
{
    std::cout
    << " \n"
    << " ";

    printSeparators(amountSeparators, "-");

    printTableHeader(amountColumns, upperBound);
}