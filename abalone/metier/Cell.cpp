#include "Cell.h"
#include "Directions.h"

Cell::Cell(Position position)
    : position_{ position },
      marble_{ std::nullopt }
{}

Cell::Cell(Position position,Color marble)
    : position_{ position },
      marble_{ marble }
{}

bool Cell::isAdjacentTo(Cell &cell){
    return position_.isNextTo(cell.getPosition());
}

