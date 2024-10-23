//
// Created by Mara Ielciu on 25.04.2024.
//

#ifndef PLAYLIST___POLYMOPRHIC_UNDO___STUB_ACTION_H
#define PLAYLIST___POLYMOPRHIC_UNDO___STUB_ACTION_H


#include "../domain/Dog.h"
#include "../repo/AdminRepo.h"

class Action {
public:
    Action(){};
    virtual ~Action(){};
    virtual void executeUndo()=0;
    virtual void executeRedo()=0;
};

class ActionAdd: public Action{
private:
    Dog addedDog;
    AdminRepo &repo;
public:
    ActionAdd(Dog dog, AdminRepo &repository_n): addedDog{dog}, repo{repository_n}{};
    ~ActionAdd(){};
    void executeUndo() override;
    void executeRedo() override;
};

class ActionRemove: public Action{
private:
    Dog removedDog;
    AdminRepo &repo;
public:
    ActionRemove(Dog dog, AdminRepo& repository_n): removedDog{dog}, repo{repository_n}{};
    ~ActionRemove(){};
    void executeUndo() override;
    void executeRedo() override;
};

class ActionUpdate: public Action{
private:
    Dog oldDog;
    Dog newDog;
    AdminRepo &repo;
public:
    ActionUpdate(Dog odog,Dog ndog, AdminRepo& repository_n): oldDog{odog},newDog{ndog}, repo{repository_n}{};
    ~ActionUpdate(){};
    void executeUndo() override;
    void executeRedo() override;
};

#endif //PLAYLIST___POLYMOPRHIC_UNDO___STUB_ACTION_H
