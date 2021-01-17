//
// Created by Маринкин Николай on 17/01/2021.
//

#ifndef CHAT_MESSAGESTORE_H
#define CHAT_MESSAGESTORE_H

#include <map>
#include "Message.h"
#include "User.h"
#include <vector>
class MessageStore {
private:
    std::map<std::string, std::vector<Message*>> channels;
public:
    void createMessage(User* from, std::string to, std::string text);
    std::vector<Message*> getChannelMessages(std::string channel);
    std::vector<Message *> getDirectMessages(User *a, User *b);
    std::string getDirectRoomId(User* a, User* b);
};


#endif //CHAT_MESSAGESTORE_H
