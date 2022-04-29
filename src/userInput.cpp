#include <iostream>
#include <string>

#include "../headers/tableStructure.hpp"




int inputFunction(int inputStage, int comparable)
{
    //=== setting outputVariable
    std::string input;
    std::string outputVariable;

    switch(inputStage)
    {
        case 1:
        {
            outputVariable = "lower bound";
            break;
        }
        case 2:
        {
            outputVariable = "upper bound";
            break;
        }
        case 3:
        {
            outputVariable = "amount columns";
            break;
        }
        default:
        {
            outputVariable = "undefined";
        }
    }


    //=== user input
    using std::stoi;

    do
    {
        std::cout << " " << outputVariable << ": ";
        std::cin  >> input;

        if (input == "help")
        {
            std::cout
            << "";
            // section WIP
        }

        if (stoi(input) < comparable)
        {
            std::cout
            << " ===== ERROR: input value MUST NOT be lower than " << comparable << "! ====="
            << " \n\n";
        }
    }
    while (stoi(input) < comparable);

    return stoi(input);
}


tableStructure func(tableStructure ts)
{
    int inputStage = 0;    // used to control std::couts of `inputFunction()`

    inputStage++;
    ts.lowerBound    = inputFunction(inputStage, 0);

    inputStage++;
    ts.upperBound    = inputFunction(inputStage, ts.lowerBound+1);

    inputStage++;
    ts.amountColumns = inputFunction(inputStage, 1);

    return ts;
}