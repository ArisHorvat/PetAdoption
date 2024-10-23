//
// Created by horva on 3/29/2024.
//

#ifndef OOP_A4_5_HORVATARIS_USERREPO_H
#define OOP_A4_5_HORVATARIS_USERREPO_H

#pragma once
#include <vector>
#include <algorithm>
#include "../domain/Dog.h"
#include "../validators/exceptions.h"

class UserRepo{
protected:
    vector<Dog> dogs;
    string filename;

public:
    UserRepo(string filename): filename{filename}{};

    virtual ~UserRepo(){}

    int get_size();

    virtual void read();

    virtual void write();

    virtual void display(){};

    virtual vector<Dog> get_dogs();

    /*
     * This function returns the dog at a given position.
     * position: the position of the element in the Dynamic Array
     */
    virtual Dog get_element(int position);

    /*
     * This function adds the dog in the repository.
     *      If the dog already exists we return false, otherwise we return true.
     * dog: the dog we want to add
     */
    virtual void add_dog(Dog dog);
};



#endif //OOP_A4_5_HORVATARIS_USERREPO_H
