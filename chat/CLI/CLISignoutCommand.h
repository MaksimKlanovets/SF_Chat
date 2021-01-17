//
// Created by Маринкин Николай on 17/01/2021.
//

#ifndef CHAT_CLISIGNOUTCOMMAND_H
#define CHAT_CLISIGNOUTCOMMAND_H


#include <string>
#include "../Utility/CLI/ICLICommand.h"

class CLISignoutCommand: public ICLICommand {
public:
    explicit CLISignoutCommand(Store* store): ICLICommand(store) {};
    std::string help() override;
    bool isEnabled() override;
    bool tryRun(std::string input) override;
};


#endif //CHAT_CLISIGNOUTCOMMAND_H
