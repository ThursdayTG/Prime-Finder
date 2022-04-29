#include <iostream>
#include <iomanip>
#include <cmath>

#include "../headers/genericFunctions.hpp"
#include "../headers/tableStructure.hpp"
#include "../headers/userInput.hpp"
#include "../headers/output.hpp"




int main()
{
    using std::cout;


    bool   restartOperator  = true;
    while (restartOperator == true)
    {

        restartOperator = false;
        printHeader();


        //=== user input
        tableStructure ts;
        ts = func(ts);

        ts.amountSeparators = ts.amountColumns * 32;
        if (ts.upperBound >= 1e+006)
        {
            ts.amountSeparators *= 1.25;
        }
        ts.amountSeparators += 4;


        //=== output
        printHeader();
        cout
        << " lower bound: "    << ts.lowerBound    << "\n"
        << " upper bound: "    << ts.upperBound    << "\n"
        << " amount columns: " << ts.amountColumns << "\n"
        << " \n\n";
        printHeader(ts.amountColumns, ts.amountSeparators, ts.upperBound);


        //=== finding prime numbers in given range
        int dividend;
        int divisor;
        int amountDivisions = 0;
            // quotient = dividend / divisor

        int memory  = ts.lowerBound;
        int newLine = 1;

        float amountPrimes = 0;


        for (dividend = ts.lowerBound; dividend <= ts.upperBound; dividend++)
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
                 && ts.upperBound >= 1e+006
                )  {
                    cout << "\t";
                }   // makes tables that end at 7 or more digits more coherent

                cout << "\t | " << dividend - memory << "\t      ]++";

                memory = dividend;

                if (newLine < ts.amountColumns)
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

        if (
            newLine <= ts.amountColumns
         && newLine >  1
        )  {
            cout << "++";
        }


        //=== output - footer
        printFooter(ts.amountColumns, ts.amountSeparators, ts.upperBound);

        {
            int setw = 55;
            cout
            << " \n"
            << std::left
            << std::setw(setw) << " \n amount of numbers checked:"                       << ts.upperBound - ts.lowerBound + 1
            << std::setw(setw) << " \n absolute amount of prime numbers in given range:" << amountPrimes
            << std::setw(setw) << " \n percentage of prime numbers in given range:"      << amountPrimes / (ts.upperBound - ts.lowerBound + 1) * 100 << "%"
            << " \n\n ";
        }

        printSeparators(ts.amountSeparators, "_");


        //=== end
        restartOperator = queryRestart();
        clearScreen();
    }

    return 0;
}
