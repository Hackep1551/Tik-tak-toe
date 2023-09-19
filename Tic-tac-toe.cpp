#include <iostream>
#include "functions.h"

char* field;




int main()
{
    UsersInfo usersInfo;
    usersInfo.botName = "Бот :D";
    initialize(field);
    usersInfo.userName = getUserName();
    system("cls");
    helloUser(usersInfo.userName);
    system("cls");
    usersInfo.userSymbol = getUserSymbol();
    system("cls");
    usersInfo.botSymbol = 
        usersInfo.userSymbol == 'X' ? 'O' : 'X';
    system("cls");
    if (usersInfo.userSymbol == 'X')
        getUserTurn(usersInfo, field);
    for (;;) {
        getBotTurn(usersInfo, field);
        getUserTurn(usersInfo, field);
    }
}