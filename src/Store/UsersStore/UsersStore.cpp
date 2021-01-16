struct User
{
  const int id;
  const char* name;
};

/**
 * Тут хранятся пользователи, но не их пароли
 */
class UsersStore {
  public:
    User findByName(char* name);
};
