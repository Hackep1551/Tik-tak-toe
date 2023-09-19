#include <iostream>
#include "functions.h"

char* field;
std::string userName;

int main()
{
    initialize(field);
    userName = getUserName();
    helloUser(userName);
}