#include <iostream>
#include "functions.h"

char* field;

struct UsersInfo {
    std::string botName;
    std::string userName;
    char userSymbol;
    char botSymbol;
};


int main()
{
    UsersInfo usersInfo;
    initialize(field);
    usersInfo.userName = getUserName();
    system("cls");
    helloUser(usersInfo.userName);
    system("cls");
    usersInfo.userSymbol = getUserSymbol();
    system("cls");
    usersInfo.botSymbol = 
        usersInfo.userSymbol == 'X' ? 'O' : 'X';
}