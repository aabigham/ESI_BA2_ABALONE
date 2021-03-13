#include <iostream>
#include "Color.h"
#include "Cell.h"
#include "Position.h"
#include "Game.h"

int main()
{
    /* These are "on the fly" tests */

    Cell cell{Position(0, 0), Color::BLACK};

    std::cout << cell << std::endl;

    std::string str = "Bonjour";
    for (const char &c : str)
    {
        std::cout << c << std::endl;
    }

    Position pos1{0, 0};
    Position pos2{0, -1};
    try
    {
        Direction dir = computeDirection(pos1, pos2);
        std::cout << dir << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    Game game;
    auto positions{game.askAbaPro()};
    for (const auto &currPos : positions)
    {
        std::cout << currPos << std::endl;
    }

    return 0;
}
