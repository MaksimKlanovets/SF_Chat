
//
// Created by Маринкин Николай on 16/01/2021.
//

#ifndef CHAT_ICLICOMMAND_H
#define CHAT_ICLICOMMAND_H

#include "../../Store/Store.h"
#include <string>
#include <iostream>

class ICLICommand {
protected:
    Store* store;
    template<typename T> void print(T text, bool withEnd = true) {
        std::cout << text;

        if (withEnd) {
            std::cout << std::endl;
        }
    };
public:
    explicit ICLICommand(Store* store);
    virtual std::string help() = 0;
    virtual bool isEnabled();
    virtual bool tryRun(std::string input) = 0;
    virtual ~ICLICommand() = default;
};


#endif //CHAT_ICLICOMMAND_H
