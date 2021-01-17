//
// Created by Маринкин Николай on 17/01/2021.
//

#include "Message.h"

Message::Message(User *from, std::string text) {
    this->from = from;
    this->text = text;

    this->at = std::time(nullptr);
}

User *Message::getFrom() {
    return this->from;
}

std::string Message::getText() {
    return this->text;
}
