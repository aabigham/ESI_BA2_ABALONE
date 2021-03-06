#ifndef _DIRECTIONS_H
#define _DIRECTIONS_H

#include <tuple>
#include "Position.h"

using Direction = std::pair<int, int>;

/*!
 * \brief The Direction class
 *
 * It allows us to define a guidance for the marbles that will be moving.
 */
class Directions {
public:
    /*!
    * \brief The UP_RIGHT direction.
    */
    constexpr static const Direction UP_RIGHT{0, 1};

    /*!
    * \brief The UP_LEFT direction.
    */
    constexpr static const Direction UP_LEFT{-1, 1};

    /*!
    * \brief The UP direction.
    */
    constexpr static const Direction LEFT{-1, 0};

    /*!
    * \brief The DOWN direction.
    */
    constexpr static const Direction RIGHT{1, 0};

    /*!
    * \brief The DOWN_LEFT direction.
    */
    constexpr static const Direction DOWN_LEFT{0, -1};

    /*!
    * \brief The DOWN_RIGHT direction.
    */
    constexpr static const Direction DOWN_RIGHT{1, -1};
};

#endif //_DIRECTIONS_H
