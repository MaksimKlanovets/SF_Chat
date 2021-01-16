#include "../Utility/CLI/CLI.h"
#include "./AuthCli/AuthCli.cpp"

#include <iostream>

class ApplicationCli {
  public:
    ApplicationCli() {
      this->manager = new CLI::Manager();

      CLI::ICli* auth = new AuthCli();

      this->manager->addCli(auth);

      std::cout << "Trololo" << std::endl;
    }

  private:
    CLI::Manager* manager;
};
