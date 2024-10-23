//
// Created by horva on 4/15/2024.
//

#ifndef OOP_A6_7_HORVATARIS_CSVUSERREPO_H
#define OOP_A6_7_HORVATARIS_CSVUSERREPO_H

#pragma once
#include "UserRepo.h"

class CSVUserRepo: public UserRepo{
public:
    CSVUserRepo(string filename);

    ~CSVUserRepo(){};

    void write() override;

    void display() override;

private:
    string filename;
};


#endif //OOP_A6_7_HORVATARIS_CSVUSERREPO_H
