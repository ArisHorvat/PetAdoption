//
// Created by horva on 4/15/2024.
//

#include "CSVUserRepo.h"

CSVUserRepo::CSVUserRepo(string filename) : UserRepo(filename) {
    this->filename = filename;
}

void CSVUserRepo::write() {
    ofstream f{this->filename};

    for_each(this->dogs.begin(), this->dogs.end(), [&f](Dog dog){f<<dog;});
    f.close();
}

void CSVUserRepo::display() {
    string display_notepad = "notepad \"" + this->filename + "\"";
    system(display_notepad.c_str());
}


