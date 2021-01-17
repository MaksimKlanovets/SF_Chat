//
// Created by Маринкин Николай on 16/01/2021.
//

#include "CLISigninCommand.h"
#include <iostream>
#include <string>

const std::string SIGNIN_COMMAND = "/signin";

std::string CLISigninCommand::help() {
    return SIGNIN_COMMAND + " - sign in";
}

bool CLISigninCommand::tryRun(std::string input) {
    if (input != SIGNIN_COMMAND) {
        return false;
    }

    std::string username;
    std::string password;

    std::cout << "Input username: ";
    getline(std::cin, username);

    std::cout << "Input password: ";
    getline(std::cin, password);

    this->store->getUserStore()->signIn(username, password);

    return true;
}

bool CLISigninCommand::isEnabled() {
    return !this->store->getUserStore()->isAuthorized();
}
