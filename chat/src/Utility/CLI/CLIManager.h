//
// Created by Маринкин Николай on 16/01/2021.
//

#ifndef CHAT_CLIMANAGER_H
#define CHAT_CLIMANAGER_H

#include <vector>
#include <string>
#include "ICLICommand.h"

enum EStatus {
    Exit = 0,
    Success = 1,
    Failed = 2,
};

class CLIManager {
private:
    std::vector<ICLICommand*> commands;
    EStatus runCommand(std::string input);
    void printWelcome();
    void printHelp();

public:
    void start();
    void addCommand(ICLICommand* command);
};


#endif //CHAT_CLIMANAGER_H
