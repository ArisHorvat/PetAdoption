//
// Created by horva on 5/31/2024.
//

#ifndef OOP_A10_HORVATARIS_ADOPTIONLIST_H
#define OOP_A10_HORVATARIS_ADOPTIONLIST_H

#include <QAbstractTableModel>
#include "../repo/UserRepo.h"

class AdoptionList: public QAbstractTableModel {
private:
    UserRepo& repo;

public:
    AdoptionList(UserRepo& repo, QObject* parent = nullptr);
    ~AdoptionList(){}

    int rowCount(const QModelIndex &parent = QModelIndex{}) const override;

    int columnCount(const QModelIndex &parent = QModelIndex{}) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    QVariant headerData(int section, Qt::Orientation orientation, int role=Qt::DisplayRole) const;

//    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;
};


#endif //OOP_A10_HORVATARIS_ADOPTIONLIST_H
