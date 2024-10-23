//
// Created by horva on 4/15/2024.
//

#ifndef OOP_A6_7_HORVATARIS_HTMLUSERREPO_H
#define OOP_A6_7_HORVATARIS_HTMLUSERREPO_H

#pragma once
#include "UserRepo.h"

class HTMLUserRepo: public UserRepo{
public:
    HTMLUserRepo(string filename);

    ~HTMLUserRepo(){};

    void write() override;

    void display() override;

private:
    string filename;
};

#endif //OOP_A6_7_HORVATARIS_HTMLUSERREPO_H
