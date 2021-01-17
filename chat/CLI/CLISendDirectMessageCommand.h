//
// Created by Маринкин Николай on 17/01/2021.
//

#ifndef CHAT_CLISENDDIRECTMESSAGECOMMAND_H
#define CHAT_CLISENDDIRECTMESSAGECOMMAND_H

#include <string>
#include "../Utility/CLI/ICLICommand.h"

class CLISendDirectMessageCommand: public ICLICommand {
public:
    explicit CLISendDirectMessageCommand(Store* store): ICLICommand(store) {};
    std::string help() override;
    bool isEnabled() override;
    bool tryRun(std::string input) override;
};

#endif //CHAT_CLISENDDIRECTMESSAGECOMMAND_H
