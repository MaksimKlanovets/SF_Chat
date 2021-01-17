//
// Created by Маринкин Николай on 17/01/2021.
//

#ifndef CHAT_MESSAGE_H
#define CHAT_MESSAGE_H

#include "User.h"
#include <string>
#include <ctime>

class Message {
private:
    User* from;
    std::string text;
    std::time_t at;

public:
    Message(User* from, std::string text);
    User* getFrom();
    std::string getText();
};


#endif //CHAT_MESSAGE_H
