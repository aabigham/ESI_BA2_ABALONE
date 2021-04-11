#include <iostream>
#include <QApplication>
#include <QPushButton>
#include "MainWindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow mw;
    mw.setFixedSize(mw.size());
    mw.show();

    return app.exec();
}
