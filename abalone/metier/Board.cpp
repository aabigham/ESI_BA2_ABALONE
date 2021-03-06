#include "Board.h"
#include <algorithm>
Board::Board()
    : cells_ {  },
      whiteMarblesLost_{ 0 },
      blackMarblesLost_{ 0 }
{
    for (int x = -4; x <= 4; x++) {
        int row1 = std::max(-4, -x -4);
        int row2 = std::min(4, -x + 4);
        for (int y = row1; y <= row2; y++) {
            cells_.insert(std::make_pair(Position(x, y),Cell(Position(x,y))));
        }
    }
}

bool Board::isInside(Position pos){
    return pos.getX() >= -4 && pos.getX() <= 4
            && pos.getY() >= -4 && pos.getY() <= 4
            && pos.getZ() >= -4 && pos.getZ() <= 4;
}

Color Board::colorAt(Position pos){
    auto color = cells_.at(pos).getColor();

    return color.has_value()? color.value()
                            : throw std::invalid_argument("There is no marble on the cell.");
}

/*bool Board::canMove(Position posStart, Position posArrival){
    // TO DO
}
bool Board::canMove(Position posStart, Position posEnd, Position posArrival){
    //TO DO
}
void Board::move(Position posStart, Position posEnd, Position posArrival){
    //TO DO
}

void Board::move(Position posStart, Position posArrival){
   // TO DO
}
*/














