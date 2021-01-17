#include "Store.h"
#include "UsersStore.h"

int main()
{
  UsersStore test;

  test.signUp("petrov", "123");
  test.signUp("Anton", "234");
  test.signUp("Kate", "321");

  test.findByName("Kate");

  test.signIn("Kate", "321");
  return 0;
}
