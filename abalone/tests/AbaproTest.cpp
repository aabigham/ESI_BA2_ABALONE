#include "catch.hpp"

#include "Abapro.h"
#include "Position.h"

using namespace abapro;

TEST_CASE("Testing methods the Abapro class")
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
}
