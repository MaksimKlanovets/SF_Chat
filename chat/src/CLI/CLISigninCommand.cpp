//
// Created by Маринкин Николай on 16/01/2021.
//

#include "CLISigninCommand.h"
#include <iostream>
#include <string>

const std::string SIGNIN_COMMAND = "/signin";

std::string CLISigninCommand::help() {
    return SIGNIN_COMMAND + " - авторизация";
}

bool CLISigninCommand::tryRun(std::string input) {
    if (input != SIGNIN_COMMAND) {
        return false;
    }

    std::string username;
    std::string password;

    std::cout << "Введите имя пользователя: ";
    std::cin >> username;

    std::cout << "Введите пароль: ";
    std::cin >> password;

    return true;
}

bool CLISigninCommand::isEnabled() {
    return true;
}
