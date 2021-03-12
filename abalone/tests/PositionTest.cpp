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

    SECTION("Testing getNext Sucess")
    {
        Position mid(0,0);
        Position up_left(-1,1);
        Position up_right(0,1);
        Position left(-1,0);
        Position right(1,0);
        Position down_left(0,-1);
        Position down_right(1,-1);
        bool up_left_b = (up_left == mid.getNext(Directions::UP_LEFT));
        bool up_right_b = (up_right == mid.getNext(Directions::UP_RIGHT));
        bool left_b = (left == mid.getNext(Directions::LEFT));
        bool right_b = (right == mid.getNext(Directions::RIGHT));
        bool down_left_b = (down_left == mid.getNext(Directions::DOWN_LEFT));
        bool down_right_b = (down_right == mid.getNext(Directions::DOWN_RIGHT));
        REQUIRE((up_left_b && up_right_b && left_b && right_b && down_left_b && down_right_b));
    }

    SECTION("Testing isNextTo Success")
    {
        Position mid(0,0);
        Position up_left(-1,1);
        Position up_right(0,1);
        Position left(-1,0);
        Position right(1,0);
        Position down_left(0,-1);
        Position down_right(1,-1);
        bool up_left_b = mid.isNextTo(up_left);
        bool up_right_b = mid.isNextTo(up_right);
        bool left_b = mid.isNextTo(left);
        bool right_b = mid.isNextTo(right);
        bool down_left_b = mid.isNextTo(down_left);
        bool down_right_b = mid.isNextTo(down_right);
        REQUIRE((up_left_b && up_right_b && left_b && right_b && down_left_b && down_right_b));
    }

    SECTION("Testing ComputeDirection No Throw")
    {
        Position mid(0,0);
        Position up_left(-1,1);
        Position up_right(0,1);
        Position left(-1,0);
        Position right(1,0);
        Position down_left(0,-1);
        Position down_right(1,-1);
        bool up_left_b = (Directions::UP_LEFT == computeDirection(mid, up_left));
        bool up_right_b = (Directions::UP_RIGHT == computeDirection(mid, up_right));
        bool left_b = (Directions::LEFT == computeDirection(mid, left));
        bool right_b = (Directions::RIGHT == computeDirection(mid, right));
        bool down_left_b = (Directions::DOWN_LEFT == computeDirection(mid, down_left));
        bool down_right_b = (Directions::DOWN_RIGHT == computeDirection(mid, down_right));
        REQUIRE((up_left_b && up_right_b && left_b && right_b && down_left_b && down_right_b));
    }

    SECTION("Testing ComputeDirection Throw Same Positions")
    {
        Position mid(0,0);
        Position mid2(0,0);
        REQUIRE_THROWS(computeDirection(mid, mid2));
    }

    SECTION("Testing ComputeDirection Throw Not Adjacent")
    {
        Position mid(0,0);
        Position other(-2,0);
        REQUIRE_THROWS(computeDirection(mid, other));
    }
}
