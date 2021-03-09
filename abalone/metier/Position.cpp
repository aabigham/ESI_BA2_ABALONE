#include "Position.h"
#include "Directions.h"
#include <assert.h>

Position::Position(int x, int y)
    : x_{ x },
      y_{ y },
      z_{ -x - y }
{
    if(x_ + y_ + z_ != 0)
        throw std::invalid_argument("The sum of all the axis does not equal 0.");
}

Position::Position(const Position& pos)
    : x_{ pos.getX() },
      y_{ pos.getY() },
      z_{ pos.getZ() }
{
    if(x_ + y_ + z_ != 0)
        throw std::invalid_argument("The sum of all the axis does not equal 0.");
}

Position Position::getNext(const Direction dir) const
{
    return Position(x_ + std::get<0>(dir), y_ + std::get<1>(dir));
}

bool Position::isNextTo(const Position pos) const
{
    if(this->getNext(Directions::LEFT) == pos
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
    if(posStart == posArrival || !(posStart.isNextTo(posArrival)))
        throw std::invalid_argument("The positions are the same or are not adjacent.");

    int x_st = posStart.getX();
    int y_st = posStart.getY();
    int x_ar = posArrival.getX();
    int y_ar = posArrival.getY();

    int x_res = x_st == x_ar ? 0 : x_st < x_ar ? 1 : -1;
    int y_res = y_st == y_ar ? 0 : y_st < y_ar ? 1 : -1;

    return getDirection(x_res, y_res);
}

Position abaproToPosition(const std::string abapro) // throws
{
    validateABAPRO(abapro);
    // TODO : Convert the abapro to a Position
    return Position(0,0);
}


