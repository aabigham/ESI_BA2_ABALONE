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

bool Position::isNextTo(Position pos)
{
    if(this->getNext(Directions::LEFT) == pos
            || this->getNext(Directions::DOWN_LEFT) == pos
            || this->getNext(Directions::UP_LEFT) == pos
            || this->getNext(Directions::RIGHT) == pos
            || this->getNext(Directions::DOWN_RIGHT) == pos
            || this->getNext(Directions::DOWN_LEFT) == pos)
        return true;
    else
        return false;
}

Direction Position::computeDirection(Position posStart, Position posArrival)
{
    if(posStart == posArrival || !posStart.isNextTo(posArrival))
        throw std::invalid_argument("Either the positions are not adjacent or they are the same.");

    // TODO
}

Position Position::toPosition(std::string abapro)
{
    // TODO
}

Position Position::getNext(Direction dir)
{
    return Position(x_ + std::get<0>(dir), y_ + std::get<1>(dir));
}
