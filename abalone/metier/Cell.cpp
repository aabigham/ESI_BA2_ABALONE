#include "Cell.h"

Cell::Cell(Position position)
    : position_{position},
      marble_{std::nullopt}
{
}

Cell::Cell(Position position, Color marble)
    : position_{position},
      marble_{marble}
{
}
