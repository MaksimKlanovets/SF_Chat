#pragma once
#include <string>
#include <vector>
struct User
{
public:
  int _id;
  std::string _name;

  };

struct UserAuth
{
    int _id;
    std::string _password;
};

class UsersStore
{
public:
  UsersStore();
  User* findByName(std::string name);//имя пользователя.возврат пользователя если рег
  User* signUp(std::string name,std::string password);//создать пользователя
  User* signIn(std::string name, std::string password); // вернуть пользователя
  void logOut();//выход
  User* findById(int id);

private:
  std::vector<User> _users;
  User* currentUser;
  std::vector<UserAuth> _userAuth;
};

