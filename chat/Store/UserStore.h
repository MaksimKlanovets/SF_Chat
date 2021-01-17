//
// Created by Маринкин Николай on 17/01/2021.
//

#ifndef CHAT_USERSTORE_H
#define CHAT_USERSTORE_H

#include "User.h"
#include <string>
#include <vector>

class UserStore {
private:
    User* currentUser = nullptr;
    std::vector<User*> users;

public:
    bool isAuthorized();
    bool hasUser(std::string name);
    User* signUp(std::string name, std::string password);
    User* signIn(std::string name, std::string password);
    void signOut();
    User* findByName(std::string name);
    User* getCurrentUser();
};


#endif //CHAT_USERSTORE_H
