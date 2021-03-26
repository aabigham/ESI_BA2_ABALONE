#ifndef _COLOR_H
#define _COLOR_H

/*!
 * \brief The Color enumeration
 *
 * This enumeration allows us to define a marble, or a player.
 */
enum class Color
{
    WHITE,
    BLACK
};

/*!
 * \brief opposite gets the opposite color of a given color.
 * \param color a given color.
 * \return the opposite color of the given color.
 */
inline Color opposite(const Color color);

Color opposite(const Color color)
{
    return color == Color::BLACK ? Color::WHITE : Color::BLACK;
}

#endif //_COLOR_H
