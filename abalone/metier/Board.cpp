#include "Board.h"
#include <algorithm>

Board::Board()
    : cells_{},
      whiteMarblesLost_{0},
      blackMarblesLost_{0}
{
    for (int x = -4; x <= 4; ++x)
    {
        int row1 = std::max(-4, -x - 4);
        int row2 = std::min(4, -x + 4);
        for (int y = row1; y <= row2; ++y)
        {
            Position position = Position(x, y);
            if (y == 4 || y == 3 || (y == 2 && x == -2) || (y == 2 && x == -1) || (y == 2 && x == 0))
                cells_.insert(std::make_pair(position, Cell(position, Color::BLACK)));
            else if (y == -4 || y == -3 || (y == -2 && x == 0) || (y == -2 && x == 1) || (y == -2 && x == 2))
                cells_.insert(std::make_pair(position, Cell(position, Color::WHITE)));
            else
                cells_.insert(std::make_pair(position, Cell(position)));
        }
    }
}

bool Board::isInside(Position pos) const
{
    return pos.getX() >= -4 && pos.getX() <= 4
            && pos.getY() >= -4 && pos.getY() <= 4
            && pos.getZ() >= -4 && pos.getZ() <= 4;
}

std::optional<Color> Board::colorAt(Position pos) const
{
    return cells_.at(pos).getColor();
}

int Board::countMarbles(Position position, Direction direction, int cpt, Color color) const
{
    if(colorAt(position).value()!=color)
        return cpt;

    return countMarbles(Position(position.getNext(direction)), direction, cpt++, color);
}

bool Board::canMove(Position posStart, Position posArrival)
{
    if(!colorAt(posArrival).has_value())
        return true;

    Color colorStart = colorAt(posStart).value();
    Direction direction = computeDirection(posStart, posArrival);
    int nbMarbles = countMarbles(posStart, direction, 1, colorStart);

    if(nbMarbles > 3)
        return false;

    Color opposite = colorStart == Color::BLACK ? Color::WHITE : Color::BLACK;
    Position from(nbMarbles == 2 ? posArrival.getNext(direction)
                                 : posArrival.getNext(direction).getNext(direction));

    if(!colorAt(from).has_value())
        return true;

    return countMarbles(from, direction, 1, opposite) < nbMarbles;
}

/*
bool Board::canMove(Position posStart, Position posEnd, Position posArrival){
    //TO DO
}

void Board::move(Position posStart, Position posEnd, Position posArrival)
{
    //TO DO
}

void Board::move(Position posStart, Position posArrival)

{
    Direction direction = computeDirection(posStart,posArrival);
    while(posArrival.getNext())

    getCellAt(posArrival).setColor(getCellAt(posStart).getColor().value());
    getCellAt(posStart).setColor();

}
*/
