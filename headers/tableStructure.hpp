#ifndef HEADERS_TABLESTRUCTURE
#define HEADERS_TABLESTRUCTURE




struct tableStructure
{
    int lowerBound {0};
    int upperBound {1};

    int amountColumns {1};
    int columnWidth   {8};

    int amountSeparators {1};

    int  fillWidth {4};
    char fillChar  {'+'};
};




#endif