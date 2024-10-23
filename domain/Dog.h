//
// Created by horva on 3/23/2024.
//

#ifndef OOP_A4_5_HORVATARIS_DOG_H
#define OOP_A4_5_HORVATARIS_DOG_H
#pragma once
#include <string>
#include <sstream>
#include <vector>
#include <fstream>

using namespace std;


class Dog{
public:
    explicit Dog(const string& breed, const string& name, int age, const string& photo);

    Dog();

    string get_breed() const;

    string get_name() const;

    int get_age() const;

    string get_photo() const;

    void set_breed(string breed);

    void set_name(string name);

    void set_age(int age);

    void set_photo(string photo);

    string to_str() const;

    string to_str_user() const;

    Dog &operator=(const Dog &dog);

    bool operator==(const Dog &dog);

    friend ostream &operator<<(ostream &stream, const Dog& dog);

    friend istream &operator>>(istream &stream, Dog& dog);

    friend ofstream &operator<<(ofstream &stream, const Dog& dog);

private:
    string breed;
    string name;
    int age;
    string photo;

};


#endif //OOP_A4_5_HORVATARIS_DOG_H
