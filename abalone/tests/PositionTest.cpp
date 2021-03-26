#include "catch.hpp"
#include "Position.h"

TEST_CASE("Testing methods the Position class")
{
    SECTION("Testing isLetterValid True")
    {
        REQUIRE(isLetterValid('A'));
    }

    SECTION("Testing isLetterValid False invalid letter")
    {
        REQUIRE_FALSE(isLetterValid('a'));
    }

    SECTION("Testing isNumberValid True")
    {
        REQUIRE(isNumberValid('1'));
    }

    SECTION("Testing isNumberValid False invalid number")
    {
        REQUIRE_FALSE(isLetterValid('0'));
    }

    SECTION("Testing isPairValid#1 True")
    {
        std::pair<char, char> pair('A', '1');
        REQUIRE(isPairValid(pair));
    }

    SECTION("Testing isPairValid#1 False")
    {
        std::pair<char, char> pair('A', '6');
        REQUIRE_FALSE(isPairValid(pair));
    }

    SECTION("Testing isPairValid#2 True")
    {
        std::pair<char, char> pair('B', '1');
        REQUIRE(isPairValid(pair));
    }

    SECTION("Testing isPairValid#2 False")
    {
        std::pair<char, char> pair('B', '7');
        REQUIRE_FALSE(isPairValid(pair));
    }

    SECTION("Testing isPairValid#3 True")
    {
        std::pair<char, char> pair('C', '1');
        REQUIRE(isPairValid(pair));
    }

    SECTION("Testing isPairValid#3 False")
    {
        std::pair<char, char> pair('C', '8');
        REQUIRE_FALSE(isPairValid(pair));
    }

    SECTION("Testing isPairValid#4 True")
    {
        std::pair<char, char> pair('D', '1');
        REQUIRE(isPairValid(pair));
    }

    SECTION("Testing isPairValid#4 False")
    {
        std::pair<char, char> pair('D', '9');
        REQUIRE_FALSE(isPairValid(pair));
    }

    SECTION("Testing isPairValid#5 True")
    {
        std::pair<char, char> pair('E', '1');
        REQUIRE(isPairValid(pair));
    }

    SECTION("Testing isPairValid#5 False")
    {
        std::pair<char, char> pair('E', 'X');
        REQUIRE_FALSE(isPairValid(pair));
    }

    SECTION("Testing isPairValid#6 True")
    {
        std::pair<char, char> pair('F', '2');
        REQUIRE(isPairValid(pair));
    }

    SECTION("Testing isPairValid#6 False")
    {
        std::pair<char, char> pair('F', '1');
        REQUIRE_FALSE(isPairValid(pair));
    }

    SECTION("Testing isPairValid#7 True")
    {
        std::pair<char, char> pair('G', '3');
        REQUIRE(isPairValid(pair));
    }

    SECTION("Testing isPairValid#7 False")
    {
        std::pair<char, char> pair('G', '2');
        REQUIRE_FALSE(isPairValid(pair));
    }

    SECTION("Testing isPairValid#8 True")
    {
        std::pair<char, char> pair('H', '4');
        REQUIRE(isPairValid(pair));
    }

    SECTION("Testing isPairValid#9 False")
    {
        std::pair<char, char> pair('H', '3');
        REQUIRE_FALSE(isPairValid(pair));
    }

    SECTION("Testing isPairValid#10 True")
    {
        std::pair<char, char> pair('I', '5');
        REQUIRE(isPairValid(pair));
    }

    SECTION("Testing isPairValid#10 False")
    {
        std::pair<char, char> pair('I', '4');
        REQUIRE_FALSE(isPairValid(pair));
    }

    SECTION("Testing isAbaproValid False string Too long")
    {
        REQUIRE_FALSE(isAbaproValid("A1B1BAEAZESZAZE"));
    }

    SECTION("Testing isAbaproValid 4 Char True")
    {
        REQUIRE(isAbaproValid("A1B1"));
    }

    SECTION("Testing isAbaproValid 4 Char False")
    {
        REQUIRE_FALSE(isAbaproValid("AXB1"));
    }

    SECTION("Testing isAbaproValid 6 Char True")
    {
        REQUIRE(isAbaproValid("A1B1C1"));
    }

    SECTION("Testing isAbaproValid 6 Char False")
    {
        REQUIRE_FALSE(isAbaproValid("AXB1CX"));
    }

    SECTION("Testing getLetterYAxis No Throw")
    {
        int y = getLetterYAxis('A');
        REQUIRE(y == -4);
    }

    SECTION("Testing getLetterYAxis Throw")
    {
        REQUIRE_THROWS(getLetterYAxis('X'));
    }

    SECTION("Testing getNumberZAxis No Throw")
    {
        int z = getNumberZAxis('1');
        REQUIRE(z == 4);
    }

    SECTION("Testing getNumberZAxis Throw")
    {
        REQUIRE_THROWS(getNumberZAxis('X'));
    }

    SECTION("Testing abaproToPosition size 4")
    {
        std::string abapro("I8H7");
        std::vector<Position> vExpected{Position(-1, 4), Position(-1, 3)};
        auto result = abaproToPosition(abapro);
        REQUIRE(vExpected == result);
    }

    SECTION("Testing abaproToPosition size 6")
    {
        std::string abapro("C3C5D3");
        std::vector<Position> vExpected{Position(0, -2), Position(2, -2), Position(-1, -1)};
        auto result = abaproToPosition(abapro);
        REQUIRE(vExpected == result);
    }

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
