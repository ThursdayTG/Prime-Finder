#include <iostream>
#include <cmath>

#include "../headers/genericFunctions.hpp"
#include "../headers/output.hpp"




int inputFunction(int, int);


int main()
{
    using std::cout;


    bool   restartOperator =  true;
    while (restartOperator == true)
    {
        restartOperator = false;
        printHeader();


        //=== user input
        int lowerBound = 0;
        int upperBound = 0;
        int amountColumns = 0;

        {
            int inputStage = 0;    // used to control std::couts of `inputFunction()`

            inputStage++;
            lowerBound    = inputFunction(inputStage, 0);

            inputStage++;
            upperBound    = inputFunction(inputStage, lowerBound+1);

            inputStage++;
            amountColumns = inputFunction(inputStage, 1);
        }

        int amountSeparators = amountColumns * 32;
        if (upperBound >= 1e+006)
        {
            amountSeparators *= 1.25;
        }
        amountSeparators += 4;


        //=== output
        printHeader();
        cout
        << " lower bound: "    << lowerBound    << "\n"
        << " upper bound: "    << upperBound    << "\n"
        << " amount columns: " << amountColumns << "\n"
        << " \n"
        << " \n";
        printHeader(amountColumns, amountSeparators, upperBound);


        //=== primary function - finding prime numbers in given range
        int dividend;
        int divisor;
        int amountDivisions = 0;
            // quotient = dividend / divisor

        int memory  = lowerBound;
        int newLine = 1;

        float amountPrimes = 0;


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
                cout << "++++++[ "
                     << dividend;

                if (
                    dividend   <  1e+006
                 && upperBound >= 1e+006
                )  {
                    cout << "\t";
                }   // makes tables that end at 7 or more digits more coherent

                cout << "\t | " << dividend - memory << "\t      ]++";

                memory = dividend;

                if (newLine < amountColumns)
                {
                    newLine++;
                }
                else
                {
                    newLine = 1;
                    cout << "++++ \n ";
                }

                amountPrimes++;
            }

            amountDivisions = 0;
        }

        if (    newLine <= amountColumns
             && newLine >  1
        )  {
            cout << "++";
        }


        //=== output - footer
        printFooter(amountColumns, amountSeparators, upperBound);

        cout
        << " \n"
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

        printSeparators(amountSeparators, "_");


        //=== end block
        restartOperator = queryRestart();
        clearScreen();
    }

    return 0;
}
