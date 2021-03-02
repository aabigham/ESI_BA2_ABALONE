#ifndef _CELL_H
#define _CELL_H

#include <string>
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
    * \brief Checks if a cell is adjacent to the current cell.
    *
    * \param cell the cell that will be checked.
    *
    * \return true if the cell is adjacent to the current cell, false otherwise.
    */
    bool isAdjacentTo(Cell cell);

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
    * \brief Getter of the position of the current cell.
    *
    * \return the position of the current cell.
    */
    inline Position getPosition() const;

    /*!
     * \brief The string representation of the object.
     *
     * \return a string representation of the object.
     */
    inline std::string to_string() const;

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
    std::optional<Color> marble_ = {};
};

// Inline methods
Position Cell::getPosition() const
{
    return position_;
}

void Cell::setColor(Color color)
{
    this->marble_.emplace(color);
}

std::optional<Color> Cell::getColor() const
{
    return marble_.value();

}
#endif //_CELL_H
