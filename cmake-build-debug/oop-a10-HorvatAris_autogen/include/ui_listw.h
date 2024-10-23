/********************************************************************************
** Form generated from reading UI file 'listw.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LISTW_H
#define UI_LISTW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_listw
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QTableView *tableView;

    void setupUi(QWidget *listw)
    {
        if (listw->objectName().isEmpty())
            listw->setObjectName("listw");
        listw->resize(335, 263);
        verticalLayout = new QVBoxLayout(listw);
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(listw);
        label->setObjectName("label");

        verticalLayout->addWidget(label);

        tableView = new QTableView(listw);
        tableView->setObjectName("tableView");

        verticalLayout->addWidget(tableView);


        retranslateUi(listw);

        QMetaObject::connectSlotsByName(listw);
    } // setupUi

    void retranslateUi(QWidget *listw)
    {
        listw->setWindowTitle(QCoreApplication::translate("listw", "listw", nullptr));
        label->setText(QCoreApplication::translate("listw", "Adoption List:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class listw: public Ui_listw {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LISTW_H
