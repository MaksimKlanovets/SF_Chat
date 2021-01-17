//
// Created by Маринкин Николай on 17/01/2021.
//

#ifndef CHAT_STORE_H
#define CHAT_STORE_H

#include "UserStore.h"
#include "MessageStore.h"

class Store {
private:
    UserStore* userStore;
    MessageStore* messageStore;
public:
    Store();
    UserStore* getUserStore() const;
    MessageStore* getMessageStore() const;
};


#endif //CHAT_STORE_H
