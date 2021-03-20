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
    cv.updateView(b);

    //Display in Multiline using escape character /n
    /*const char *example2 = "Line1\n"
                           "Line2\n"
                           "Line3\n"
                           "Line4\n";
    std::cout << example2 << std::endl;
    std::cout << "===================================" << std::endl;
    // display in multiline using Raw
    const char *example = R"(Line1 Line2 Line3 Line4)"; //no need to use escape character  /n
    std::cout << example << std::endl;

    std::cin.get();*/

    return 0;
}
