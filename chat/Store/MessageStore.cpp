//
// Created by Маринкин Николай on 17/01/2021.
//

#include "MessageStore.h"
#include <vector>
#include <iostream>

void MessageStore::createMessage(User *from, std::string to, std::string text) {
    Message* message = new Message(from, text);

    this->channels.emplace(to, std::vector<Message*>());
    std::vector<Message*>& messages = this->channels[to];

    messages.push_back(message);
}

std::vector<Message *> MessageStore::getChannelMessages(std::string channel) {
    return this->channels[channel];
}

std::vector<Message *> MessageStore::getDirectMessages(User* a, User* b) {
    return this->getChannelMessages(this->getDirectRoomId(a, b));
}

std::string MessageStore::getDirectRoomId(User *a, User *b) {
    if (a->getName() > b->getName()) {
        return "@" + b->getName() + "_" + a->getName();
    }

    return "@" + a->getName() + "_" + b->getName();
}
