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