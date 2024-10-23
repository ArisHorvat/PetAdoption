//
// Created by horva on 4/15/2024.
//

#include "HTMLUserRepo.h"

HTMLUserRepo::HTMLUserRepo(string filename) : UserRepo(filename) {
    this->filename = filename;
}

void HTMLUserRepo::write() {
    ofstream f{this->filename};

    f<<"<!DOCTYPE html>\n<html>\n<head>\n<title>Adoption List</title>\n</head>\n<body>\n<table border=1>\n";
    f<<"<tr>\n<td>Breed</td>\n<td>Name</td>\n<td>Age</td>\n<td>Photo Link</td>\n</tr>\n";
    for_each(this->dogs.begin(), this->dogs.end(),
             [&f](Dog dog)
             {
                f<<"<tr>\n";
                f<<"<td>"<<dog.get_breed()<<"</td>\n";
                f<<"<td>"<<dog.get_name()<<"</td>\n";
                f<<"<td>"<<dog.get_age()<<"</td>\n";
                f<<"<td><a href=\""<<dog.get_photo()<<"\">Link</a></td>\n";
                f<<"</tr>\n";
             });
    f<<"</table>\n</body>\n</html>";
    f.close();
}

void HTMLUserRepo::display() {
    string display_site = "start \"\" \"" + this->filename + "\"";
    system(display_site.c_str());
}
