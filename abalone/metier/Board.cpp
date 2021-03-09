#include "Board.h"
#include <algorithm>

Board::Board()
    : cells_ {  },
      whiteMarblesLost_{ 0 },
      blackMarblesLost_{ 0 }
{
    for (int x = -4; x <= 4; ++x)
    {
        int row1 = std::max(-4, -x - 4);
        int row2 = std::min(4, -x + 4);
        for (int y = row1; y <= row2; ++y)
        {
            cells_.insert(std::make_pair(Position(x, y),Cell(Position(x,y))));
        }
    }
}

bool Board::isInside(Position pos)
{
    return pos.getX() >= -4 && pos.getX() <= 4
            && pos.getY() >= -4 && pos.getY() <= 4
            && pos.getZ() >= -4 && pos.getZ() <= 4;
}

Color Board::colorAt(Position pos)
{
    auto color = cells_.at(pos).getColor();

    return color.has_value()? color.value()
                            : throw std::invalid_argument("There is no marble on the cell.");
}
/*
bool Board::canMove(Position posStart, Position posArrival){

    if((isInside(posStart)&&isInside(posArrival))&&posStart.isNextTo(posArrival)){//vérifie si les positions sont inside et adjacentes
        Direction direction =computeDirection(posStart,posArrival);
        Cell cellToCheck=getCellAt(posArrival.getNext(direction));
        Cell startCell=getCellAt(posStart);
        Cell arrivalCell=getCellAt(posArrival);
        if(hasSameColor(startCell,arrivalCell)){//si les deux cells ont la meme couleurs
            if(cellToCheck.getColor()==std::nullopt&&isInside(cellToCheck.getPosition())){//si la case vers laquelle on avance est vide et inside,on peut avancer
                return true;
            }else if(cellToCheck.getColor()==startCell.getColor()&&
                     getCellAt(cellToCheck.getPosition().getNext(direction)).getColor()!=startCell.getColor()){//si on retrouve une bille de la meme couleur sur le chemin,et que la bille >3 est différente ou vide

            }else{

            }
        }else if(arrivalCell.getColor()==std::nullopt){//si la case 'arrival' est vide, on avance
            return true;
        }else{//si on arrive ici, cela veut dire qu'on a un face a face de deux cells opposée. on peut donc pas bouger(1vs1)
            return false;
        }
    }else{
        return false;
    }
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














