//
// Created by Маринкин Николай on 17/01/2021.
//

#include "CLISignoutCommand.h"
#include <iostream>
#include <string>

const std::string SIGNOUT_COMMAND = "/signout";

std::string CLISignoutCommand::help() {
    return SIGNOUT_COMMAND + " - sign out";
}

bool CLISignoutCommand::tryRun(std::string input) {
    if (input != SIGNOUT_COMMAND) {
        return false;
    }

    this->store->getUserStore()->signOut();

    this->print("Successful sign out");

    return true;
}

bool CLISignoutCommand::isEnabled() {
    return this->store->getUserStore()->isAuthorized();
}
