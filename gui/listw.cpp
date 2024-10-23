//
// Created by horva on 6/1/2024.
//

// You may need to build the project (run Qt uic code generator) to get "ui_listw.h" resolved

#include "listw.h"
#include "ui_listw.h"


listw::listw(AdoptionList *model, QWidget *parent) :
        QWidget(parent), model(model), ui(new Ui::listw) {
    ui->setupUi(this);
    ui->tableView->setModel(model);
}

listw::~listw() {
    delete ui;
}
