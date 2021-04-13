#include <iostream>
#include <QApplication>
#include <QPushButton>
#include "Game.h"
#include "MainWindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Game game;
    MainWindow mw(game);
    mw.setFixedSize(mw.size());
    mw.show();

    return app.exec();
}
