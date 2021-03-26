#include <algorithm>
#include "Board.h"

Board::Board()
    : cells_{std::unordered_map<Position, Cell>()},
      whiteMarblesLost_{0},
      blackMarblesLost_{0}
{
    for (int x = -4; x <= 4; ++x)
    {
        int row1 = std::max(-4, -x - 4);
        int row2 = std::min(4, -x + 4);
        for (int y = row1; y <= row2; ++y)
        {
            Position pos(x, y);
            if (y == 4 || y == 3 || (y == 2 && x == -2) || (y == 2 && x == -1) || (y == 2 && x == 0))
                cells_.insert(std::make_pair(pos, Cell(pos, Color::WHITE)));
            else if (y == -4 || y == -3 || (y == -2 && x == 0) || (y == -2 && x == 1) || (y == -2 && x == 2))
                cells_.insert(std::make_pair(pos, Cell(pos, Color::BLACK)));
            else
                cells_.insert(std::make_pair(pos, Cell(pos)));
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

int Board::countMarbles(Position posStart, Direction dirCount, int cpt, Color color) const
{
    if(!isInside(posStart)
            || (colorAt(posStart).has_value() && colorAt(posStart).value() != color)
            ||!colorAt(posStart).has_value())
        return cpt;

    return countMarbles(Position(posStart.getNext(dirCount)), dirCount, ++cpt, color);
}

std::vector<Position> Board::canMove(Position posStart, Position posArrival, Color playerColor)
{
    std::vector<Position> positions;

    if(colorAt(posStart) != playerColor || !posStart.isNextTo(posArrival))
        return positions;

    Color oppositeColor = opposite(playerColor);
    Direction dirMove = computeDirection(posStart, posArrival);

    if(!isInside(posStart) || !isInside(posArrival)
            ||(colorAt(posArrival).has_value() && colorAt(posArrival) == oppositeColor))
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
    int nbMarbles = countMarbles(posStart, dirMove, 0, playerColor);
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
            int oppositeMarbleCounter = countMarbles(from, dirMove, 0, oppositeColor);
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
    auto positionVector = canMove(posStart, posArrival, playerColor);

    if(positionVector.size() == 0 )
        return false;

    getCellAt(posStart).removeColor();
    getCellAt(positionVector.at(0)).setColor(playerColor);

    if(positionVector.size() == 2)
    {
        if(!isInside(positionVector.at(1)))
            playerColor == Color::BLACK ? addWhiteMarbleLost() : addBlackMarbleLost();
        else
            getCellAt(positionVector.at(1)).setColor(opposite(playerColor));
    }

    return true;
}

int Board::countMarblesUntil(Position posStart, Position posEnd, Direction dirCount,
                             Direction dirMove, int cpt, Color color) const
{
    if(colorAt(posStart.getNext(dirMove)).has_value() || cpt > 3)
        return -5;

    if(colorAt(posStart).value() != color || posStart == posEnd)
        return cpt;

    return countMarblesUntil(Position(posStart.getNext(dirCount)), posEnd, dirCount, dirMove, ++cpt, color);
}

int Board::canMove(Position posStart, Position posEnd, Position posArrival, Color playerColor){
    if(colorAt(posStart) != playerColor)
        return -1;

    Direction dirMove = computeDirection(posStart, posArrival);
    Direction dirCount = computeDirection(posStart, posEnd);

    if(!(isInside(posStart) && isInside(posEnd) && isInside(posArrival)
         && isInside(posStart.getNext(dirMove)) && isInside(posEnd.getNext(dirMove))
         && isInside(posArrival.getNext(dirMove)) && !colorAt(posArrival).has_value()))
    { //Start, End or Arrival positions are outside the board,
        // or the arrival position is occupied.
        return -1;
    }

    // Count lines
    int nbMarblesLine = countMarblesUntil(posStart, posEnd, dirCount, dirMove, 1, playerColor);
    if(nbMarblesLine < 0)
        return -1;
    else
        return nbMarblesLine;
}

bool Board::move(Position posStart, Position posEnd, Position posArrival, Color playerColor)
{
    int nbMarbles = canMove(posStart, posEnd, posArrival, playerColor);
    if(nbMarbles < 0)
        return false;

    //Direction dirMove = computeDirection(posStart, posArrival);
    Direction dirCount = computeDirection(posStart, posEnd);

    switch (nbMarbles) {
    case 1:
    {
        getCellAt(posStart).removeColor();
        getCellAt(posArrival).setColor(playerColor);
        break;
    }
    case 2:
    {
        getCellAt(posStart).removeColor();
        getCellAt(posStart.getNext(dirCount)).removeColor();
        getCellAt(posArrival).setColor(playerColor);
        getCellAt(posArrival.getNext(dirCount)).setColor(playerColor);
        break;
    }
    case 3:
    {
        getCellAt(posStart).removeColor();
        getCellAt(posStart.getNext(dirCount)).removeColor();
        getCellAt(posStart.getNext(dirCount).getNext(dirCount)).removeColor();
        getCellAt(posArrival).setColor(playerColor);
        getCellAt(posArrival.getNext(dirCount)).setColor(playerColor);
        getCellAt(posArrival.getNext(dirCount).getNext(dirCount)).setColor(playerColor);
        break;
    }
    default:
        return false;
    }
    return true;
}
