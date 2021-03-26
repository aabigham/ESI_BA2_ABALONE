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

int getLetterYAxis(const char letter)
{
    for (const auto &[c, i] : Position::letters_y)
        if (c == letter)
            return i;
    throw std::invalid_argument("The letter does not exist.");
}

int getNumberZAxis(const int number)
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
    for (int i = 0; i < size - 1; i += 2)
    {
        auto currPair{std::make_pair(abapro.at(i), abapro.at(i + 1))};
        if(!isPairValid(currPair))
            return false;
    }
    return true;
}

std::vector<Position> abaproToPosition(const std::string abapro) // throws
{
    if(!isAbaproValid(abapro))
        throw std::invalid_argument("The abapro input is not valid.");

    // Make a position out of each pair then pushing to the back of the vector
    std::vector<Position> ret;
    for (size_t i = 0; i < abapro.size() - 1; i += 2)
    {
        int y = getLetterYAxis(abapro.at(i));
        int z = getNumberZAxis(abapro.at(i + 1));
        int x = 0 - (y + z);
        ret.push_back(Position(x, y, z));
    }
    return ret;
}
