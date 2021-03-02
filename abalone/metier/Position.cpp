#include "Position.h"
#include <assert.h>

Position::Position(int x, int y)
    : x_{ x }, y_{ y }, z_{ -x - y }
{
    if(x_ + y_ + z_ != 0)
        throw std::invalid_argument("The sum of all the axis does not equal 0.");
}

Position::Position(Position& pos)
    : x_{ pos.getX() }, y_{ pos.getY() }, z_{ pos.getZ() }
{
    if(x_ + y_ + z_ != 0)
        throw std::invalid_argument("The sum of all the axis does not equal 0.");
}

Direction Position::computeDirection(Position posStart, Position posArrival)
{

}

Position Position::toPosition(std::string abapro)
{

}

Position Position::getNext(Direction dir)
{
    return Position(x_ + std::get<0>(dir), y_ + std::get<1>(dir));
}
