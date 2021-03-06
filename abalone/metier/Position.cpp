#include "Position.h"
#include "Directions.h"
#include <assert.h>
#include <algorithm>

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

const Direction Position::computeDirection(Position posStart, Position posArrival)
{
    if(posStart == posArrival || !posStart.isNextTo(posArrival))
        throw std::invalid_argument("The positions are invalid.");

    int x_st = posStart.getX();
    int y_st = posStart.getY();
    int x_ar = posArrival.getX();
    int y_ar = posArrival.getY();

    int x_res = x_st == y_ar ? 0 : x_st < x_ar ? 1 : -1;
    int y_res = y_st == y_ar ? 0 : y_st < y_ar ? 1 : -1;

    return Direction{x_res, y_res};
}

Position Position::toPosition(std::string abapro)
{
    int size = abapro.size();
    if(size != 4 && size != 6)
        throw std::invalid_argument("Invalid ABAPRO, must be 4 or 6 characters long.");

    if(size == 4) // A1B1
    {
        char letter1 = abapro.at(0);
        char letter2 = abapro.at(2);
        bool letters_inside = std::find(std::begin(letters_), std::end(letters_), letter1)!= std::end(letters_)
                && std::find(std::begin(letters_), std::end(letters_), letter2)!= std::end(letters_);

        char number1 = abapro.at(1);
        char number2 = abapro.at(3);
        bool numbers_inside = std::find(std::begin(numbers_), std::end(numbers_), number1)!= std::end(numbers_)
                && std::find(std::begin(numbers_), std::end(numbers_), number2)!= std::end(numbers_);

        if(!(letters_inside && numbers_inside))
            throw std::invalid_argument("Invalid ABAPRO, wrong letter/number pair.");
    }
    else if(size == 6) // C1B2B4
    {
        char letter1 = abapro.at(0);
        char letter2 = abapro.at(2);
        char letter3 = abapro.at(4);
        bool letters_inside = std::find(std::begin(letters_), std::end(letters_), letter1)!= std::end(letters_)
                && std::find(std::begin(letters_), std::end(letters_), letter2)!= std::end(letters_)
                && std::find(std::begin(letters_), std::end(letters_), letter3)!= std::end(letters_);

        char number1 = abapro.at(1);
        char number2 = abapro.at(3);
        char number3 = abapro.at(5);
        bool numbers_inside = std::find(std::begin(numbers_), std::end(numbers_), number1)!= std::end(numbers_)
                && std::find(std::begin(numbers_), std::end(numbers_), number2)!= std::end(numbers_)
                && std::find(std::begin(numbers_), std::end(numbers_), number3)!= std::end(numbers_);

        if(!(letters_inside && numbers_inside))
            throw std::invalid_argument("Invalid ABAPRO, wrong letter/number pair.");
    }

    // TODO : Convert the abapro to a Position

    return Position(0,0);
}

Position Position::getNext(Direction dir)
{
    return Position(x_ + std::get<0>(dir), y_ + std::get<1>(dir));
}
