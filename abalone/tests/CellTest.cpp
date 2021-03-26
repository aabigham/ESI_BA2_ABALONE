#include "catch.hpp"
#include "Cell.h"

TEST_CASE("Testing methods of the Cell class")
{

    SECTION("Test of method setColor")
    {
        Cell cell = Cell(Position(0, 0), Color::BLACK);
        cell.setColor(Color::WHITE);
        REQUIRE(cell.getColor() == Color::WHITE);
    }

    SECTION("Test of method setColor")
    {
        Cell cell = Cell(Position(0, 0), Color::BLACK);
        cell.removeColor();
        REQUIRE(cell.getColor() == std::nullopt);
    }

}
