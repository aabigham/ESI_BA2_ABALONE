#ifndef _POSITION_H
#define _POSITION_H

#include <string>
#include <algorithm>
#include <utility>
#include <vector>
#include "Directions.h"

using Direction = std::pair<int, int>;

/*!
 * \brief The Position class
 *
 * This class allows any cell to have a position and be located somewhere on the board.
 */
class Position
{
public:
    /*!
     * \brief Constructor of the Position class with 2 parameters.
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
     * \brief Constructor of the Position class with 3 parameters.
     * The class has three position but only the x an y axis are required,
     * the z axis will be calculated.
     *
     * \param x the value of the x axis.
     * \param y the value of the y axis.
     * \param z the value of the z axis.
     *
     * \throws std::invalid_argument if the sum of the attributes is different than zero.
     */
    Position(int x, int y, int z);

    /*!
     * \brief Copy constructor of the Position class.
     *
     * \param pos the position that will provide the values.
     */
    Position(const Position &pos);

    /*!
     * \brief Gets the next position given a direction.
     *
     * \param dir the direction that will be used to determine the next case.
     *
     * \return the position next to the current case, based on the  given direction.
     *
     */
    Position getNext(const Direction dir) const;

    /*!
     * \brief Checks if the position in parameter is next to the current position.
     *
     * \param pos the position to check
     *
     * \return true is the checked position is adjacent, false otherwise.
     */
    bool isNextTo(const Position pos) const;

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

    /*!
    * \brief The ABAPRO letters and their corresponding Y Axis value.
    */
    constexpr static std::array<std::pair<char, int>, 9>
        letters_y{std::make_pair('A', -4),
                  std::make_pair('B', -3),
                  std::make_pair('C', -2),
                  std::make_pair('D', -1),
                  std::make_pair('E', 0),
                  std::make_pair('F', 1),
                  std::make_pair('G', 2),
                  std::make_pair('H', 3),
                  std::make_pair('I', 4)};

    /*!
    * \brief The ABAPRO numbers and their corresponding Z Axis value.
    */
    constexpr static std::array<std::pair<char, int>, 9>
        numbers_z{std::make_pair('1', 4),
                  std::make_pair('2', 3),
                  std::make_pair('3', 2),
                  std::make_pair('4', 1),
                  std::make_pair('5', 0),
                  std::make_pair('6', -1),
                  std::make_pair('7', -2),
                  std::make_pair('8', -3),
                  std::make_pair('9', -4)};

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
};

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
 * \brief Validates an ABAPRO letter.
 *
 * \param letter the letter to validate.
 *
 * \throws std::invalid_argument if the letter is not valid.
 */
inline void validateLetter(const char letter);

/*!
 * \brief Validates an ABAPRO number.
 *
 * \param letter the number to validate.
 *
 * \throws std::invalid_argument if the number is not valid.
 */
inline void validateNumber(const char number);

/*!
 * \brief Validates an ABAPRO input.
 *
 * \param letter the input to validate.
 *
 * \throws std::invalid_argument if the input is not valid.
 */
inline void validateABAPRO(const std::string abapro);

/*!
 * \brief Gets the according Y axis to the letter in parameter.
 * Useful to convert an abapro character chain into a position.
 *
 * \param letter the letter we want the axis from.
 */
int getLetterYAxis(char letter);

/*!
 * \brief Gets the according Z axis to the number in parameter.
 * Useful to convert an abapro character chain into a position.
 *
 * \param number the number we want the axis from.
 */
int getNumberZAxis(int number);

/*!
 * \brief Converts an abapro string into a vector of positions.
 *
 * This method takes an ABA-PRO notation and converts it to vector of positions objects.
 *
 * \param abapro the ABA-PRO notation as a vector of positions.
 *
 * \return the newly created vector of positions.
 */
std::vector<Position> abaproToPosition(const std::string abapro);

// Operator functions
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
//inline Position operator+(const Position &lhs, const Position &rhs);

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

// Inline implementations
bool operator==(const Position &lhs, const Position &rhs)
{
    return lhs.getX() == rhs.getX() && lhs.getY() == rhs.getY() && lhs.getZ() == rhs.getZ();
}

bool operator!=(const Position &lhs, const Position &rhs)
{
    return !(lhs == rhs);
}

/*Position operator+(const Position &lhs, const Position &rhs)
{
    return Position(lhs.getX() + rhs.getX(), lhs.getY() + rhs.getY());
}*/

Position operator-(const Position &lhs, const Position &rhs)
{
    return Position(lhs.getX() - rhs.getX(), lhs.getY() - rhs.getY());
}

void validateLetter(const char letter) // throws
{
    bool valid = false;
    for (const auto &[c, i] : Position::letters_y)
    {
        if (c == letter)
        {
            valid = true;
            break;
        }
    }
    if (!valid)
        throw std::invalid_argument("Invalid ABAPRO, wrong letter input.");
}

void validateNumber(const char number) // throws
{
    bool valid = false;
    for (const auto &[c, i] : Position::numbers_z)
    {
        if (c == number)
        {
            valid = true;
            break;
        }
    }
    if (!valid)
        throw std::invalid_argument("Invalid ABAPRO, wrong number input.");
}

void validateABAPRO(const std::string abapro) // throws
{
    int size = abapro.size();
    if (size != 4 && size != 6)
        throw std::invalid_argument("Invalid ABAPRO, must be 4 or 6 characters long.");

    // Validation of the abapro input. Example : A1B2 or A1B2C3
    for (int i = 0; i < size; ++i)
    {
        char currChar = abapro.at(i);
        if (i % 2 == 0) // The char is a letter
            validateLetter(currChar);
        else if (i % 2 != 0) // The char is a number
            validateNumber(currChar);
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
namespace std
{
    template <>
    struct hash<Position>
    {
    /*!
     * \brief The operator() overload to hash a position.
     *
     * \param p the position to hash.
     *
     * \return the hash value of the position in parameter.
     */
        size_t operator()(const Position &p) const
        {
            hash<int> int_hash;
            size_t px = int_hash(p.getX());
            size_t py = int_hash(p.getY());
            return px ^ (py + 0x9e3779b9 + (px << 6) + (px >> 2));
        }
    };
}

#endif //_POSITION_H
