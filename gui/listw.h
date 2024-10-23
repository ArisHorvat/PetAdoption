//
// Created by horva on 6/1/2024.
//

#ifndef OOP_A10_HORVATARIS_LISTW_H
#define OOP_A10_HORVATARIS_LISTW_H

#include <QWidget>
#include "AdoptionList.h"

QT_BEGIN_NAMESPACE
namespace Ui { class listw; }
QT_END_NAMESPACE

class listw : public QWidget {
Q_OBJECT

public:
    explicit listw(AdoptionList *model, QWidget *parent = nullptr);

    ~listw() override;

private:
    Ui::listw *ui;
    AdoptionList* model;
};


#endif //OOP_A10_HORVATARIS_LISTW_H
