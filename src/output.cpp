#include <iostream>
#include <iomanip>

#include <string>
#include <cmath>

#include "../headers/genericFunctions.hpp"
#include "../headers/output.hpp"
#include "../headers/tableStructure.hpp"




void printTableHeader(int amountColumns, int upperBound)
{
    using std::cout;


    cout << " \n ";

    int columnWidth = 8;

    for (int i = 5; upperBound >= pow(10, i); i++)
    {
        columnWidth++;
    }


    for (int col = 0; col < amountColumns; col++)
    {
        //tableFiller();
        cout << std::setw(columnWidth) << "[ prime ";
        cout << std::setw(columnWidth) << "| diff  ";
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

    std::cout << "\n ";
}


void printFooter(int amountColumns, int amountSeparators, int upperBound)
{
    std::cout << "\n ";

    printSeparators(amountSeparators, "-");

    printTableHeader(amountColumns, upperBound);
}