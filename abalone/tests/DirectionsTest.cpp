#include "catch.hpp"
#include "Directions.h"

TEST_CASE("Testing methods the Directions class")
{
    SECTION("Testing getDirection UP_RIGHT")
    {
        int x = 0;
        int y = 1;
        Direction dir = getDirection(x, y);
        REQUIRE(Directions::UP_RIGHT == dir);
    }

    SECTION("Testing getDirection UP_LEFT")
    {
        int x = -1;
        int y = 1;
        Direction dir = getDirection(x, y);
        REQUIRE(Directions::UP_LEFT == dir);
    }

    SECTION("Testing getDirection LEFT")
    {
        int x = -1;
        int y = 0;
        Direction dir = getDirection(x, y);
        REQUIRE(Directions::LEFT == dir);
    }

    SECTION("Testing getDirection RIGHT")
    {
        int x = 1;
        int y = 0;
        Direction dir = getDirection(x, y);
        REQUIRE(Directions::RIGHT == dir);
    }

    SECTION("Testing getDirection DOWN_LEFT")
    {
        int x = 0;
        int y = -1;
        Direction dir = getDirection(x, y);
        REQUIRE(Directions::DOWN_LEFT == dir);
    }

    SECTION("Testing getDirection DOWN_RIGHT")
    {
        int x = 1;
        int y = -1;
        Direction dir = getDirection(x, y);
        REQUIRE(Directions::DOWN_RIGHT == dir);
    }
}
