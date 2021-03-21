#include <iostream>
#include "Color.h"
#include "Cell.h"
#include "Position.h"
#include "Game.h"
#include "View.h"
#include "ConsoleView.h"
#include "Controller.h"

int main()
{
    /* These are "on the fly" tests */

    Game game;
    ConsoleView cv;
    Controller controller(game, cv);
    controller.startGame();

    return 0;
}
