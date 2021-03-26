#ifndef _CELL_H
#define _CELL_H

#include <optional>
#include "Position.h"
#include "Color.h"

/*!
 * \brief The Cell class
 *
 * A cell is located on the board, it has its position and the color of the marble that is on top of it.
 */
class Cell
{
public:
    /*!
    * \brief Constructor of the Cell class.
    *
    * \param pos the position of the cell on the board.
    */
    Cell(Position pos);

    /*!
    * \brief Second constructor of the Cell class.
    *
    * \param pos the position of the cell on the board.
    * \param marble the color of the marble, NONE if there is no marble on the cell.
    */
    Cell(Position pos, Color marble);

    /*!
    * \brief The string representation of the object.
    *
    * \return a string representation of the object.
    */
    inline std::string to_string() const;

    /*!
    * \brief Getter of the color of the cell.
    *
    * \return the color of the cell.
    */
    inline std::optional<Color> getColor() const;

    /*!
    * \brief Setter of the cell class.
    *
    * \param the color that will be attributed to the cell.
    */
    inline void setColor(Color color);

    /*!
    * \brief setColor sets the color value at std::nullopt
    */
    inline void removeColor();

private:
    /*!
    * \brief The position of the cell.
    */
    Position position_;

    /*!
    * \brief The marble that the cell contains.
    *
    * If there is not any marble on the cell, the value of the cell is NONE.
    */
    std::optional<Color> marble_;
};


/*!
 * \brief The output stream operator overloading.
 *
 * \param os the output stream.
 * \param cell the cell to output.
 *
 * \return the output stream containing the string representation of the cell.
 */
inline std::ostream &operator<<(std::ostream &os, const Cell &cell);

inline std::ostream &operator<<(std::ostream &os, const Cell &cell)
{
    return os << cell.to_string();
}

// Inline methods
std::string Cell::to_string() const
{
    if (marble_.has_value())
        return marble_.value() == Color::WHITE ? "W" : "B";
    else
        return ".";
}

std::optional<Color> Cell::getColor() const
{
    if (marble_.has_value())
        return marble_.value();
    return std::nullopt;
}

void Cell::setColor(Color color)
{
    marble_.emplace(color);
}

void Cell::removeColor()
{
    marble_.reset();
}

#endif //_CELL_H
