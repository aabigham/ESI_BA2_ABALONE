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
    /*
     * If the marble is not inside, or the color does not correspond anymore,
     * or if there is no color anymore
     * */
    if(!isInside(posStart)
            || (colorAt(posStart).has_value() && colorAt(posStart).value() != color)
            || !colorAt(posStart).has_value())
        return cpt;

    return countMarbles(Position(posStart.getNext(dirCount)), dirCount, ++cpt, color);
}

std::vector<Position> Board::canMove(Position posStart, Position posArrival, Color playerColor) const
{
    std::vector<Position> positions;
    Color oppositeColor = opposite(playerColor);
    Direction dirMove = computeDirection(posStart, posArrival);

    // If positions are not inside
    if(!(isInside(posStart) && isInside(posArrival)))
        return positions;
    // If arrival pos isn't next to start pos
    if(!posStart.isNextTo(posArrival))
        return positions;
    // Cells not belonging to the player
    if(colorAt(posStart) != playerColor
            || (colorAt(posArrival).has_value() && colorAt(posArrival) == oppositeColor))
        return positions;
    // The arrival pos is empty so we can move
    if(!colorAt(posArrival).has_value())
    {
        positions.push_back(posArrival);
        return positions;
    }

    // Counting the current player's marbles
    int nbMarbles = countMarbles(posStart, dirMove, 0, playerColor);
    // Max 3 marbles able to move
    if(nbMarbles <= 3)
    {
        // First pos after the player's marbles
        Position firstOther(nbMarbles == 2 ? posArrival.getNext(dirMove)
                                           : posArrival.getNext(dirMove).getNext(dirMove));
        // If it has no color, we can move directly
        if(!colorAt(firstOther).has_value())
        {
            positions.push_back(firstOther);
        }
        else // It has a marble belonging to the ennemy
        {
            int oppositeMarbleCounter = countMarbles(firstOther, dirMove, 0, oppositeColor);

            // We should be in numeric superiority
            if(oppositeMarbleCounter < nbMarbles)
            {
                // First position after "firstOther"
                Position afterOther(oppositeMarbleCounter == 1
                             ? firstOther.getNext(dirMove)
                             : firstOther.getNext(dirMove).getNext(dirMove));
                // If it's not inside, or not occupied
                if(!isInside(afterOther) || !colorAt(afterOther).has_value())
                {
                    positions.push_back(firstOther);
                    positions.push_back(oppositeMarbleCounter == 1
                                        ? firstOther.getNext(dirMove)
                                        : firstOther.getNext(dirMove).getNext(dirMove));
                }
            }
        }
    }

    return positions;
}


bool Board::move(Position posStart, Position posArrival)
{
    Color playerColor{colorAt(posStart).value()};
    auto positions = canMove(posStart, posArrival, playerColor);
    // If the vector is empty, the move is not possible
    if(positions.size() == 0)
        return false;

    // Removing the start marble
    getCellAt(posStart).removeColor();
    // The first position in the vector will always be the player's one
    getCellAt(positions.at(0)).setColor(playerColor);

    /*
     * The second position in the vector is the position where
     * the pushed marble of the opposite player will arrive
     * */
    if(positions.size() == 2)
    {
        // Checking if we pushed a marble outside of the board
        if(!isInside(positions.at(1)))
            playerColor == Color::BLACK ? addWhiteMarbleLost() : addBlackMarbleLost();
        else
            getCellAt(positions.at(1)).setColor(opposite(playerColor));
    }

    return true;
}

int Board::countMarblesUntil(Position posStart, Position posEnd, Direction dirCount,
                             Direction dirMove, int cpt, Color color) const
{
    // Checking the parallel line above (for lateral move)
    // Also checking if we count above 3, which cancels the move
    // and checks if there is a foreign marble in the way
    if(colorAt(posStart.getNext(dirMove)).has_value() || cpt > 3 || colorAt(posStart).value() != color)
        return -5;

    // If the posStart is the same of posEnd
    if(posStart == posEnd)
        return cpt;

    return countMarblesUntil(Position(posStart.getNext(dirCount)), posEnd, dirCount, dirMove, ++cpt, color);
}

int Board::canMove(Position posStart, Position posEnd, Position posArrival, Color playerColor) const
{
    // Pos does not belong to the player
    if(colorAt(posStart) != playerColor)
        return -1;
    Direction dirMove = computeDirection(posStart, posArrival);
    // All the positions involved in the lateral move must be inside
    if(!(isInside(posStart) && isInside(posEnd) && isInside(posArrival)
         && isInside(posStart.getNext(dirMove)) && isInside(posEnd.getNext(dirMove))))
        return -1;
    // If the arrival position is not ajdacent to the starting position.
    if(!posStart.isNextTo(posArrival))
        return -1;
    // Checking if the arrival pos already has a value
    if(colorAt(posArrival).has_value())
        return -1;

    // Counting lines
    Direction dirCount = computeDirection(posStart, posEnd);
    return countMarblesUntil(posStart, posEnd, dirCount, dirMove, 1, playerColor);
}

bool Board::move(Position posStart, Position posEnd, Position posArrival)
{
    Color playerColor{colorAt(posStart).value()};
    int nbMarbles = canMove(posStart, posEnd, posArrival, playerColor);
    if(nbMarbles < 0)
        return false;

    // Changing the corresponding positions, according to nbMarbles
    Direction dirCount = computeDirection(posStart, posEnd);
    switch (nbMarbles)
    {
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
