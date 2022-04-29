#include <iostream>
#include <string>




void clearScreen()
{
    std::cout.flush();
    std::cout << "\033[2J\033[1;1H";

    /**
     * flushes stdout and outputs ANSI escape sequences to
     * clear the screen, then position the cursor at row 1 column 1.
     */
}


void printHeader()
{
    clearScreen();

    std::cout
    << " \n"
    << "";
}


bool queryRestart()
{
    char restartOperator;

    std::cout
    << " \n"
    << " \n"
    << " \n restart? (0/1): ";
    std::cin >> restartOperator;
    std::cin.ignore();

    if (
        restartOperator == '1'
     || restartOperator == 'Y' || restartOperator == 'y'
     || restartOperator == 'T' || restartOperator == 't'
    )  {
        return true;
    }
    else
    {
        return false;
    }
}