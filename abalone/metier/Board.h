#ifndef _BOARD_H
#define _BOARD_H

#include <array>
#include <unordered_map>
#include "Position.h"
#include "Color.h"
#include "Directions.h"
#include "Cell.h"

/*!
 * \brief The Board class
 *
 * The game board. It is filled with tiles and counts the number of lost marbles for each player (color)
 */
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
    * \param posArrival the arrival position of the first marble in row.
    * \param playerColor the color of the current player.
    *
    * \return true if the move was succesful, false otherwise.
    */
    bool move(Position posStart, Position posArrival, Color playerColor);

    /*!
    * \brief The move method for side moves.
    *
    * \param posStart the position of the first marble in row.
    * \param posEnd the position of the last marble in row.
    * \param posArrival the arrival position of the first marble in row.
    * \param playerColor the color of the current player.
    *
    * \return true if the move was succesful, false otherwise.
    */
    bool move(Position posStart, Position posEnd, Position posArrival, Color playerColor);

    /*!
    * \brief countMarbles counts the number of marbles in a given direction, beginning from the given position.
    *
    * \param posStart the position of the first marble.
    * \param dirCount the direction in which the counting is heading towards to.
    * \param cpt the number of the counted marbles.
    * \param color the color that the counted marbles must have.
    *
    * \return the number of counted marbles.
    */
    int countMarbles(Position posStart, Direction dirCount, int cpt, Color color) const;

    /*!
    * \brief countMarblesUntil counts the number of marbles in a given direction,
    * beginning from the given position and stops at the given end position.
    * Since this method is used in the parallel move context, it also counts
    * the marble above or below the line, according the the dirMove in parameter.
    *
    * \param posStart the position of the first marble.
    * \param posEnd the position where to stop counting.
    * \param dirCount the direction in which the counting is heading towards to.
    * \param dirMove the direction in which we want to move parallely.
    * \param cpt the number of the counted marbles.
    * \param color the color that the counted marbles must have.
    *
    * \return the number of counted marbles.
    */
    int countMarblesUntil(Position posStart, Position posEnd, Direction dirCount,
                          Direction dirMove, int cpt, Color color) const;

    /*!
    * \brief The can move method for inline moves.
    *
    * \param posStart the position of the first marble in row.
    * \param posArrival the arrival position of the first marble in row.
    *
    * \return A vector of positions. If the vector is empty, the move is not
    * possible. If the vector has one position, it means that the contained position
    * is empty. If the vector has 2 positions, the first one is the position where
    * marble of the player will move, and the second one is the position where the
    * pushed marble of the oppisite player will arrive.
    */
    std::vector<Position>canMove(Position posStart, Position posArrival);

    /*!
    * \brief The can move method for side moves.
    *
    * \param posStart the position of the first marble in row.
    * \param posEnd the position of the last marble in row.
    * \param posArrival the arrival position of the first marble in row.
    *
    * \return true if the marbles are able to move, false otherwise.
    */
    std::vector<Position> canMove(Position posStart, Position posEnd, Position posArrival);

    /*!
    * \brief Gets the color located at the position in parameter.
    *
    * \param pos the position at which we want to find its color
    * \return the color located at the position in parameter.
    */
    std::optional<Color> colorAt(Position pos) const; //done

    /*!
    * \brief Checks if a position is inside the board.
    * \param pos the position we want to be checking.
    *
    * \return true if the position is inside, false otherwise.
    */
    bool isInside(Position pos) const ; //Done

    /*!
    * \brief Getter of the cells of the board.
    *
    * \return the cells of the board.
    */
    inline std::unordered_map<Position, Cell> getCells() const; //done

    /*!
    * \brief Gets the cell at the position in parameter.
    *
    * \param pos the position of the cell we want to get.
    *
    * \return the cell at the given position.
    */
    inline Cell &getCellAt(Position pos); //done

    /*!
    * \brief Getter of the lost white marbles.
    *
    * \return the number of lost white marble.
    */
    inline int getWhiteMarblesLost() const; //done

    /*!
    * \brief Getter of the lost black marbles.
    *
    * \return the number of lost black marble.
    */
    inline int getBlackMarblesLost() const; //done

    /*!
    * \brief Increments the count of lost white marbles.
    */
    inline void addWhiteMarbleLost(); //done

    /*!
    * \brief Increments the count of lost black marbles.
    */
    inline void addBlackMarbleLost(); //done

private:
    /*!
    * \brief The cells located on the board.
    */
    std::unordered_map<Position, Cell> cells_;

    /*!
    * \brief Counts the number of lost white marbles.
    */
    int whiteMarblesLost_;

    /*!
    * \brief Counts the number of black marbles.
    */
    int blackMarblesLost_;
};

// Iinline methods

std::unordered_map<Position, Cell> Board::getCells() const
{
    return cells_;
}

Cell &Board::getCellAt(const Position pos)
{
    return cells_.at(pos);
}

int Board::getWhiteMarblesLost() const
{
    return whiteMarblesLost_;
}

int Board::getBlackMarblesLost() const
{
    return blackMarblesLost_;
}

void Board::addWhiteMarbleLost()
{
    ++whiteMarblesLost_;
}

void Board::addBlackMarbleLost()
{
    ++blackMarblesLost_;
}

#endif //_BOARD_H
