#include "Controller.h"

Controller::Controller(Game game)
    : game_{game},
      view_{}
{
}

void Controller::startGame()
{
    view_.displayWelcome();
    while (!game_.isGameOver())
    {
        game_.play();
    }
}
