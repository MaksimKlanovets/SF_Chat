#include "../../Utility/CLI/CLI.h"

class AuthCli: public CLI::ICli {
  public:
    AuthCli()
    {
      this->manager = new CLI::Manager();
    }

    char* getHelp()
    {
      return (char *)"AuthCli help";
    }

    bool tryCommand(char* command)
    {
      return false;
    }

  private:
    CLI::Manager* manager;
};
