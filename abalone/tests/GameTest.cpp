#include "catch.hpp"
#include "Game.h"

TEST_CASE("Test of the Game class")
{
    SECTION("Test of the isGameOver method")
    {
        Game game = Game();
        for (int i = 0;i < 6 ; ++i) {
           game.getBoard().addBlackMarbleLost();
        }
        REQUIRE(game.isGameOver());
    }
}
