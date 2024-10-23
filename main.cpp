#include <QApplication>
#include <QPushButton>
#include "gui/mainw.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    mainw widget;
    widget.show();
    return QApplication::exec();
}
