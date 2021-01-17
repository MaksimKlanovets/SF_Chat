//
// Created by Маринкин Николай on 17/01/2021.
//

#ifndef CHAT_CLISENDPUBLICMESSAGECOMMAND_H
#define CHAT_CLISENDPUBLICMESSAGECOMMAND_H

#include <string>
#include "../Utility/CLI/ICLICommand.h"

class CLISendPublicMessageCommand: public ICLICommand {
public:
    explicit CLISendPublicMessageCommand(Store* store): ICLICommand(store) {};
    std::string help() override;
    bool isEnabled() override;
    bool tryRun(std::string input) override;
};


#endif //CHAT_CLISENDPUBLICMESSAGECOMMAND_H
