#include "UsersStore.h"


UsersStore::UsersStore()
{
  _users = {};
  this->currentUser = nullptr;
  this->_userAuth = {};
}

User* UsersStore::findByName(std::string name)
{
  for (auto i = 0; i < _users.size(); i++)
  {
    if (name != _users[i]._name)
    {
      continue;
    }
    return &_users[i];
  }
  return nullptr;
}

User* UsersStore::signUp(std::string name, std::string password)
{
  for (auto i = 0; i < _users.size(); i++)
  {
    if (_users[i]._name != name)
    {
      continue;
    }
    if (_userAuth[i]._password != password)
    {
      return nullptr;
    }
  }
  User temp = {};
  UserAuth tempUserAuth = {};

  
  temp._id = _users.size();
  temp._name = name;

  tempUserAuth._id = _userAuth.size();
  tempUserAuth._password = password;

  _userAuth.push_back(tempUserAuth);
  _users.push_back(temp);


  return &(_users[_users.size()-1]);
}

User* UsersStore::signIn(std::string name, std::string password)
{
  for (auto i = 0; i < _users.size(); i++)
  {
    if (_users[i]._name != name  )
    {
      continue;
    }
    if (_userAuth[i]._password != password)
    {
      return nullptr;
    }
    this->currentUser = &_users[i];
    return &currentUser[i];
  }
  return nullptr;
}

void UsersStore::logOut()
{
  this->currentUser = nullptr;
}

User* UsersStore::findById(int id)
{
  for (auto i = 0; i < _users.size(); i++)
  {
    if (_users[i]._id == id)
    {
      return &_users[i];
    }
  }
  return nullptr;
}




