//
// Created by Маринкин Николай on 17/01/2021.
//

#include "CLISignupCommand.h"
#include <iostream>
#include <string>

const std::string SIGNUP_COMMAND = "/signup";

std::string CLISignupCommand::help() {
    return SIGNUP_COMMAND + " - регистрация";
}

bool CLISignupCommand::tryRun(std::string input) {
    if (input != SIGNUP_COMMAND) {
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

bool CLISignupCommand::isEnabled() {
    return true;
}
