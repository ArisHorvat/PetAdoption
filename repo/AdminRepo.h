//
// Created by horva on 3/23/2024.
//

#ifndef OOP_A4_5_HORVATARIS_ADMINREPO_H
#define OOP_A4_5_HORVATARIS_ADMINREPO_H

#pragma once
#include <vector>
#include <algorithm>
#include "../domain/Dog.h"
#include "../validators/exceptions.h"

class AdminRepo{
public:
    AdminRepo(string filename): filename{filename}{};

    int get_size();

    vector<Dog> get_dogs();

    void read();

    void write();

    /*
     * This function adds the dog in the repository.
     *      If the dog already exists we return false, otherwise we return true.
     * dog: the dog we want to add
     */
    void add_repo(const Dog& dog);

    /*
     * This function updates the dog from the repository.
     *      If the dog does not exist we return false, otherwise we return true.
     * oldDog: the dog in the database
     * newDog: the dog we would like to replace it with
     */
    void update_repo(Dog oldDog, Dog newDog);

    /*
     * This function removes the dog from the repository.
     *      If the dog does not exist we return false, otherwise we return true.
     * dog: the dog we want to remove
     */
    void remove_repo(Dog dog);

    int find_repo(Dog dog);

    /*
     * This function returns the dog at a given position.
     * position: the position of the element in the Dynamic Array
     */
    Dog get_element(int position);
private:
    vector<Dog> dogs;
    string filename;
};


#endif //OOP_A4_5_HORVATARIS_ADMINREPO_H
