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

        std::cout << "Введите команду: ";
        std::cin >> input;

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

        const bool isSuccess = command->tryRun(input);

        if (isSuccess) {
            return EStatus::Success;
        }
    }

    std::cout << "Неизвестная команда" << std::endl;

    return EStatus::Failed;
}

void CLIManager::addCommand(ICLICommand *command) {
    this->commands.push_back(command);
}

void CLIManager::printHelp() {
    std::cout << HELP_COMMAND + " - выводит эту помощь" << std::endl;
    std::cout << EXIT_COMMAND + " - выход из приложения" << std::endl;

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
    std::cout << "Добро пожаловать в приложение чата" << std::endl;
    std::cout << "Для просмотра доступных команд введите /help" << std::endl;
}
