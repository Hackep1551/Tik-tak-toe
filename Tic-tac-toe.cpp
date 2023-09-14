#include <iostream>
#include "functions.h"

char* field;

int main()
{
    initialize(field);
    std::cout << hello() << std::endl;
    std::cout << getStringField(field);
}