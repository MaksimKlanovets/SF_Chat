//
// Created by Маринкин Николай on 17/01/2021.
//

#include "CLISendDirectMessageCommand.h"
#include <string>

const std::string DIRECT_MESSAGE_SYMBOL = "@";

std::string CLISendDirectMessageCommand::help() {
    return DIRECT_MESSAGE_SYMBOL + "username text - send direct message";
}

bool CLISendDirectMessageCommand::tryRun(std::string input) {
    if (input.substr(0, 1) != DIRECT_MESSAGE_SYMBOL) {
        return false;
    }

    std::size_t firstSpacePos = input.find(" ");

    if (
        (firstSpacePos == std::string::npos) ||
        (firstSpacePos == (input.size() - 1))
    ) {
        return false;
    }

    std::string toUsername = input.substr(1, firstSpacePos - 1);
    std::string message = input.substr(firstSpacePos + 1);

    User* toUser = this->store->getUserStore()->findByName(toUsername);

    if (toUser == nullptr) {
        throw((std::string)toUsername + " is unregistered");
    }

    User* currentUser = this->store->getUserStore()->getCurrentUser();

    this->store->getMessageStore()->createMessage(
        this->store->getUserStore()->getCurrentUser(),
        this->store->getMessageStore()->getDirectRoomId(currentUser, toUser),
        message
    );

    this->print("Message to " + toUsername + " sent");

    return true;
}

bool CLISendDirectMessageCommand::isEnabled() {
    return this->store->getUserStore()->isAuthorized();
}
