//
// Created by Маринкин Николай on 17/01/2021.
//

#ifndef CHAT_CLISTATUSCOMMAND_H
#define CHAT_CLISTATUSCOMMAND_H

#include <string>
#include "../Utility/CLI/ICLICommand.h"

class CLIStatusCommand: public ICLICommand {
public:
    explicit CLIStatusCommand(Store* store): ICLICommand(store) {};
    std::string help() override;
    bool tryRun(std::string input) override;
};


#endif //CHAT_CLISTATUSCOMMAND_H
