//
// Created by Маринкин Николай on 17/01/2021.
//

#ifndef CHAT_USER_H
#define CHAT_USER_H

#include <string>

class User {
private:
    std::string name;
    std::string password;
public:
    User(std::string name, std::string password);
    std::string getName();
    bool isCorrectPassword(std::string password);
};


#endif //CHAT_USER_H
