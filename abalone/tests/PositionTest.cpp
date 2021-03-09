#include "catch.hpp"
#include "Position.h"

TEST_CASE("Testing methods the Position class")
{
    SECTION("Testing validateLetter No Throw")
    {
        REQUIRE_NOTHROW(validateLetter('A'));
    }
    SECTION("Testing validateLetter Throw invalid letter")
    {
        REQUIRE_THROWS(validateLetter('a'));
    }
    SECTION("Testing validateNumber No Throw")
    {
        REQUIRE_NOTHROW(validateNumber('1'));
    }
    SECTION("Testing validateNumber Throw invalid number")
    {
        REQUIRE_THROWS(validateLetter('0'));
    }
    SECTION("Testing validateABAPRO Throw string Too long")
    {
        REQUIRE_THROWS(validateABAPRO("A1B1BAEAZESZAZE"));
    }
    SECTION("Testing validateABAPRO 4 Char No Throw")
    {
        REQUIRE_NOTHROW(validateABAPRO("A1B1"));
    }
    SECTION("Testing validateABAPRO 4 Char Throw")
    {
        REQUIRE_THROWS(validateABAPRO("AXB1"));
    }
    SECTION("Testing validateABAPRO 6 Char No Throw")
    {
        REQUIRE_NOTHROW(validateABAPRO("A1B1C1"));
    }
    SECTION("Testing validateABAPRO 6 Char Throw")
    {
        REQUIRE_THROWS(validateABAPRO("AXB1CX"));
    }

    /*SECTION("Testing getNext")
    {
        Position mid(0,0);
        Position top_left(-1,1);
        Position top_right(0,0);
        Position left(0,0);
        Position right(0,0);
        Position down_left(0,0);
        Position down_right(0,0);
        REQUIRE_THROWS(validateABAPRO("AXB1CX"));
    }*/
}
