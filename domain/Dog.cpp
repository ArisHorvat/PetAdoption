//
// Created by horva on 3/23/2024.
//

#include "Dog.h"


Dog::Dog(const string &breed, const string& name, int age, const string& photo): breed{breed}, name{name}, age{age}, photo{photo} {
}

string Dog::get_breed() const {
    return this->breed;
}

string Dog::get_name() const {
    return this->name;
}

int Dog::get_age() const {
    return this->age;
}

string Dog::get_photo() const {
    return this->photo;
}

string Dog::to_str() const{
    stringstream stream;
    stream<< "Breed: " << this->breed << "; " << "Name: " << this->name + "; "
    <<"Age: " << this->age << "; " << "Photograph: " + this->photo;
    return stream.str();
}

bool Dog::operator==(const Dog &dog) {
    return (this->breed == dog.get_breed() && this->name == dog.get_name()
           && this->age == dog.get_age());
}

Dog &Dog::operator=(const Dog &dog){
    if (this == &dog)
        return *this;

    this->breed = dog.get_breed();
    this->name = dog.get_name();
    this->age = dog.get_age();
    this->photo = dog.get_photo();

    return *this;
}

Dog::Dog() {
    this->breed = "";
    this->name = "";
    this->age = 0;
    this->photo = "";
}

string Dog::to_str_user() const {
    stringstream stream;
    stream<< "Breed: " << this->breed << "; " << "Name: " << this->name + "; "
          <<"Age: " << this->age;
    return stream.str();
}

vector<string> tokenize(string line, char delimiter) {
    vector<string> result;
    stringstream ss(line);
    string token;
    while(getline(ss, token, delimiter))
        result.push_back(token);
    return result;
}


ostream &operator<<(ostream &stream, const Dog &dog) {
    stream<< "Breed: " << dog.breed << "; " << "Name: " << dog.name + "; "
          <<"Age: " << dog.age;
    return stream;
}


istream &operator>>(istream &stream, Dog &dog) {
    string line;
    getline(stream, line);
    vector<string> tokens = tokenize(line, ',');
    if(tokens.size() != 4)
        return stream;
    dog.breed = tokens[0];
    dog.name = tokens[1];
    dog.age = stoi(tokens[2]);
    dog.photo = tokens[3];
    return stream;
}

ofstream &operator<<(ofstream &stream, const Dog &dog) {
    stream<<dog.breed<<","<<dog.name<<","<<dog.age<<","<<dog.photo<<"\n";
    return stream;
}

void Dog::set_breed(string breed){
    this->breed = breed;
}

void Dog::set_name(string name){
    this->name = name;
}

void Dog::set_age(int age){
    this->age = age;
}

void Dog::set_photo(string photo){
    this->photo = photo;
}


