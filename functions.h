#pragma once
#define FIELD_SIZE 9

struct UsersInfo {
    std::string botName;
    std::string userName;
    char userSymbol;
    char botSymbol;
    int scoreBot = 0;
    int scoreUser = 0;
};

void initialize(char*& field);
std::string getStringField(char* field);
std::string getUserName();
void helloUser(const std::string& username);
char getUserSymbol();
void getUserTurn(const UsersInfo& usersInfo, char* field);
void getBotTurn(const UsersInfo& usersInfo, char* field);
char getWinner(char* field);
int updateScore(const UsersInfo& usersInfo, char winner);
int getScore(const UsersInfo& usersInfo);
