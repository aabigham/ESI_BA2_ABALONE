#include "Directions.h"

Direction getDirection(int x, int y)
{
    Direction ret;
    switch (x)
    {
    case 0:
        switch (y)
        {
        case 1:
            ret = Directions::UP_RIGHT;
            break;
        case -1:
            ret = Directions::DOWN_LEFT;
            break;
        }
        break;
    case 1:
        switch (y)
        {
        case 0:
            ret = Directions::RIGHT;
            break;
        case -1:
            ret = Directions::DOWN_RIGHT;
            break;
        }
        break;
    case -1:
        switch (y)
        {
        case 0:
            ret = Directions::LEFT;
            break;
        case 1:
            ret = Directions::UP_LEFT;
            break;
        }
        break;
    default:
        throw std::invalid_argument("The direction does not exist");
    }
    return ret;
}
