#include <iostream>
#include <string>




int inputFunction(int inputStage, int comparable)
{
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


    using std::cout, std::cin;
    using std::stoi;

    do
    {
        cout << " " << outputVariable << ": ";
        cin  >> input;

        if (input == "help")
        {
            cout << "";  // section WIP
        }

        if (stoi(input) < comparable)
        {
            cout << " ===== ERROR: input value MUST NOT be lower than " << comparable << "! ====="
                 << "\n\n";
        }
    }
    while (stoi(input) < comparable);

    return stoi(input);
}