//
// Created by Маринкин Николай on 17/01/2021.
//

#ifndef CHAT_CLISIGNUPCOMMAND_H
#define CHAT_CLISIGNUPCOMMAND_H

#include <string>
#include "../Utility/CLI/ICLICommand.h"

class CLISignupCommand: public ICLICommand {
public:
    std::string help() override;
    bool isEnabled() override;
    bool tryRun(std::string input) override;
};


#endif //CHAT_CLISIGNUPCOMMAND_H
