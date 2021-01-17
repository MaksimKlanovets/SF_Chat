//
// Created by Маринкин Николай on 17/01/2021.
//

#include "CLISendPublicMessageCommand.h"
#include <string>

const std::string PUBLIC_MESSAGE_SYMBOL = "#";

std::string CLISendPublicMessageCommand::help() {
    return PUBLIC_MESSAGE_SYMBOL + "channel text - send public message to channel";
}

bool CLISendPublicMessageCommand::tryRun(std::string input) {
    if (input.substr(0, 1) != PUBLIC_MESSAGE_SYMBOL) {
        return false;
    }

    std::size_t firstSpacePos = input.find(" ");

    if (
            (firstSpacePos == std::string::npos) ||
            (firstSpacePos == (input.size() - 1))
            ) {
        return false;
    }

    std::string toChannel = input.substr(1, firstSpacePos - 1);
    std::string message = input.substr(firstSpacePos + 1);

    this->store->getMessageStore()->createMessage(
            this->store->getUserStore()->getCurrentUser(),
            PUBLIC_MESSAGE_SYMBOL + toChannel,
            message
    );

    this->print("Message to channel " + toChannel + " sent");

    return true;
}

bool CLISendPublicMessageCommand::isEnabled() {
    return this->store->getUserStore()->isAuthorized();
}
