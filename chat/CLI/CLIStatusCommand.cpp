//
// Created by Маринкин Николай on 17/01/2021.
//

#include "CLIStatusCommand.h"
#include <string>

const std::string STATUS_COMMAND = "/status";

std::string CLIStatusCommand::help() {
    return STATUS_COMMAND + " - print current status";
}

bool CLIStatusCommand::tryRun(std::string input) {
    if (input != STATUS_COMMAND) {
        return false;
    }

    User* user = this->store->getUserStore()->getCurrentUser();

    this->print("Status:");

    if (user != nullptr) {
        this->print("You are logged in as " + user->getName());
    } else {
        this->print("You are not logged in");
    }

    return true;
}
