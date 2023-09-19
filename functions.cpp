#include <string>
#include <iostream>
#include "functions.h"
#include "windows.h"
#include "conio.h"

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
    std::cout << "Введите ваше имя: ";
    getline(std::cin, userName);
    return userName;
}

void helloUser(const std::string& userName) {
    std::cout << "Приветсвую, " << userName << "!"
        << std::endl
        << "Это игра Крестики-колики с ботом!"
        << std::endl
        << "Вы готовы?"
        << std::endl
        << "Нажмите любую кнопку для продолжения...";
    _getch();
}

char getUserSymbol() {
    char userSymbol;
    for (;;) {
        std::cout << "Выберете вашу фигуру для игры"
            << std::endl
            << "(X ходит первым)"
            << std::endl
            << "X | O\n: ";
        userSymbol = getchar();
        if (userSymbol == 'X' ||
            userSymbol == 'O')
            break;
        system("cls");
        std::cout << "Неверный ввод\n";
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
        std::cout << "Ваш ход: ";
        int userChoice;
        std::cin.ignore();
        std::cin >> userChoice;
        if (userChoice < 1 || userChoice > 9) {
            system("cls");
            std::cout << "-----Некоректный ввод!-----\n\n";
            continue;
        }
        char* currentCell = &field[userChoice - 1];
        if (*currentCell == 'X' ||
            *currentCell == 'O') {
            system("cls");
            std::cout << "-----Ячейка занята!-----\n\n";
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