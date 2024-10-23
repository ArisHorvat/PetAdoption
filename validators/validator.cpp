//
// Created by horva on 4/14/2024.
//

#include "validator.h"
#include "exceptions.h"

void Validator::is_number(string number) {
    for(const char &c: number){
        if(std::isdigit(c)==0)
            throw InputError("Invalid input for number.");
    }
}

void Validator::validate_options(string login, vector<string> options) {
    bool verify = false;
    for_each(options.begin(), options.end(), [&login, &verify](string option){if(login==option) verify=true;});
    if(!verify)
        throw InputError("Invalid input.");
}

void Validator::validate_dog(Dog dog) {
    int nr_e=0;
    if(dog.get_breed().length() < 3)
        nr_e++;
    if(dog.get_name().length() < 2)
        nr_e++;
    if(dog.get_photo().length() < 5)
        nr_e++;
    if(dog.get_age() < 0)
        nr_e++;
    if(nr_e == 1)
        throw InputError("One of the dog's attributes are not valid!");
    else if(nr_e == 2)
        throw InputError("Two of the dog's attributes are not valid!");
    else if(nr_e == 3)
        throw InputError("Three of the dog's attributes are not valid!");
    else if(nr_e == 4)
        throw InputError("Four of the dog's attributes are not valid!");
}
