//
// Created by horva on 3/23/2024.
//

#include "Services.h"

Services::Services(AdminRepo adminRepo, UserRepo* userRepo) : adminRepo(adminRepo), userRepo(userRepo) {
}

AdminRepo Services::get_admin_repo() {
    return this->adminRepo;
}

void Services::add_admin(Dog dog) {
    this->adminRepo.add_repo(dog);
    Action* action = new ActionAdd(dog, this->adminRepo);
    this->undoStack.push_back(action);
}

void Services::update_admin(Dog oldDog, Dog newDog) {
    this->adminRepo.update_repo(oldDog, newDog);
    Action* action = new ActionUpdate(oldDog, newDog, this->adminRepo);
    this->undoStack.push_back(action);
}

void Services::remove_admin(Dog dog) {
    this->adminRepo.remove_repo(dog);
    Action* action = new ActionRemove(dog, this->adminRepo);
    this->undoStack.push_back(action);
}

void Services::add_user(Dog dog) {
    this->userRepo->add_dog(dog);
}

Dog Services::get_element(int position, int type) {
    if(type == 0)
        return this->adminRepo.get_element(position);
    else
        return this->userRepo->get_element(position);
}

int Services::find_dog(Dog dog) {
    return this->adminRepo.find_repo(dog);
}

void Services::continue_user(Dog &dog) {
    if(this->adminRepo.find_repo(dog) == this->adminRepo.get_size() - 1)
        dog = this->adminRepo.get_element(0);
    else
        dog = this->adminRepo.get_element(this->find_dog(dog) + 1);
}

bool predicate(Dog dog, string breed, int age)
{
    return dog.get_age() < age && dog.get_breed() == breed;
}

vector<Dog> Services::filter_dogs(string breed, int age) {
    vector<Dog> filtered_dogs;
    vector<Dog> list_of_dogs = this->get_dogs_list();
    Dog current_dog;
    copy_if(list_of_dogs.begin(), list_of_dogs.end(), std::back_inserter(filtered_dogs), [breed, age](Dog dog){return dog.get_breed()==breed && dog.get_age() < age;});
    if(filtered_dogs.size() == 0)
        throw OperationError("There are no dogs who satisfy the requirements.");
    return filtered_dogs;
}

vector<Dog> Services::get_dogs_list() {
    return this->adminRepo.get_dogs();
}

vector<Dog> Services::get_dogs_adopted() {
    return this->userRepo->get_dogs();
}

void Services::write() {
    this->userRepo->write();
}

void Services::read_admin() {
    this->adminRepo.read();
}

void Services::write_admin() {
    this->adminRepo.write();
}

void Services::display() {
    this->userRepo->display();
}

void Services::change_repo(string type) {
    UserRepo *repo;
    if(type == "CSV"){
        this->userDogs = this->userRepo->get_dogs();
        delete this->userRepo;
        repo = new CSVUserRepo("../adopted_dogs.csv");
    }
    else{
        this->userDogs = this->userRepo->get_dogs();
        delete this->userRepo;
        repo = new HTMLUserRepo("../adopted_dogs.html");
    }
    this->userRepo = repo;
    for(auto dog:this->userDogs)
    {
        this->userRepo->add_dog(dog);
    }
}

void Services::undo() {
    if(this->undoStack.size() == 0)
        throw RepoError("There are no operations to undo");
    Action* action = this->undoStack.back();
    action->executeUndo();
    this->undoStack.pop_back();
    this->redoStack.push_back(action);
}

void Services::redo() {
    if(this->redoStack.size() == 0)
        throw RepoError("There are no operations to redo");
    Action* action = this->redoStack.back();
    action->executeRedo();
    this->redoStack.pop_back();
    this->undoStack.push_back(action);
}

void Services::clearRedo() {
    this->redoStack.clear();
}
