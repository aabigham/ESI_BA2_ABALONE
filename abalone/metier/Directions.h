#ifndef _DIRECTIONS_H
#define _DIRECTIONS_H

#include <tuple>

using Direction = std::pair<int, int>;

/*!
 * \brief The Direction namespace
 * It allows us to define a guidance for the marbles that will be moving.
 */
namespace Directions
{
    /*!
    * \brief The UP_RIGHT direction.
    */
    constexpr static Direction UP_RIGHT{0, 1};

    /*!
    * \brief The UP_LEFT direction.
    */
    constexpr static Direction UP_LEFT{-1, 1};

    /*!
    * \brief The UP direction.
    */
    constexpr static Direction LEFT{-1, 0};

    /*!
    * \brief The DOWN direction.
    */
    constexpr static Direction RIGHT{1, 0};

    /*!
    * \brief The DOWN_LEFT direction.
    */
    constexpr static Direction DOWN_LEFT{0, -1};

    /*!
    * \brief The DOWN_RIGHT direction.
    */
    constexpr static Direction DOWN_RIGHT{1, -1};

    /*!
    * \brief Get the direction according to the x and y in parameter.
    * Used in the computeDirection Method.
    * \param x the x axis.
    * \param y the y axis.
    * \return the direction according to the axis in parameter.
    */
    Direction getDirection(int x, int y);
}

#endif //_DIRECTIONS_H
