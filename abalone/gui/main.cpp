#include <QApplication>

#include "Game.h"
#include "GuiController.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Game game;
    /*MainWindow mw;
    mw.initialize();
    mw.show();*/
    GuiController controller{game};
    controller.initialize();
    controller.startGame();
    return app.exec();
}
