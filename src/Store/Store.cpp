#include "./UsersStore/UsersStore.cpp"

/**
 * Точка входа в состояние приложения
 *
 * Тут нужно инициализировать конкретные сторы
 */
class Store {
  public:
    UsersStore users;
};
