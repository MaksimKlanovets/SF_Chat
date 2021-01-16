#include "./Store/Store.cpp"
#include "./CLI/ApplicationCli.cpp"

int main() {
  Store *store = new Store();
  ApplicationCli *cli = new ApplicationCli();

  return 0;
}
