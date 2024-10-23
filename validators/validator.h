//
// Created by horva on 4/14/2024.
//

#ifndef OOP_A6_7_HORVATARIS_VALIDATOR_H
#define OOP_A6_7_HORVATARIS_VALIDATOR_H

#pragma once
#include <string>
#include <vector>
#include <algorithm>
#include "../domain/Dog.h"

using namespace std;

class Validator{
public:
    void is_number(string number);

    void validate_options(string login, vector<string> options);

    static void validate_dog(Dog dog);
};

#endif //OOP_A6_7_HORVATARIS_VALIDATOR_H
