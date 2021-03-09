#include "catch.hpp"
#include "Cell.h"

TEST_CASE("Testing methods of the Cell class"){

    SECTION("Test of method isAdjacentTo basic"){
        Cell cell=Cell(Position(0,0));
        Cell cell2=Cell(Position(0,-1));
        REQUIRE(cell.isAdjacentTo(cell2));
    }

    SECTION("Test of method isAdjacentTo other values"){
        Cell cell=Cell(Position(1,1));
        Cell cell2=Cell(Position(0,2));
        REQUIRE(cell.isAdjacentTo(cell2));
    }

    SECTION("Test of method isAdjacentTo but is false"){
        Cell cell=Cell(Position(1,1));
        Cell cell2=Cell(Position(3,-2));
        REQUIRE_FALSE(cell.isAdjacentTo(cell2));
    }

    SECTION("Test of method hasSameColor"){
        Cell cell=Cell(Position(0,0),Color::BLACK);
        Cell cell2=Cell(Position(0,-1),Color::BLACK);
        REQUIRE(hasSameColor(cell,cell2));
    }

    SECTION("Test of method hasSameColor but is false"){
        Cell cell=Cell(Position(0,0),Color::BLACK);
        Cell cell2=Cell(Position(0,-1),Color::WHITE);
        REQUIRE_FALSE(hasSameColor(cell,cell2));
    }

    SECTION("Test of method hasSameColor but one with no color"){
        Cell cell=Cell(Position(0,0),Color::BLACK);
        Cell cell2=Cell(Position(0,-1));
        REQUIRE_FALSE(hasSameColor(cell,cell2));
    }

}
