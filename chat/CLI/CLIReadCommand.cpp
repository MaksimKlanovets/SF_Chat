//
// Created by Маринкин Николай on 17/01/2021.
//

#include "CLIReadCommand.h"
#include <iostream>
#include <string>

const std::string DIRECT_MESSAGE_SYMBOL = "@";
const std::string PUBLIC_MESSAGE_SYMBOL = "#";

std::string CLIReadCommand::help() {
    return (
            DIRECT_MESSAGE_SYMBOL + "username - read direct message from user\n" +
            PUBLIC_MESSAGE_SYMBOL + "channel - read public channel"
            );
}

bool CLIReadCommand::tryRun(std::string input) {
    std::string firstChar = input.substr(0, 1);
    if (firstChar != DIRECT_MESSAGE_SYMBOL && firstChar != PUBLIC_MESSAGE_SYMBOL) {
        return false;
    }

    std::size_t firstSpacePos = input.find(" ");

    if (firstSpacePos != std::string::npos) {
        return false;
    }

    std::vector<Message*> messages;

    if (firstChar == DIRECT_MESSAGE_SYMBOL) {
        std::string toUsername = input.substr(1);

        User* toUser = this->store->getUserStore()->findByName(toUsername);

        if (toUser == nullptr) {
            throw((std::string)toUsername + " is unregistered");
        }

        User* currentUser = this->store->getUserStore()->getCurrentUser();

        messages = this->store->getMessageStore()->getDirectMessages(currentUser, toUser);
    } else {
        messages = this->store->getMessageStore()->getChannelMessages(input);
    }

    if (messages.size() == 0) {
        this->print("Channel " + input + " is empty");
    } else {
        this->print("Channel " + input + " messages:");
        this->printMessages(messages);
    }

    return true;
}

bool CLIReadCommand::isEnabled() {
    return this->store->getUserStore()->isAuthorized();
}

void CLIReadCommand::printMessages(std::vector<Message *>& messages) {
    for (int i = 0; i < messages.size(); i++) {
        Message* message = messages[i];

        this->print(message->getFrom()->getName() + " says:");
        this->print("  " + message->getText());
        this->print("");
    }
}
