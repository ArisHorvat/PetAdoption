//
// Created by horva on 3/23/2024.
//

#ifndef OOP_A4_5_HORVATARIS_SERVICES_H
#define OOP_A4_5_HORVATARIS_SERVICES_H

#pragma once
#include "../repo/AdminRepo.h"
#include "../repo/UserRepo.h"
#include "../repo/CSVUserRepo.h"
#include "../repo/HTMLUserRepo.h"
#include "../domain/Dog.h"
#include "../action/Action.h"

class Services{
public:
    Services(AdminRepo adminRepo, UserRepo *userRepo);

    Services(): adminRepo(""), userRepo(nullptr){};

    vector<Dog> get_dogs_list();

    vector<Dog> get_dogs_adopted();

    AdminRepo get_admin_repo();

    void add_admin(Dog dog);

    void update_admin(Dog oldDog, Dog newDog);

    void remove_admin(Dog dog);

    int find_dog(Dog dog);

    void add_user(Dog dog);

    void write();

    void read_admin();

    void write_admin();

    void display();

    void change_repo(string type);

    /*
     * This function gets the element at the position i,
     *  from the list of dogs depending on the type
     *  position: the position of the element in the Dynamic Array
     *  type: 0 for all the dogs, 1 for the adopted dogs
     */
    Dog get_element(int position, int type);

    /*
     * This function changes the dog we would show the user. If it is at the end
     *      of the list we go back to the beginning.
     *  dog: the dog we show the user
     */
    void continue_user(Dog& dog);

    /*
     * This function returns a list of dogs of a given breed
     *      and with age less than the one give by the user.
     * breed: the breed given by the user
     * age: the age given by the user
     */
    vector<Dog> filter_dogs(string breed, int age);

    void undo();

    void redo();

    void clearRedo();

private:
    AdminRepo adminRepo;
    UserRepo* userRepo;
    vector<Dog> userDogs;
    vector<Action*> undoStack;
    vector<Action*> redoStack;
};


#endif //OOP_A4_5_HORVATARIS_SERVICES_H
