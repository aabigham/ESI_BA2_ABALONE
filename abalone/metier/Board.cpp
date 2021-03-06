#include "Board.h"

Board::Board()
    : cells_ {  },
      whiteMarblesLost_{ 0 },
      blackMarblesLost_{ 0 }
{
    for (unsigned i = 0; i < 61 ; ++i) {
        // TODO : insert to map
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










