//
// Created by Маринкин Николай on 17/01/2021.
//

#include "CLISignoutCommand.h"
#include <iostream>
#include <string>

const std::string SIGNOUT_COMMAND = "/signout";

std::string CLISignoutCommand::help() {
    return SIGNOUT_COMMAND + " - выход";
}

bool CLISignoutCommand::tryRun(std::string input) {
    if (input != SIGNOUT_COMMAND) {
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

bool CLISignoutCommand::isEnabled() {
    return true;
}
