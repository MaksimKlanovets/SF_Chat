#include "Utility/CLI/CLIManager.h"
#include "CLI/CLISignupCommand.h"
#include "CLI/CLISigninCommand.h"
#include "CLI/CLISignoutCommand.h"

#include <iostream>

int main() {
    std::cout << "Chat Application Start" << std::endl;

    CLIManager* cli = new CLIManager();

    cli->addCommand(new CLISignupCommand());
    cli->addCommand(new CLISigninCommand());
    cli->addCommand(new CLISignoutCommand());

    cli->start();

    return 0;
}
