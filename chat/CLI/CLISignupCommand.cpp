//
// Created by Маринкин Николай on 17/01/2021.
//

#include "CLISignupCommand.h"
#include <iostream>
#include <string>

const std::string SIGNUP_COMMAND = "/signup";

std::string CLISignupCommand::help() {
    return SIGNUP_COMMAND + " - sign up";
}

bool CLISignupCommand::tryRun(std::string input) {
    if (input != SIGNUP_COMMAND) {
        return false;
    }

    std::string username;
    std::string password;

    this->print("Input username: ", false);
    getline(std::cin, username);

    if (username.size() < 2) {
        throw ((std::string)"Username can not be shorter than 2 symbols");
    }

    this->print("Input password: ", false);
    getline(std::cin, password);

    if (password.size() < 4) {
        throw ((std::string)"Password can not be shorter than 4 symbols");
    }

    this->store->getUserStore()->signUp(username, password);

    if (this->store->getUserStore()->isAuthorized()) {
        this->print("You are logged in as " + username);
    }

    return true;
}

bool CLISignupCommand::isEnabled() {
    return !this->store->getUserStore()->isAuthorized();
}
