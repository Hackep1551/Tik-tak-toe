#pragma once
#define FIELD_SIZE 9

void initialize(char*& field);
std::string getStringField(char* field);
std::string getUserName();
void helloUser(const std::string& username);