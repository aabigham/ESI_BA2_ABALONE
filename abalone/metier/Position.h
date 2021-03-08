#ifndef _POSITION_H
#define _POSITION_H

#include <string>
#include <algorithm>
#include "Directions.h"

/*!
 * \brief The Position class
 *
 * This class allows any cell to have a position and be located somewhere on the board.
 */
class Position {
public: 
    /*!
     * \brief Constructor of the Position class.
     * The class has three position but only the x an y axis are required,
     * the z axis will be calculated.
     *
     * \param x the value of the x axis.
     * \param y the value of the y axis.
     *
     * \throws std::invalid_argument if the sum of the attributes is different than zero.
     */
    Position(int x, int y);

    /*!
     * \brief Copy constructor of the Position class.
     *
     * \param pos the position that will provide the values.
     */
    Position(const Position& pos);

    /*!
     * \brief Checks if the position in parameter is next to the current position.
     *
     * \param pos the position to check
     *
     * \return true is the checked position is adjacent, false otherwise.
     */
    bool isNextTo(const Position pos);

    inline void validateLetter(const char letter);

    inline void validateNumber(const char number);

    inline void validateABAPRO(const std::string abapro);

    /*!
    * \brief Compute the direction in which the marbles will be moving
    *
    * This method takes a start position and a future positon in arguments,
    * and computes the direction according to the those two arguments.
    *
    * \param posStart the start position.
    * \param posArrival the future position.
    *
    * \return the calculated direction.
    */
    const Direction computeDirection(Position posStart, Position posArrival);

    /*!
     * \brief Converts a string to a position.
     *
     * This method takes an ABA-PRO notation and converts it to a Position object.
     *
     * \param abapro the ABA-PRO notation as a String object.
     * \return the according position.
     */
    Position toPosition(const std::string abapro);

    /*!
     * \brief Gets the next position given a direction.
     *
     * \param dir the direction that will be used to determine the next case.
     *
     * \return the position next to the current case, based on the  given direction.
     *
     */
    Position getNext(const Direction dir);

    /*!
     * \brief Getter of the x value.
     *
     * \return the x value.
     */
    inline int getX() const;

    /*!
     * \brief Getter of the xyvalue.
     *
     * \return the y value.
     */
    inline int getY() const;

    /*!
     * \brief Getter of the y value.
     *
     * \return the y value.
     */
    inline int getZ() const;

private:

    /*!
    * \brief The value of the x axis.
    */
    const int x_;

    /*!
    * \brief The value of the y axis.
    */
    const int y_;

    /*!
    * \brief The value of the z axis.
    */
    const int z_;

    /*!
    * \brief The ABAPRO letters.
    */
    constexpr static char letters_ [9]{'A','B','C','D','E','F','G','H','I'};

    /*!
    * \brief The ABAPRO numbers.
    */
    constexpr static char numbers_ [9]{'1','2','3','4','5','6','7','8','9'};
};

// Operators
/*!
 * \brief Comparison of equality between two positions.
 *
 * \param lhs the first position to compare.
 * \param rhs the second position to compare.
 *
 * \return true if the position share the same value, false otherwise.
 */
inline bool operator==(const Position &lhs, const Position &rhs);

/*!
 * \brief Comparison of inequality between two positions.
 *
 * \param lhs the first position to compare.
 * \param rhs the second position to compare.
 *
 * \return true if the positions are not equal, false otherwise.
 */
inline bool operator!=(const Position &lhs, const Position &rhs);

/*!
 * \brief Addition of two positions.
 *
 * \param lhs the first position.
 * \param rhs the second position.
 *
 * \return a new Position object, wich is the result
 * of the addition of both parameters.
 */
inline Position operator+(const Position &lhs, const Position &rhs);

/*!
 * \brief Substraction of two positions.
 *
 * \param lhs the first position.
 * \param rhs the second position.
 *
 * \return a new Position object, wich is the result
 * of the substraction of both parameters.
 */
inline Position operator-(const Position &lhs, const Position &rhs);

bool operator==(const Position &lhs, const Position &rhs)
{
    return lhs.getX() == rhs.getX()
            && lhs.getY() == rhs.getY()
            && lhs.getZ() == rhs.getZ();
}

bool operator!=(const Position &lhs, const Position &rhs)
{
    return !(lhs == rhs);
}

Position operator+(const Position &lhs, const Position &rhs)
{
    return Position(lhs.getX() + rhs.getX(), lhs.getY() + rhs.getY());
}

Position operator-(const Position &lhs, const Position &rhs)
{
    return Position(lhs.getX() - rhs.getX(), lhs.getY() - rhs.getY());
}

// Inline implementation
void Position::validateLetter(const char letter)
{
    bool valid = std::find(std::begin(letters_), std::end(letters_), letter)!= std::end(letters_);
    if(!valid)
         throw std::invalid_argument("Invalid ABAPRO, wrong number input.");
}

void Position::validateNumber(const char number)
{
    bool valid = std::find(std::begin(numbers_), std::end(numbers_), number)!= std::end(numbers_);
    if(!valid)
         throw std::invalid_argument("Invalid ABAPRO, wrong number input.");
}

void Position::validateABAPRO(const std::string abapro)
{
    int size = abapro.size();
    if(size != 4 && size != 6)
        throw std::invalid_argument("Invalid ABAPRO, must be 4 or 6 characters long.");

    // Validation of the abapro input Example : A1B2 or A1B2C3
    for(int i = 0; i < size; ++i)
    {
        char c = abapro.at(i);
        if(i % 2 == 0) // The char is a letter
            validateLetter(c);
        else if(i % 2 != 0) // The char is a number
            validateNumber(c);
    }
}

int Position::getX() const
{
    return x_;
}

int Position::getY() const
{
    return y_;
}

int Position::getZ() const
{
    return z_;
}


/*!
 * Hash function of the unordered map of Cells.
 */
namespace std {
template <> struct hash<Position> {
    /*!
     * \brief The operator() overload to hash a position.
     *
     * \param p the position to hash.
     *
     * \return the hash value of the position in parameter.
     */
    size_t operator()(const Position& p) const {
        hash<int> int_hash;
        size_t px = int_hash(p.getX());
        size_t py = int_hash(p.getY());
        return px ^ (py + 0x9e3779b9 + (px << 6) + (px >> 2));
    }
};
}

#endif //_POSITION_H
