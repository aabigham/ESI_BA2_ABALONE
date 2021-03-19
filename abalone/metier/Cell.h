#ifndef _CELL_H
#define _CELL_H

#include <string>
#include <optional>
#include "Position.h"
#include "Color.h"
#include <stdlib.h>

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
    Cell(Position pos); //done

    /*!
    * \brief Second constructor of the Cell class.
    *
    * \param pos the position of the cell on the board.
    * \param marble the color of the marble, NONE if there is no marble on the cell.
    */
    Cell(Position pos, Color marble); //done

    /*!
    * \brief Checks if a cell is adjacent to the current cell.
    *
    * \param cell the cell that will be checked.
    *
    * \return true if the cell is adjacent to the current cell, false otherwise.
    */
    bool isAdjacentTo(Cell &cell); //done

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
    inline std::optional<Color> getColor() const; //done

    /*!
    * \brief Getter of the position of the current cell.
    *
    * \return the position of the current cell.
    */
    inline Position getPosition() const; //done

    /*!
    * \brief Setter of the cell class.
    *
    * \param the color that will be attributed to the cell.
    */
    inline void setColor(Color color); //done

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
 * \brief hasSameColor Checks if two cells have the same color.
 *
 * \param cell1 the first cell to compare
 * \param cell2 the second cell to compare
 *
 * \return true if the cells have the same color, false otherwise.
 */
inline bool hasSameColor(Cell cell1, Cell cell2);

/*!
 * \brief The output stream operator overloading.
 *
 * \param os the output stream.
 * \param cell the cell to output.
 *
 * \return the output stream containing the string representation of the cell.
 */
inline std::ostream &operator<<(std::ostream &os, const Cell &cell);

inline bool hasSameColor(Cell cell1, Cell cell2)
{
    return cell1.getColor() == cell2.getColor();
}

inline std::ostream &operator<<(std::ostream &os, const Cell &cell)
{
    return os << cell.to_string();
}

// Inline methods
std::string Cell::to_string() const
{
    std::string str;
    str.append(" ___ ");
    str.append("\n/ ");
    if (marble_.has_value())
    {
        Color color = marble_.value();
        str.append(color == Color::WHITE ? "W" : "B");
    }
    else
    {
        str.append(" ");
    }
    str.append(" \\");
    str.append("\n\\___/");
    return str;
}

std::optional<Color> Cell::getColor() const
{
    if (marble_.has_value())
        return marble_.value();

    return std::nullopt;
}

Position Cell::getPosition() const
{
    return position_;
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
