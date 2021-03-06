#include "catch.hpp"
#include "Position.h"

TEST_CASE("Testing methods the Position class")
{
    SECTION("Testing UP_LEFT getNext Sucess")
    {
        Position mid(0, 0);
        Position up_left(-1, 1);
        bool up_left_b = (up_left == mid.getNext(Directions::UP_LEFT));
        REQUIRE(up_left_b);
    }

    SECTION("Testing UP_RIGHT getNext Sucess")
    {
        Position mid(0, 0);
        Position up_right(0, 1);
        bool up_right_b = (up_right == mid.getNext(Directions::UP_RIGHT));
        REQUIRE(up_right_b);
    }

    SECTION("Testing LEFT getNext Sucess")
    {
        Position mid(0, 0);
        Position left(-1, 0);
        bool left_b = (left == mid.getNext(Directions::LEFT));
        REQUIRE(left_b);
    }

    SECTION("Testing RIGHT getNext Sucess")
    {
        Position mid(0, 0);
        Position right(1, 0);
        bool right_b = (right == mid.getNext(Directions::RIGHT));
        REQUIRE(right_b);
    }

    SECTION("Testing DOWN_LEFT getNext Sucess")
    {
        Position mid(0, 0);
        Position down_left(0, -1);
        bool down_left_b = (down_left == mid.getNext(Directions::DOWN_LEFT));
        REQUIRE(down_left_b);
    }

    SECTION("Testing DOWN_RIGHT getNext Sucess")
    {
        Position mid(0, 0);
        Position down_right(1, -1);
        bool down_right_b = (down_right == mid.getNext(Directions::DOWN_RIGHT));
        REQUIRE(down_right_b);
    }

    SECTION("Testing isNextTo UP_LEFT Success")
    {
        Position mid(0, 0);
        Position up_left(-1, 1);
        bool up_left_b = mid.isNextTo(up_left);
        REQUIRE(up_left_b);
    }

    SECTION("Testing isNextTo UP_RIGHT Success")
    {
        Position mid(0, 0);
        Position up_right(0, 1);
        bool up_right_b = mid.isNextTo(up_right);
        REQUIRE(up_right_b);
    }

    SECTION("Testing isNextTo LEFT Success")
    {
        Position mid(0, 0);
        Position left(-1, 0);
        bool left_b = mid.isNextTo(left);
        REQUIRE(left_b);
    }

    SECTION("Testing isNextTo RIGHT Success")
    {
        Position mid(0, 0);
        Position right(1, 0);
        bool right_b = mid.isNextTo(right);
        REQUIRE(right_b);
    }

    SECTION("Testing isNextTo DOWN_LEFT Success")
    {
        Position mid(0, 0);
        Position down_left(0, -1);
        bool down_left_b = mid.isNextTo(down_left);
        REQUIRE(down_left_b);
    }

    SECTION("Testing isNextTo DOWN_RIGHT Success")
    {
        Position mid(0, 0);
        Position down_right(1, -1);
        bool down_right_b = mid.isNextTo(down_right);
        REQUIRE(down_right_b);
    }

    SECTION("Testing ComputeDirection UP_LEFT No Throw")
    {
        Position mid(0, 0);
        Position up_left(-1, 1);
        bool up_left_b = (Directions::UP_LEFT == computeDirection(mid, up_left));
        REQUIRE(up_left_b);
    }

    SECTION("Testing ComputeDirection UP_RIGHT No Throw")
    {
        Position mid(0, 0);
        Position up_right(0, 1);
        bool up_right_b = (Directions::UP_RIGHT == computeDirection(mid, up_right));
        REQUIRE(up_right_b);
    }

    SECTION("Testing ComputeDirection LEFT No Throw")
    {
        Position mid(0, 0);
        Position left(-1, 0);
        bool left_b = (Directions::LEFT == computeDirection(mid, left));
        REQUIRE(left_b);
    }

    SECTION("Testing ComputeDirection RIGHT No Throw")
    {
        Position mid(0, 0);
        Position right(1, 0);
        bool right_b = (Directions::RIGHT == computeDirection(mid, right));
        REQUIRE(right_b);
    }

    SECTION("Testing ComputeDirection DOWN_LEFT No Throw")
    {
        Position mid(0, 0);
        Position down_left(0, -1);
        bool down_left_b = (Directions::DOWN_LEFT == computeDirection(mid, down_left));
        REQUIRE(down_left_b);
    }

    SECTION("Testing ComputeDirection DOWN_RIGHT No Throw")
    {
        Position mid(0, 0);
        Position down_right(1, -1);
        bool down_right_b = (Directions::DOWN_RIGHT == computeDirection(mid, down_right));
        REQUIRE(down_right_b);
    }

    SECTION("Testing ComputeDirection Throw Same Positions")
    {
        Position mid(0, 0);
        Position mid2(0, 0);
        REQUIRE_THROWS(computeDirection(mid, mid2));
    }

    SECTION("Testing ComputeDirection Throw Not Adjacent")
    {
        Position mid(0, 0);
        Position other(-2, 0);
        REQUIRE_NOTHROW(computeDirection(mid, other));
    }
}
