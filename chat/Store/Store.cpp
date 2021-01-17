//
// Created by Маринкин Николай on 17/01/2021.
//

#include "Store.h"

Store::Store() {
    this->userStore = new UserStore;
    this->messageStore = new MessageStore;
}

UserStore *Store::getUserStore() const {
    return this->userStore;
}

MessageStore *Store::getMessageStore() const {
    return this->messageStore;
}
