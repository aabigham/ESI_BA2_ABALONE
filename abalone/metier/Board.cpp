#include "Board.h"



bool Board::isInside(Position pos){
    return pos.getX()>=-4&&pos.getX()<=4&& pos.getY()>=-4&&pos.getY()<=4&& pos.getZ()>=-4&&pos.getZ()<=4;
}



Color Board::colorAt(Position pos){
    cells.at(pos).getColor();
}










