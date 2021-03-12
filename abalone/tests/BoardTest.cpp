#include "catch.hpp"
#include "Board.h"


TEST_CASE("Testing methods of the Board class")
{

    SECTION("Test of the method isInside")
    {
        Position p1=Position(1,0);
        Board board= Board();
        REQUIRE(board.isInside(p1));
    }

    SECTION("Test of the method isInside but false")
    {
        Position p1=Position(5,0);
        Board board= Board();
        REQUIRE_FALSE(board.isInside(p1));
    }

    SECTION("Test of the getColorAt method with a color")
    {
        Position p1=Position(1,0);
        Board board= Board();
        board.getCellAt(p1).setColor(Color::BLACK);
        Color result= board.colorAt(p1);
        REQUIRE(result==Color::BLACK);
    }

    SECTION("Test of the getColorAt method with no color")
    {
        Position p1=Position(1,0);
        Board board= Board();
        REQUIRE_THROWS(board.colorAt(p1));
    }

}
