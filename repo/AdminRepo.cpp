//
// Created by horva on 3/23/2024.
//

#include "AdminRepo.h"

int AdminRepo::get_size() {
    return this->dogs.size();
}

vector<Dog> AdminRepo::get_dogs() {
    return this->dogs;
}

void AdminRepo::add_repo(const Dog& dog) {
    auto it = find(this->dogs.begin(), this->dogs.end(), dog);
    if (it == this->dogs.end())
    {
        this->dogs.push_back(dog);
    }
    else
        throw OperationError("The dog is already in the database.");
}

void AdminRepo::update_repo(Dog oldDog, Dog newDog) {
    auto it = find(this->dogs.begin(), this->dogs.end(), oldDog);
    if (it != this->dogs.end())
    {
        int position = it - this->dogs.begin();
        this->dogs[position] = newDog;
    }
    else
        throw OperationError("The dog is not in the database.");
}

void AdminRepo::remove_repo(Dog dog) {
    auto it = find(this->dogs.begin(), this->dogs.end(), dog);
    if (it != this->dogs.end())
    {
        int position = it - this->dogs.begin();
        this->dogs.erase(dogs.begin() + position);
    }
    else
        throw OperationError("The dog is not in the database.");
}

int AdminRepo::find_repo(Dog dog){
    auto it = find(this->dogs.begin(), this->dogs.end(), dog);
    if(it != this->dogs.end())
    {
        int position = it - this->dogs.begin();
        return position;
    }
    else
        return -1;
}

Dog AdminRepo::get_element(int position) {
    return this->dogs[position];
}

void AdminRepo::read() {
    ifstream f{this->filename};
    Dog dog;
    if(!f.is_open())
        return;
    while(!f.eof())
    {
        f>>dog;
        this->dogs.push_back(dog);
    }
    this->dogs.pop_back();
    f.close();
}

void AdminRepo::write() {
    ofstream f{this->filename};
    if(!f.is_open())
        return;
    for_each(dogs.begin(), dogs.end(), [&f](Dog dog){ f<<dog;});
    f.close();
}
