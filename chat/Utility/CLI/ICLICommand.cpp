//
// Created by Маринкин Николай on 17/01/2021.
//

#include "ICLICommand.h"

ICLICommand::ICLICommand(Store* store) {
    this->store = store;
}

bool ICLICommand::isEnabled() {
    return true;
}
