#include "Action.h"

void ActionAdd::executeUndo() {
    this->repo.remove_repo(this->addedDog);
}

void ActionAdd::executeRedo() {
    this->repo.add_repo(this->addedDog);
}

void ActionRemove::executeUndo() {
    this->repo.add_repo(this->removedDog);
}

void ActionRemove::executeRedo() {
    this->repo.remove_repo(this->removedDog);
}

void ActionUpdate::executeUndo() {
    this->repo.update_repo(this->newDog, this->oldDog);
}

void ActionUpdate::executeRedo() {
    this->repo.update_repo(this->oldDog, this->newDog);
}
