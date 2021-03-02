#include "Position.h"

Position::Position(int x, int y)
    : x_{ x }, y_{ y }, z_{ -x - y }
{}
