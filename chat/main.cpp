#include "Store/Store.h"
#include "Utility/CLI/CLIManager.h"
#include "CLI/CLISignupCommand.h"
#include "CLI/CLISigninCommand.h"
#include "CLI/CLISignoutCommand.h"
#include "CLI/CLIStatusCommand.h"
#include "CLI/CLISendDirectMessageCommand.h"
#include "CLI/CLISendPublicMessageCommand.h"
#include "CLI/CLIReadCommand.h"

int main() {
    CLIManager* cli = new CLIManager();
    Store* store = new Store();

    cli->addCommand(new CLIStatusCommand(store));
    cli->addCommand(new CLISignupCommand(store));
    cli->addCommand(new CLISigninCommand(store));
    cli->addCommand(new CLISignoutCommand(store));
    cli->addCommand(new CLISendDirectMessageCommand(store));
    cli->addCommand(new CLISendPublicMessageCommand(store));
    cli->addCommand(new CLIReadCommand(store));

    cli->start();

    return 0;
}
