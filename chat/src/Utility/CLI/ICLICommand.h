
//
// Created by Маринкин Николай on 16/01/2021.
//

#ifndef CHAT_ICLICOMMAND_H
#define CHAT_ICLICOMMAND_H

#include <string>

class ICLICommand {
public:
    virtual std::string help() = 0;
    virtual bool isEnabled() = 0;
    virtual bool tryRun(std::string input) = 0;
    virtual ~ICLICommand() = default;
};


#endif //CHAT_ICLICOMMAND_H
