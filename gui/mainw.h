//
// Created by horva on 5/30/2024.
//

#ifndef OOP_A10_HORVATARIS_MAINW_H
#define OOP_A10_HORVATARIS_MAINW_H

#include <QMainWindow>
#include <QWidget>
#include <QMessageBox>
#include <QShortcut>
#include "../services/Services.h"
#include "AdoptionList.h"


QT_BEGIN_NAMESPACE
namespace Ui { class mainw; }
QT_END_NAMESPACE

class mainw : public QWidget {
Q_OBJECT

public:
    explicit mainw(QWidget *parent = nullptr);

    ~mainw() override;

private:
    Ui::mainw *ui;
    UserRepo *userRepo = new UserRepo("../adopted_dogs.txt");
    Services services = Services(AdminRepo("../original_dogs.txt"), userRepo);
    AdoptionList* adoptionModel;
    Dog currentDog;
    void populate_list();
    void update_table();

public slots:
    //Admin slots
    void add();

    void update();

    void remove();

    void undo();

    void redo();

    //User slots
    void adopt();

    void next();

    void list();

    void filter();
};


#endif //OOP_A10_HORVATARIS_MAINW_H
