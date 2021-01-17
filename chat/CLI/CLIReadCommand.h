//
// Created by Маринкин Николай on 17/01/2021.
//

#ifndef CHAT_CLIREADCOMMAND_H
#define CHAT_CLIREADCOMMAND_H

#include <string>
#include "../Utility/CLI/ICLICommand.h"

class CLIReadCommand: public ICLICommand {
private:
    void printMessages(std::vector<Message*>& messages);
public:
    explicit CLIReadCommand(Store* store): ICLICommand(store) {};
    std::string help() override;
    bool isEnabled() override;
    bool tryRun(std::string input) override;
};


#endif //CHAT_CLIREADCOMMAND_H
