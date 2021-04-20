#ifndef ABAPRO_H
#define ABAPRO_H

#include <array>
#include <vector>

#include "Position.h"

namespace abapro
{
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

    /*!
    * \brief Validates an ABAPRO letter.
    * \param letter the letter to validate.
    * \throws std::invalid_argument if the letter is not valid.
    */
    bool isLetterValid(char letter);

    /*!
    * \brief Validates an ABAPRO number.
    * \param letter the number to validate.
    * \throws std::invalid_argument if the number is not valid.
    */
    bool isNumberValid(char number);

    /*!
    * \brief isPairValid Checks if a letter - number pair is valid.
    * \param pair the letter - number pair.
    * \return true if the pair is valid, false otherwise.
    */
    bool isPairValid(std::pair<char, char> pair);

    /*!
    * \brief Validates an ABAPRO input.
    * \param letter the input to validate.
    * \throws std::invalid_argument if the input is not valid.
    */
    bool isAbaproValid(std::string abapro);

    /*!
    * \brief Gets the according Y axis to the letter in parameter.
    * Useful to convert an abapro character chain into a position.
    * \param letter the letter we want the axis from.
    */
    int getLetterYAxis(char letter);

    /*!
    * \brief Gets the according Z axis to the number in parameter.
    * Useful to convert an abapro character chain into a position.
    * \param number the number we want the axis from.
    */
    int getNumberZAxis(int number);

    /*!
     * \brief Converts an abapro string into a vector of positions.
     * This method takes an ABA-PRO notation and converts it to vector of positions objects.
     * \param abapro the ABA-PRO notation as a vector of positions.
     * \return the newly created vector of positions.
     */
    std::vector<Position> abaproToPosition(std::string abapro);
}

#endif // ABAPRO_H
