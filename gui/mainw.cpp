//
// Created by horva on 5/30/2024.
//

// You may need to build the project (run Qt uic code generator) to get "ui_mainw.h" resolved

#include "mainw.h"
#include "ui_mainw.h"
#include "listw.h"
#include "../validators/exceptions.h"
#include "../validators/validator.h"


mainw::mainw(QWidget *parent) :
        QWidget(parent), ui(new Ui::mainw) {
    ui->setupUi(this);
    //Admin
    this->services.read_admin();
    this->populate_list();
    ui->tableWidget_2->setColumnCount(3);
    ui->tableWidget_2->setHorizontalHeaderLabels({"Breed", "Name", "Age"});

    //User
    this->adoptionModel = new AdoptionList{*this->userRepo};
    this->currentDog = this->services.get_element(0, 0);
    ui->lineEdit_5->setText(QString::fromStdString(this->currentDog.get_breed()));
    ui->lineEdit_6->setText(QString::fromStdString(this->currentDog.get_name()));
    ui->lineEdit_7->setText(QString::number(this->currentDog.get_age()));

    //Admin
    connect(ui->pushButton, &QPushButton::clicked, this, &mainw::add);
    connect(ui->pushButton_2, &QPushButton::clicked, this, &mainw::update);
    connect(ui->pushButton_3, &QPushButton::clicked, this, &mainw::remove);
    QShortcut *undo = new QShortcut(QKeySequence("Ctrl+Z"), this);
    QShortcut *redo = new QShortcut(QKeySequence("Ctrl+Y"), this);
    connect(ui->pushButton_4, &QPushButton::clicked, this, &mainw::undo);
    connect(undo, &QShortcut::activated, this, &mainw::undo);
    connect(ui->pushButton_5, &QPushButton::clicked, this, &mainw::redo);
    connect(redo, &QShortcut::activated, this, &mainw::redo);

    //User
    connect(ui->pushButton_6, &QPushButton::clicked, this, &mainw::adopt);
    connect(ui->pushButton_7, &QPushButton::clicked, this, &mainw::next);
    connect(ui->pushButton_8, &QPushButton::clicked, this, &mainw::list);
    connect(ui->pushButton_9, &QPushButton::clicked, this, &mainw::filter);
}

mainw::~mainw() {
    delete ui;
}

void mainw::populate_list() {
    vector<Dog> dogs = this->services.get_dogs_list();
    QStringList header = {"Breed", "Name", "Age", "Photo Link"};
    ui->tableWidget->clear();
    ui->tableWidget->setColumnCount(header.size());
    ui->tableWidget->setHorizontalHeaderLabels(header);
    for(auto dog: dogs){
        int row = ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(row);
        ui->tableWidget->setItem(row, 0, new QTableWidgetItem(QString::fromStdString(dog.get_breed())));
        ui->tableWidget->setItem(row, 1, new QTableWidgetItem(QString::fromStdString(dog.get_name())));
        ui->tableWidget->setItem(row, 2, new QTableWidgetItem(QString::number(dog.get_age())));
        ui->tableWidget->setItem(row, 3, new QTableWidgetItem(QString::fromStdString(dog.get_photo())));
    }
}

void mainw::add() {
    string breed = ui->lineEdit->text().toStdString();
    string name = ui->lineEdit_2->text().toStdString();
    int age = ui->lineEdit_3->text().toInt();
    string link = ui->lineEdit_4->text().toStdString();

    try{
        Validator::validate_dog(Dog(breed, name, age, link));
        Dog dog = Dog(breed, name, age, link);
        this->services.add_admin(dog);
        this->services.clearRedo();
        ui->lineEdit->clear();
        ui->lineEdit_2->clear();
        ui->lineEdit_3->clear();
        ui->lineEdit_4->clear();

        int row = ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(row);
        ui->tableWidget->setItem(row, 0, new QTableWidgetItem(QString::fromStdString(breed)));
        ui->tableWidget->setItem(row, 1, new QTableWidgetItem(QString::fromStdString(name)));
        ui->tableWidget->setItem(row, 2, new QTableWidgetItem(QString::number(age)));
        ui->tableWidget->setItem(row, 3, new QTableWidgetItem(QString::fromStdString(link)));
    }
    catch(InputError &e){
        QMessageBox::critical(this, "Error", e.what());
    }
    catch(OperationError &e){
        QMessageBox::critical(this, "Error", e.what());
    }
}

void mainw::update() {
    int selectedRow = ui->tableWidget->currentRow();
    if(selectedRow < 0){
        QMessageBox::critical(this, "Error", "Didn't select a row");
        return;
    }
    string oldBreed = ui->tableWidget->item(selectedRow, 0)->text().toStdString();
    string oldName = ui->tableWidget->item(selectedRow, 1)->text().toStdString();
    int oldAge = ui->tableWidget->item(selectedRow, 2)->text().toInt();
    string oldLink = ui->tableWidget->item(selectedRow, 3)->text().toStdString();

    string breed = ui->lineEdit->text().toStdString();
    string name = ui->lineEdit_2->text().toStdString();
    int age = ui->lineEdit_3->text().toInt();
    string link = ui->lineEdit_4->text().toStdString();

    try{
        Validator::validate_dog(Dog(breed, name, age, link));
        this->services.update_admin(Dog(oldBreed, oldName, oldAge, oldLink),
                                    Dog(breed, name, age, link));
        this->services.clearRedo();
        ui->tableWidget->setItem(selectedRow, 0, new QTableWidgetItem(QString::fromStdString(breed)));
        ui->tableWidget->setItem(selectedRow, 1, new QTableWidgetItem(QString::fromStdString(name)));
        ui->tableWidget->setItem(selectedRow, 2, new QTableWidgetItem(QString::number(age)));
        ui->tableWidget->setItem(selectedRow, 3, new QTableWidgetItem(QString::fromStdString(link)));
        ui->lineEdit->clear();
        ui->lineEdit_2->clear();
        ui->lineEdit_3->clear();
        ui->lineEdit_4->clear();
    }
    catch(InputError &e){
        QMessageBox::critical(this, "Error", e.what());
    }
    catch(OperationError &e){
        QMessageBox::critical(this, "Error", e.what());
    }
}

void mainw::remove() {
    int selectedRow = ui->tableWidget->currentRow();
    if(selectedRow < 0){
        QMessageBox::critical(this, "Error", "Didn't select a row");
        return;
    }
    try{
        string breed = ui->tableWidget->item(selectedRow, 0)->text().toStdString();
        string name = ui->tableWidget->item(selectedRow, 1)->text().toStdString();
        int age = ui->tableWidget->item(selectedRow, 2)->text().toInt();
        string link = ui->tableWidget->item(selectedRow, 3)->text().toStdString();
        this->services.remove_admin(Dog(breed, name, age, link));
        this->services.clearRedo();
        ui->tableWidget->removeRow(selectedRow);
    }
    catch(OperationError &e){
        QMessageBox::critical(this, "Error", e.what());
    }
}

void mainw::undo() {
    try{
        this->services.undo();
        this->update_table();
    }
    catch(RepoError &e){
        QMessageBox::critical(this, "Error", e.what());
    }
}

void mainw::redo() {
    try{
        this->services.redo();
        this->update_table();
    }
    catch(RepoError &e){
        QMessageBox::critical(this, "Error", e.what());
    }
}

void mainw::update_table() {
    vector<Dog> dogs = this->services.get_dogs_list();
    ui->tableWidget->clear();
    int row = 0;
    for(auto dog: dogs){
        if(row >= ui->tableWidget->rowCount())
            ui->tableWidget->insertRow(row);
        ui->tableWidget->setItem(row, 0, new QTableWidgetItem(QString::fromStdString(dog.get_breed())));
        ui->tableWidget->setItem(row, 1, new QTableWidgetItem(QString::fromStdString(dog.get_name())));
        ui->tableWidget->setItem(row, 2, new QTableWidgetItem(QString::number(dog.get_age())));
        ui->tableWidget->setItem(row, 3, new QTableWidgetItem(QString::fromStdString(dog.get_photo())));
        row++;
    }
    while(row < ui->tableWidget->rowCount()){
        ui->tableWidget->removeRow(row);
    }
}

void mainw::adopt() {
    string name;
    string breed;
    int age;
    breed = ui->lineEdit_5->text().toStdString();
    name = ui->lineEdit_6->text().toStdString();
    age = ui->lineEdit_7->text().toInt();
    try{
        this->services.add_user(Dog{breed, name, age, ""});
        QMessageBox::information(this, "Successful!", "The dog was added to the adoption list!");
        this->next();
    }
    catch(InputError &e){
        QMessageBox::critical(this, "Error", e.what());
    }
    catch(OperationError &e){
        QMessageBox::critical(this, "Error", e.what());
    }
}

void mainw::next() {
    this->services.continue_user(this->currentDog);
    ui->lineEdit_5->setText(QString::fromStdString(this->currentDog.get_breed()));
    ui->lineEdit_6->setText(QString::fromStdString(this->currentDog.get_name()));
    ui->lineEdit_7->setText(QString::number(this->currentDog.get_age()));
}

void mainw::list() {
    delete this->adoptionModel;
    this->adoptionModel = new AdoptionList{*this->userRepo};
    listw* list = new listw{this->adoptionModel};
    list->show();
}

void mainw::filter() {
    if(ui->lineEdit_8->text().isEmpty()){
        QMessageBox::critical(this, "Error", "Type in a breed!");
    }
    if(ui->lineEdit_9->text().isEmpty()){
        QMessageBox::critical(this, "Error", "Type in an age!");
    }
    string breed = ui->lineEdit_8->text().toStdString();
    int age = ui->lineEdit_9->text().toInt();
    ui->tableWidget_2->setRowCount(0);
    try {
        vector<Dog> dogs = this->services.filter_dogs(breed, age);
        for (auto dog: dogs) {
            int row = ui->tableWidget_2->rowCount();
            ui->tableWidget_2->insertRow(row);
            ui->tableWidget_2->setItem(row, 0, new QTableWidgetItem(QString::fromStdString(dog.get_breed())));
            ui->tableWidget_2->setItem(row, 1, new QTableWidgetItem(QString::fromStdString(dog.get_name())));
            ui->tableWidget_2->setItem(row, 2, new QTableWidgetItem(QString::number(dog.get_age())));
        }
    }
    catch(OperationError &e){
        QMessageBox::critical(this, "Error", e.what());
    }
}
