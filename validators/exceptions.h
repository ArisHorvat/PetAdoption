//
// Created by horva on 4/14/2024.
//

#ifndef OOP_A6_7_HORVATARIS_EXCEPTIONS_H
#define OOP_A6_7_HORVATARIS_EXCEPTIONS_H

#pragma once
#include <exception>
#include <string>

using namespace std;

class InputError: public exception{
private:
    const char* message;

public:
    InputError(const char* message): message{message}{};

    const char *what() const noexcept override{return this->message;};
};

class OperationError: public exception{
private:
    const char* message;

public:
    OperationError(char* message): message{message} {};

    const char *what() const noexcept override {return this->message;};
};

class RepoError: public exception{
private:
    const char* message;

public:
    RepoError(char* message): message{message}{};
    const char *what() const noexcept override {return this->message;};
};

#endif //OOP_A6_7_HORVATARIS_EXCEPTIONS_H
