//
// Created by horva on 3/29/2024.
//

#include "UserRepo.h"

void UserRepo::read() {
    ifstream f{this->filename};
    Dog dog;
    if(!f.is_open())
        return;
    while(!f.eof())
    {
        f>>dog;
        this->dogs.push_back(dog);
    }
    f.close();
}

void UserRepo::write() {
    ofstream f{this->filename};
    if(!f.is_open())
        return;
    for_each(dogs.begin(), dogs.end(), [&f](Dog dog){ f<<dog;});
    f.close();
}


void UserRepo::add_dog(Dog dog) {
    auto it = find(this->dogs.begin(), this->dogs.end(), dog);
    if (it == this->dogs.end()) {
        this->dogs.push_back(dog);
    } else
        throw OperationError("The dog is not part of the database.");
}

int UserRepo::get_size() {
    return this->dogs.size();
}

Dog UserRepo::get_element(int position) {
    return this->dogs[position];
}

vector<Dog> UserRepo::get_dogs() {
    return this->dogs;
}
