#include <QApplication>

#include "Game.h"
#include "MainWindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Game game;
    MainWindow mw(game);
    mw.show();
    return app.exec();
}
