#include "catch.hpp"
#include "Board.h"

TEST_CASE("Testing methods of the Board class")
{
    SECTION("Test of the method isInside")
    {
        Position p1(1, 0);
        Board board = Board();
        REQUIRE(board.isInside(p1));
    }

    SECTION("Test of the method isInside but false")
    {
        Position p1(5, 0);
        Board board = Board();
        REQUIRE_FALSE(board.isInside(p1));
    }

    SECTION("Test of the getColorAt method with a color")
    {
        Position p1(1, 0);
        Board board = Board();
        board.getCellAt(p1).setColor(Color::BLACK);
        std::optional<Color> result = board.colorAt(p1);
        REQUIRE(result.value() == Color::BLACK);
    }

    SECTION("Test of the getColorAt method with no color")
    {
        Position p1(1, 0);
        Board board = Board();
        REQUIRE(board.colorAt(p1) == std::nullopt);
    }

    SECTION("Test of the right color initialisation in the Constructor of board ")
    {
        Board board = Board();
        bool colorAtRightPlace = true;
        for (const auto &cell : board.getCells())
        {
            Position position = cell.first;
            int y = position.getY();
            int x = position.getX();
            if (y == 4 || y == 3 || (y == 2 && x == -2) || (y == 2 && x == -1) || (y == 2 && x == 0))
            {
                colorAtRightPlace = (board.colorAt(position).value() == Color::BLACK);
            }
            else if (y == -4 || y == -3 || (y == -2 && x == 0) || (y == -2 && x == 1) || (y == -2 && x == 2))
            {
                colorAtRightPlace = (board.colorAt(position).value() == Color::WHITE);
            }
            else
            {
                colorAtRightPlace = (!board.colorAt(position).has_value());
            }
        }
        REQUIRE(colorAtRightPlace);
    }
}
