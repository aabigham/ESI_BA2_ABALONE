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
                colorAtRightPlace = (board.colorAt(position).value() == Color::WHITE);
            else if (y == -4 || y == -3 || (y == -2 && x == 0) || (y == -2 && x == 1) || (y == -2 && x == 2))
                colorAtRightPlace = (board.colorAt(position).value() == Color::BLACK);
            else
                colorAtRightPlace = (!board.colorAt(position).has_value());
        }
        REQUIRE(colorAtRightPlace);
    }

    SECTION("Test count marbles valid, equals 0")
    {
        Board board = Board();
        Position posStart = Position(-2, 1);
        Position posArrival = Position(posStart.getNext(Directions::DOWN_LEFT));
        REQUIRE(board.countMarbles(posStart, computeDirection(posStart, posArrival), 0, Color::WHITE) == 0);
    }

    SECTION("Test count marbles valid, equals 1")
    {
        Board board = Board();
        Position posStart = Position(-2, 2);
        Position posArrival = Position(posStart.getNext(Directions::DOWN_LEFT));
        REQUIRE(board.countMarbles(posStart, computeDirection(posStart, posArrival), 0, Color::WHITE) == 1);
    }

    SECTION("Test count marbles valid, equals 2 ")
    {
        Board board = Board();
        Position posStart = Position(-2, 3);
        Position posArrival = Position(posStart.getNext(Directions::DOWN_LEFT));
        REQUIRE(board.countMarbles(posStart, computeDirection(posStart, posArrival), 0, Color::WHITE) == 2);
    }
    SECTION("Test count marbles valid, equals 3 ")
    {
        Board board = Board();
        Position posStart = Position(-2, 4);
        Position posArrival = Position(posStart.getNext(Directions::DOWN_LEFT));
        REQUIRE(board.countMarbles(posStart, computeDirection(posStart, posArrival), 0, Color::WHITE) == 3);
    }

    SECTION("Test of the canMove inline method one moved")
    {
        Board board = Board();
        Position posStart = Position(-2, 2);
        Position posArrival = Position(posStart.getNext(Directions::DOWN_LEFT));
        REQUIRE(board.canMove(posStart, posArrival, Color::WHITE).size() == 1);
    }

    SECTION("Test of the canMove inline method two moved")
    {
        Board board = Board();
        Position posStart = Position(-2, 3);
        Position posArrival = Position(posStart.getNext(Directions::DOWN_LEFT));
        REQUIRE(board.canMove(posStart, posArrival, Color::WHITE).size() == 1);
    }

    SECTION("Test of the canMove inline method two moved")
    {
        Board board = Board();
        Position posStart = Position(-2, 4);
        Position posArrival = Position(posStart.getNext(Directions::DOWN_LEFT));
        REQUIRE(board.canMove(posStart, posArrival, Color::WHITE).size() == 1);
    }

    SECTION("Test of the canMove inline method empty case")
    {
        Board board = Board();
        Position posStart = Position(-2, 0);
        Position posArrival = Position(posStart.getNext(Directions::DOWN_LEFT));
        REQUIRE(board.canMove(posStart, posArrival, Color::WHITE).size() == 0);
    }

    SECTION("Test of the canMove lateral method threeMoved")
    {
        Board board = Board();
        Position posStart = Position(0, -2);
        Position posArrival = Position(0, -1);
        Position posEnd = Position(2, -2);
        REQUIRE(board.canMove(posStart, posEnd, posArrival, Color::BLACK) == 3);
    }

    SECTION("Test of the canMove lateral method blocked")
    {
        Board board = Board();
        Position posStart = Position(4, -4);
        Position posArrival = Position(4, -3);
        Position posEnd = Position(3, -3);
        REQUIRE(board.canMove(posStart, posEnd, posArrival, Color::BLACK) == -1);
    }

    SECTION("Test of the canMove lateral method blocked")
    {
        Board board = Board();
        Position posStart = Position(1, -4);
        Position posArrival = Position(0, -3);
        Position posEnd = Position(3, -4);
        REQUIRE(board.canMove(posStart, posEnd, posArrival, Color::BLACK) == -1);
    }

    SECTION("Test of the canMove inline 2VS2 method blocked")
    {
        Board board = Board();
        Position posStart = Position(4, -4);
        Position posArrival = Position(posStart.getNext(Directions::UP_LEFT));
        board.move(posStart, posArrival, Color::BLACK);
        board.move(posArrival.getNext(Directions::UP_LEFT),
                   posArrival.getNext(Directions::UP_LEFT).getNext(Directions::UP_LEFT),
                   Color::BLACK);
        board.move(Position(-3, 3), Position(-2, 2), Color::WHITE);

        REQUIRE(board.canMove(Position(2, -2), Position(1, -1), Color::BLACK).size() == 0);
    }

    SECTION("Test of the canMove inline 3VS2 method pushing white marbles")
    {
        Board board = Board();
        Position posStart = Position(4, -4);
        Position posArrival = Position(posStart.getNext(Directions::UP_LEFT));
        board.move(posStart, posArrival, Color::BLACK);
        board.move(posArrival, posArrival.getNext(Directions::UP_LEFT), Color::BLACK);
        board.move(Position(-3, 3), Position(-2, 2), Color::WHITE);

        REQUIRE(board.canMove(Position(2, -2), Position(1, -1), Color::BLACK).size() == 2);
    }
    SECTION("Test of the canMove inline 3VS3 blocked")
    {
        Board board = Board();
        Position posStart = Position(4, -4);
        Position posArrival = Position(posStart.getNext(Directions::UP_LEFT));
        board.move(posStart, posArrival, Color::BLACK);
        board.move(posArrival, posArrival.getNext(Directions::UP_LEFT), Color::BLACK);
        board.move(Position(-4, 4), Position(-3, 3), Color::WHITE);

        REQUIRE(board.canMove(Position(2, -2), Position(1, -1), Color::BLACK).size() == 0);
    }


    SECTION("Test of the canMove inline with positions that are not neighboor")
    {
        Board board = Board();
        Position posStart = Position(0, -3);
        Position posArrival = Position(-3,0);

        REQUIRE(board.canMove(posStart,posArrival, Color::BLACK).size() == 0);
    }

    SECTION("Test of the canMove inline with positions that are not neighboor and posStart marble surrounded")
    {
        Board board = Board();
        Position posStart = Position(1, -3);
        Position posArrival = Position(-3,1);

        REQUIRE(board.canMove(posStart,posArrival, Color::BLACK).size() == 0);
    }

    SECTION("Test move when 3vs2 but blocked by an other marble")
    {
        Board board = Board();

        board.move(Position(0,-3),Position(0,-2),Color::BLACK);
        board.move(Position(0,-2),Position(0,-1),Color::BLACK);
        board.move(Position(0,-1),Position(0,0),Color::BLACK);

        board.move(Position(-1,2),Position(-1,1),Color::WHITE);
        board.move(Position(-1,1),Position(-1,0),Color::WHITE);
        board.move(Position(-1,0),Position(0,-1),Color::WHITE);

        REQUIRE(board.canMove(Position(0,4),Position(0,3), Color::WHITE).size() == 0);

    }

    SECTION("Test move lateral on border")
    {
            Board board=Board();
            board.move(Position(-3,3),Position(-2,2),Position(-3,2),Color::WHITE);
            REQUIRE(board.canMove(Position(-3,2),Position(-2,1),Position(-4,2),Color::WHITE)==2);

    }
}
