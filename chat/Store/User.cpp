//
// Created by Маринкин Николай on 17/01/2021.
//

#include "User.h"

User::User(std::string name, std::string password) {
    this->name = name;
    this->password = password;
}

std::string User::getName() {
    return this->name;
}

bool User::isCorrectPassword(std::string password) {
    return password == this->password;
}
