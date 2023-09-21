#include <string>
#include <iostream>
#include "functions.h"
#include "windows.h"
#include "conio.h"
#include <vector>

std::string getStringField(char* field) {
    std::string stringField = "-------------\n";
    for (int i = 0; i < FIELD_SIZE;) {
        stringField.append("| ").push_back(field[i++]);
        stringField.append(" | ").push_back(field[i++]);
        stringField.append(" | ").push_back(field[i++]);
        stringField.append(" |\n-------------\n");
    }
    return stringField;
}

void initialize(char*& field) {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "ru");
    srand(time(NULL));
    char* startfield = new char[FIELD_SIZE]
    { '1', '2', '3', '4', '5', '6', '7', '8', '9' };
    field = startfield;
}

std::string getUserName() {
    std::string userName;
    std::cout << "  : ";
    getline(std::cin, userName);
    return userName;
}

void helloUser(const std::string& userName) {
    std::cout << ", " << userName << "!"
        << std::endl
        << "  -  !"
        << std::endl
        << " ?"
        << std::endl
        << "    ...";
    _getch();
}

char getUserSymbol() {
    char userSymbol;
    for (;;) {
        std::cout << "    "
            << std::endl
            << "(X  )"
            << std::endl
            << "X | O\n: ";
        userSymbol = getchar();
        if (userSymbol == 'X' ||
            userSymbol == 'O')
            break;
        system("cls");
        std::cout << " \n";
    }
    return userSymbol;
}

void getUserTurn(const UsersInfo& usersInfo, char* field) {
    for (;;) {
        std::cout << usersInfo.userName << "\t"
            << usersInfo.userSymbol << std::endl
            << usersInfo.botName << "\t"
            << usersInfo.botSymbol << "\t" << std::endl;
        std::cout << getStringField(field);
        std::cout << " : ";
        int userChoice;
        std::cin.ignore();
        std::cin >> userChoice;
        if (userChoice < 1 || userChoice > 9) {
            system("cls");
            std::cout << "----- !-----\n\n";
            continue;
        }
        char* currentCell = &field[userChoice - 1];
        if (*currentCell == 'X' ||
            *currentCell == 'O') {
            system("cls");
            std::cout << "----- !-----\n\n";
            continue;
        }
        *currentCell = usersInfo.userSymbol;
        system("cls");
        break;
    }
}
void getBotTurn(const UsersInfo& usersInfo, char* field) {
    int botChoice;
    for (;;) {
        botChoice = (int)(rand() % 8 + 1);
        if (botChoice < 1 || botChoice > 9) continue;
        char* currentCell = &field[botChoice - 1];
        if (*currentCell == 'X' ||
            *currentCell == 'O') continue;
        *currentCell = usersInfo.botSymbol;
        break;
    }
}

char getWinner(char* field) {
    std::vector<std::vector<int>> winCombinations = {
        {0, 1, 2},
        {3, 4, 5},
        {6, 7, 8},
        {0, 3, 6},
        {1, 4, 7},
        {2, 5, 8},
        {0, 4, 8},
        {2, 4, 6}
    };
    int countNumbers = 0;
    for (std::vector<int> winCombination : winCombinations) {
        char symbols[3];
        int i = 0;
        for (int index : winCombination)
            symbols[i++] = field[index];
        for (int i = 0; i < 3; i++)
            if (symbols[i] != 'X' && symbols[i] != 'O') countNumbers++;
        if (symbols[0] == symbols[1] &&
            symbols[0] == symbols[2])
            return symbols[0];
    }
    if (countNumbers == 0) return 'N';
    return '_';
}

int updateScore(const UsersInfo& usersInfo, char winner) {
    if (usersInfo.userSymbol == winner)
        usersInfo.scoreUser + 1;
    else if (usersInfo.botSymbol == winner)
        usersInfo.scoreBot + 1;
    std::cout << std::endl << "¬аш счЄт: " << usersInfo.scoreUser << std::endl << "—чЄт бота: " << usersInfo.scoreBot;

}