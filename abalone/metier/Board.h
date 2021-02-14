#ifndef _BOARD_H
#define _BOARD_H

#include <array>
#include "Position.h"
#include "Color.h"
#include "Direction.h"
#include "Cell.h"

class Board
{
public:
    /*!
    * \brief Constructor of Board.
    */
    Board();

    /*!
    * \brief The move method for inline moves.
    *
    * \param posStart the position of the first marble in row.
    * \param posEnd the end position of the first marble in row.
    */
    void move(Position posStart, Position posEnd);

    /*!
    * \brief The move method for side moves.
    *
    * \param posStart the position of the first marble in row.
    * \param posEnd the end position of the first marble in row.
    * \param futurePos the position in which the marbles will be heading toward to.
    */
    void move(Position posStart, Position posEnd, Position futurePos);

    /*!
    * \brief The can move method for inline moves.
    *
    * \param posStart the position of the first marble in row.
    * \param posEnd the end position of the first marble in row.
    *
    * \return true if the marbles are able to move, false otherwise.
    */
    bool canMove(Position posStart, Position posEnd);

    /*!
    * \brief The can move method for side moves.
    *
    * \param posStart the position of the first marble in row.
    * \param posEnd the end position of the first marble in row.
    * \param futurePos the position in which the marbles will be heading toward to.
    *
    * \return true if the marbles are able to move, false otherwise.
    */
    bool canMove(Position posStart, Position posEnd, Position futurePos);

    /*!
    * \brief Gets the color located at the position in parameter.
    *
    * \param pos the position at which we want to find its color
    * \return the color located at the position in parameter.
    */
    Color colorAt(Position pos);

    /*!
    * \brief Checks if a position is inside the board.
    * \param pos the position we want to be checking.
    *
    * \return true if the position is inside, false otherwise.
    */
    bool isInside(Position pos);

    /*!
    * \brief Compute the direction in which the marbles will be moving
    *
    * This method takes a start position and a future positon in arguments,
    * and computes the direction according to the those two arguments.
    *
    * \param posStart the start position.
    * \param posFuture the future position.
    *
    * \return the calculated direction.
    */
    Direction computeDirection(Position posStart, Position posFuture);

    /*!
    * \brief Getter of the cells of the board.
    *
    * \return the cells of the board.
    */
    std::array<Cell, 61> getCells();

    /*!
     * \brief Gets the cell at the position in parameter.
     *
     * \param pos the position of the cell we want to get.
     *
     * \return the cell at the given position.
     */
    Cell &getCellAt(Position pos);

    /*!
    * \brief Getter of the lost white marbles.
    *
    * \return the number of lost white marble.
    */
    int getWhiteMarblesLost();

    /*!
    * \brief Getter of the lost black marbles.
    *
    * \return the number of lost black marble.
    */
    int getBlackMarblesLost();

    /*!
    * \brief Increments the count of lost white marbles.
    */
    void addWhiteMarbleLost();

    /*!
    * \brief Increments the count of lost black marbles.
    */
    void addBlackMarbleLost();

private:
    /*!
     * \brief The cells located on the board.
     */
    std::array<Cell, 61> cells;

    /*!
    * \brief Counts the number of lost white marbles.
    */
    int whiteMarblesLost;

    /*!
    * \brief Counts the number of black marbles.
    */
    int blackMarblesLost;
};

#endif //_BOARD_H
