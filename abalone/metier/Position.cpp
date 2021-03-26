#include <iostream>
#include "Position.h"
#include "Directions.h"


Position::Position(int x, int y)
    : x_{x},
      y_{y},
      z_{-x - y}
{
    if (x_ + y_ + z_ != 0)
        throw std::invalid_argument("The sum of all the axis does not equal 0.");
}

Position::Position(int x, int y, int z)
    : x_{x},
      y_{y},
      z_{z}
{
    if (x_ + y_ + z_ != 0)
        throw std::invalid_argument("The sum of all the axis does not equal 0.");
}

Position::Position(const Position &pos)
    : x_{pos.getX()},
      y_{pos.getY()},
      z_{pos.getZ()}
{
    if (x_ + y_ + z_ != 0)
        throw std::invalid_argument("The sum of all the axis does not equal 0.");
}

Position Position::getNext(const Direction dir) const
{
    return Position(x_ + std::get<0>(dir), y_ + std::get<1>(dir));
}

bool Position::isNextTo(const Position pos) const
{
    if (getNext(Directions::LEFT) == pos
            || getNext(Directions::DOWN_LEFT) == pos
            || getNext(Directions::UP_LEFT) == pos
            || getNext(Directions::RIGHT) == pos
            || getNext(Directions::DOWN_RIGHT) == pos
            || getNext(Directions::UP_RIGHT) == pos)
        return true;
    else
        return false;
}

const Direction computeDirection(Position posStart, Position posArrival) // throws
{
    if (posStart == posArrival)
        throw std::invalid_argument("The positions are the same or are not adjacent.");

    int x_st = posStart.getX();
    int y_st = posStart.getY();
    int x_ar = posArrival.getX();
    int y_ar = posArrival.getY();

    int x_res = x_st == x_ar  ? 0 : x_st < x_ar ? 1 : -1;
    int y_res = y_st == y_ar  ? 0 : y_st < y_ar ? 1 : -1;

    return getDirection(x_res, y_res);
}

int getLetterYAxis(char letter)
{
    for (const auto &[c, i] : Position::letters_y)
        if (c == letter)
            return i;
    throw std::invalid_argument("The letter does not exist.");
}

int getNumberZAxis(int number)
{
    for (const auto &[c, i] : Position::numbers_z)
        if (c == number)
            return i;
    throw std::invalid_argument("The number does not exist.");
}

bool isLetterValid(const char letter)
{
    for (const auto &[c, i] : Position::letters_y)
        if (c == letter)
            return true;
    return false;
}

bool isNumberValid(const char number)
{
    for (const auto &[c, i] : Position::numbers_z)
        if (c == number)
            return true;
    return false;
}

bool isPairValid(const std::pair<char, char> pair)
{
    char letter = pair.first;
    char number = pair.second;
    if(!(isLetterValid(letter) && isNumberValid(number)))
        return false;

    int n = number - 48; // Converts the char to int
    switch (letter) {
    case 'A':
        return (n <= 5);
    case 'B':
        return (n <= 6);
    case 'C':
        return (n <= 7);
    case 'D':
        return (n <= 8);
    case 'E':
        return (n <= 9);
    case 'F':
        return (n >= 2);
    case 'G':
        return (n >= 3);
    case 'H':
        return (n >= 4);
    case 'I':
        return (n >= 5);
    default :
        return false;
    }
}

bool isAbaproValid(const std::string abapro)
{
    int size = abapro.size();
    if (size != 4 && size != 6)
        return false;
    // Checking each pair
    for (int i = 0; i < size / 2; i += 2)
    {
        std::pair<char, char> currPair
                = std::make_pair(abapro.at(i), abapro.at(i + 1));
        if(!isPairValid(currPair))
            return false;
    }
    return true;
}

std::vector<Position> abaproToPosition(const std::string abapro) // throws
{
    if(!isAbaproValid(abapro))
        throw std::invalid_argument("The abapro input is not valid.");

    std::vector<Position> ret;
    // p1
    int y1 = getLetterYAxis(abapro.at(0));
    int z1 = getNumberZAxis(abapro.at(1));
    int x1 = 0 - (y1 + z1);
    Position p1{x1, y1, z1};
    ret.push_back(p1);
    // p2
    int y2 = getLetterYAxis(abapro.at(2));
    int z2 = getNumberZAxis(abapro.at(3));
    int x2 = 0 - (y2 + z2);
    Position p2{x2, y2, z2};
    ret.push_back(p2);
    // p3
    if (abapro.size() == 6)
    {
        int y3 = getLetterYAxis(abapro.at(4));
        int z3 = getNumberZAxis(abapro.at(5));
        int x3 = 0 - (y3 + z3);
        Position p3{x3, y3, z3};
        ret.push_back(p3);
        return ret;
    }
    return ret;
}
