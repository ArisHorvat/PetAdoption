//
// Created by horva on 5/31/2024.
//

#include "AdoptionList.h"

AdoptionList::AdoptionList(UserRepo &repo, QObject *parent): QAbstractTableModel(parent), repo{repo}{
}

int AdoptionList::rowCount(const QModelIndex &parent) const {
    int nrDogs = this->repo.get_size();
    return nrDogs+1;
}

int AdoptionList::columnCount(const QModelIndex &parent) const {
    return 3;
}

QVariant AdoptionList::data(const QModelIndex &index, int role) const {
    int row=index.row();
    int column=index.column();
    vector<Dog> dogs = this->repo.get_dogs();
    if(row == dogs.size()){
        return QVariant();
    }

    Dog dog = dogs[row];

    if(role == Qt::DisplayRole || role == Qt::EditRole){
        if(column == 0){
            return QString::fromStdString(dog.get_breed());
        }
        else if(column==1){
            return QString::fromStdString(dog.get_name());
        }
        else if(column==2){
            return QString::number(dog.get_age());
        }
    }
    return QVariant();
}

QVariant AdoptionList::headerData(int section, Qt::Orientation orientation, int role) const {
    if(role == Qt::DisplayRole){
        if(orientation == Qt::Horizontal){
            switch(section){
                case 0:
                    return "Breed";
                case 1:
                    return "Name";
                case 2:
                    return "Age";
                default:
                    break;
            }
        }
    }
    return QVariant();
}

//bool AdoptionList::setData(const QModelIndex &index, const QVariant &value, int role) {
//    if(role != Qt::EditRole || !index.isValid())
//        return false;
//
//    int dogIndex = index.row();
//    vector<Dog> dogs = this->repo.get_dogs();
//    if(dogIndex == dogs.size()){
//        this->beginInsertRows(QModelIndex{}, dogIndex, dogIndex);
//            if(index.column() == 0){
//                this->repo.add_dog(Dog{value.toString().toStdString(), "", 0, ""});
//            }
//            else if(index.column() == 1){
//                this->repo.add_dog(Dog{"", value.toString().toStdString(), 0, ""});
//            }
//            else if(index.column() == 2){
//                this->repo.add_dog(Dog{"", "", value.toInt(), ""});
//            }
//            this->endInsertRows();
//            return true;
//    }
//
//    Dog& dog = dogs[dogIndex];
//    switch(index.column()){
//        case 0:
//            dog.set_breed(value.toString().toStdString());
//            break;
//        case 1:
//            dog.set_name(value.toString().toStdString());
//            break;
//        case 2:
//            dog.set_age(value.toInt());
//            break;
//    }
//}


