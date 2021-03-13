#include "Position.h"
#include "Directions.h"
#include <assert.h>
#include <iostream>

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
    if (this->getNext(Directions::LEFT) == pos
            || this->getNext(Directions::DOWN_LEFT) == pos
            || this->getNext(Directions::UP_LEFT) == pos
            || this->getNext(Directions::RIGHT) == pos
            || this->getNext(Directions::DOWN_RIGHT) == pos
            || this->getNext(Directions::UP_RIGHT) == pos)
        return true;
    else
        return false;
}

const Direction computeDirection(Position posStart, Position posArrival) // throws
{
    if (posStart == posArrival || !(posStart.isNextTo(posArrival)))
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

std::vector<Position> abaproToPosition(const std::string abapro) // throws
{
    if(!isAbaproValid(abapro))
        throw std::invalid_argument("The abapro input is not valid.");

    std::vector<Position> ret;
    // p1
    char l1{abapro.at(0)};
    char n1{abapro.at(1)};
    int y1 = getLetterYAxis(l1);
    int z1 = getNumberZAxis(n1);
    int x1 = 0 - (y1 + z1);
    Position p1{x1, y1, z1};
    ret.push_back(p1);
    // p2
    char l2{abapro.at(2)};
    char n2{abapro.at(3)};
    int y2 = getLetterYAxis(l2);
    int z2 = getNumberZAxis(n2);
    int x2 = 0 - (y2 + z2);
    Position p2{x2, y2, z2};
    ret.push_back(p2);
    // p3
    if (abapro.size() == 6)
    {
        char l3{abapro.at(4)};
        char n3{abapro.at(5)};
        int y3 = getLetterYAxis(l3);
        int z3 = getNumberZAxis(n3);
        int x3 = 0 - (y3 + z3);
        Position p3{x3, y3, z3};
        ret.push_back(p3);
        return ret;
    }
    return ret;
}
