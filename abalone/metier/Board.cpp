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

std::vector<Position> Board::canMove(Position posStart, Position posArrival)
{
    std::vector<Position> positions;

    Color colorStart = colorAt(posStart).value();
    Color oppositeColor = (colorStart == Color::BLACK ? Color::WHITE : Color::BLACK);
    Direction dirMove = computeDirection(posStart, posArrival);

    if( !isInside(posStart) || !isInside(posArrival) || colorAt(posArrival) == oppositeColor)
    { /* Start or Arrival position are outside the board,
        or the arrival color does not belong to the player.*/
        return positions;
    }
    else if(!colorAt(posArrival).has_value())
    { // The arrival pos is empty
        positions.push_back(posArrival);
        return positions;
    }
    // Counting the current player's marble
    int nbMarbles = countMarbles(posStart, dirMove, 1, colorStart);
    if(nbMarbles <= 3) // Max 3 marbles
    {
        // First ennemy marble
        Position from(nbMarbles == 2 ? posArrival.getNext(dirMove)
                                     : posArrival.getNext(dirMove).getNext(dirMove));
        if(!colorAt(from).has_value())
        { // If it has no color
            positions.push_back(from);
        }
        else
        { // If it's belonging to the ennemy
            int oppositeMarbleCounter = countMarbles(from, dirMove, 1, oppositeColor);
            if(oppositeMarbleCounter < nbMarbles)
            {
                positions.push_back(from);
                positions.push_back(oppositeMarbleCounter == 1 ? from.getNext(dirMove)
                                                               : from.getNext(dirMove).getNext(dirMove));
            }
        }
    }

    return positions;
}


bool Board::move(Position posStart, Position posArrival, Color playerColor)
{
    auto positionVector = canMove(posStart,posArrival);

    if(colorAt(posStart) != playerColor || positionVector.size() == 0 )
        return false;

    getCellAt(posStart).removeColor();
    getCellAt(positionVector.at(0)).setColor(playerColor);

    if(positionVector.size() == 2)
        getCellAt(positionVector.at(1)).setColor(playerColor == Color::BLACK ? Color::WHITE : Color::BLACK);

    return true;
}

int Board::countMarblesUntil(Position posStart, Position posEnd, Direction dirCount, Direction dirMove, int cpt, Color color) const
{
    if(colorAt(posStart.getNext(dirMove)).has_value() || cpt > 3)
       return -5;

    if(colorAt(posStart).value() != color || posStart == posEnd)
        return cpt;

    return countMarblesUntil(Position(posStart.getNext(dirCount)), posEnd, dirCount, dirMove, cpt++, color);
}

/*std::vector<Position> Board::canMove(Position posStart, Position posEnd, Position posArrival){
    std::vector<Position> positions;
    Color colorStart = colorAt(posStart).value();
    Color oppositeColor = (colorStart == Color::BLACK ? Color::WHITE : Color::BLACK);
    Direction dirMove = computeDirection(posStart, posArrival);
    Direction dirCount = computeDirection(posStart, posEnd);

    if(!isInside(posStart) || !isInside(posEnd) || !isInside(posArrival)
            || colorAt(posArrival).has_value())
    { //Start, End or Arrival positions are outside the board,
       // or the arrival position is occupied.
        return positions;
    }

    // Count line
    int nbMarblesLine = countMarblesUntil(posStart, posEnd, dirCount, dirMove, 1, colorStart);

    // If nb < 0 --> return false;


    // Peut bouger
    // If nb == 1
    // If nb == 2
    // If nb == 3

}*/

/*bool Board::move(Position posStart, Position posEnd, Position posArrival)
{
    //TO DO
}*/
