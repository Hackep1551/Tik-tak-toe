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
    char winner = '_';
    for (;;) {
        getBotTurn(usersInfo, field);
        winner = getWinner(field);
        if (winner != '_')
            break;
        getUserTurn(usersInfo, field);
        winner = getWinner(field);
        if (winner != '_')
            break;
    }
    system("cls");
    if (winner == 'N') std::cout << "Ничья";
    else std::cout <<
        (usersInfo.userSymbol == winner ?
            usersInfo.userName : usersInfo.botName) << " победил!";
}
