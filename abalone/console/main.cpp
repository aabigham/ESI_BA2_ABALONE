#include <iostream>
#include "Color.h"
#include "Cell.h"
#include "Position.h"
#include "Game.h"
#include "View.h"
#include "ConsoleView.h"

int main()
{
    /* These are "on the fly" tests */

    Board b;
    ConsoleView cv;
    cv.displayWelcome();
    cv.updateView(b);

    return 0;
}
