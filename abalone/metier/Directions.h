#ifndef _DIRECTIONS_H
#define _DIRECTIONS_H

#include <tuple>

using Direction = std::pair<int, int>;

/*!
 * \brief The Direction class
 *
 * It allows us to define a guidance for the marbles that will be moving.
 */
class Directions
{
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

/*!
 * \brief The output stream operator overloading.
 *
 * \param os the output stream.
 * \param cell the direction to output.
 *
 * \return the output stream containing the string representation of the direction.
 */
inline std::ostream &operator<<(std::ostream &os, const Direction &dir);

/*!
 * \brief Comparison of equality between two direction.
 *
 * \param lhs the first direction to compare.
 * \param rhs the second direction to compare.
 *
 * \return true if the direction share the same value, false otherwise.
 */
inline bool operator==(const Direction &lhs, const Direction &rhs);

/*!
 * \brief Get the direction according to the x and y in parameter.
 * Used in the computeDirection Method.
 *
 * \param x the x axis.
 * \param y the y axis.
 *
 * \return the direction according to the axis in parameter.
 */
inline Direction getDirection(const int x, const int y);

std::ostream &operator<<(std::ostream &os, const Direction &dir)
{
    std::string ret;
    switch (dir.first)
    {
    case 0:
        switch (dir.second)
        {
        case 1:
            ret = "UP_RIGHT";
            break;
        case -1:
            ret = "DOWN_LEFT";
            break;
        }
        break;
    case 1:
        switch (dir.second)
        {
        case 0:
            ret = "RIGHT";
            break;
        case -1:
            ret = "DOWN_RIGHT";
            break;
        }
        break;
    case -1:
        switch (dir.second)
        {
        case 0:
            ret = "LEFT";
            break;
        case 1:
            ret = "UP_LEFT";
            break;
        }
        break;
    default:
        throw std::invalid_argument("The direction does not exist");
    }
    return os << ret;
}

bool operator==(const Direction &lhs, const Direction &rhs)
{
    return lhs.first == rhs.first && lhs.second == rhs.second;
}

Direction getDirection(const int x, const int y)
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

#endif //_DIRECTIONS_H
