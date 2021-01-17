//
// Created by Маринкин Николай on 16/01/2021.
//

#ifndef CHAT_CLISIGNINCOMMAND_H
#define CHAT_CLISIGNINCOMMAND_H

#include <string>
#include "../Utility/CLI/ICLICommand.h"

class CLISigninCommand: public ICLICommand {
public:
    std::string help() override;
    bool isEnabled() override;
    bool tryRun(std::string input) override;
};


#endif //CHAT_CLISIGNINCOMMAND_H
