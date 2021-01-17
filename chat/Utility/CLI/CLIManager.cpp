//
// Created by Маринкин Николай on 16/01/2021.
//

#include <iostream>
#include <string>
#include "CLIManager.h"

const std::string EXIT_COMMAND = "/exit";
const std::string HELP_COMMAND = "/help";

void CLIManager::start() {
    this->printWelcome();

    while (true)
    {
        std::string input;

        std::cout << "Input command: ";
        getline(std::cin, input);

        const EStatus result = this->runCommand(input);

        if (result == EStatus::Exit) {
            return;
        }
    }
}

EStatus CLIManager::runCommand(std::string input) {
    if (input == EXIT_COMMAND) {
        return EStatus::Exit;
    }

    if (input == HELP_COMMAND) {
        this->printHelp();

        return EStatus::Success;
    }

    for (int i = 0; i < this->commands.size(); i++) {
        ICLICommand* command = this->commands[i];

        if (!command->isEnabled()) {
            continue;
        }

        bool isSuccess;

        try {
            isSuccess = command->tryRun(input);
        } catch (std::string error) {
            std::cout << error << std::endl;

            return EStatus::Failed;
        }

        if (isSuccess) {
            return EStatus::Success;
        }
    }

    std::cout << "Unknown command " << input << std::endl;

    return EStatus::Failed;
}

void CLIManager::addCommand(ICLICommand *command) {
    this->commands.push_back(command);
}

void CLIManager::printHelp() {
    std::cout << HELP_COMMAND + " - print this help" << std::endl;
    std::cout << EXIT_COMMAND + " - exit from application" << std::endl;

    for (int i = 0; i < this->commands.size(); i++) {
        ICLICommand* command = this->commands[i];

        if (!command->isEnabled()) {
            continue;
        }

        std::cout << command->help() << std::endl;
    }

    std::cout << std::endl;
}

void CLIManager::printWelcome() {
    std::cout << "Welcome to the Chat Application" << std::endl;
    std::cout << "For help print /help" << std::endl;
}
