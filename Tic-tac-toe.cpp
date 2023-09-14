#include <iostream>
#include "windows.h"

#include "functions.h"

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "ru");
    std::cout << hello();
}