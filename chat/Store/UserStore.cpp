//
// Created by Маринкин Николай on 17/01/2021.
//

#include "UserStore.h"

bool UserStore::isAuthorized() {
    return this->currentUser != nullptr;
}

User *UserStore::findByName(std::string name) {
    for (int i = 0; i < this->users.size(); i++) {
        User* user = this->users[i];

        if (user->getName() == name) {
            return user;
        }
    }

    return nullptr;
}

bool UserStore::hasUser(std::string name) {
    return this->findByName(name) != nullptr;
}

User *UserStore::signUp(std::string name, std::string password) {
    if (this->hasUser(name)) {
        throw((std::string)"Username " + name + " already used");
    }

    User* user = new User(name, password);
    this->users.push_back(user);
    this->currentUser = user;

    return user;
}

User *UserStore::signIn(std::string name, std::string password) {
    User* user = this->findByName(name);

    if (user == nullptr) {
        throw((std::string)"User " + name + " is not registered");
    }

    if (!user->isCorrectPassword(password)) {
        throw((std::string)"Incorrect password");
    }

    this->currentUser = user;

    return user;
}

void UserStore::signOut() {
    if (!this->isAuthorized()) {
        throw((std::string)"You are not logged in");
    }

    this->currentUser = nullptr;
}

User *UserStore::getCurrentUser() {
    return this->currentUser;
}
