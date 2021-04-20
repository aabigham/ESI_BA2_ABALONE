#include "Abapro.h"

namespace abapro
{
    int getLetterYAxis(char letter)
    {
        for (const auto &[c, i] : abapro::letters_y)
            if (c == letter)
                return i;
        throw std::invalid_argument("The letter does not exist.");
    }

    int getNumberZAxis(int number)
    {
        for (const auto &[c, i] : abapro::numbers_z)
            if (c == number)
                return i;
        throw std::invalid_argument("The number does not exist.");
    }

    bool isLetterValid(char letter)
    {
        for (const auto &[c, i] : abapro::letters_y)
            if (c == letter)
                return true;
        return false;
    }

    bool isNumberValid(char number)
    {
        for (const auto &[c, i] : abapro::numbers_z)
            if (c == number)
                return true;
        return false;
    }

    bool isPairValid(std::pair<char, char> pair)
    {
        char letter = pair.first;
        char number = pair.second;
        if (!(isLetterValid(letter) && isNumberValid(number)))
            return false;

        int n = number - 48; // Converts the char to int
        switch (letter)
        {
        case 'A':
            return (n <= 5);
        case 'B':
            return (n <= 6);
        case 'C':
            return (n <= 7);
        case 'D':
            return (n <= 8);
        case 'E':
            return (n <= 9);
        case 'F':
            return (n >= 2);
        case 'G':
            return (n >= 3);
        case 'H':
            return (n >= 4);
        case 'I':
            return (n >= 5);
        default:
            return false;
        }
    }

    bool isAbaproValid(std::string abapro)
    {
        int size = abapro.size();
        if (size != 4 && size != 6)
            return false;
        // Checking each pair
        for (int i = 0; i < size - 1; i += 2)
        {
            auto currPair{std::make_pair(abapro.at(i), abapro.at(i + 1))};
            if (!isPairValid(currPair))
                return false;
        }
        return true;
    }

    std::vector<Position> abaproToPosition(std::string abapro)
    {
        if(!isAbaproValid(abapro))
            throw std::invalid_argument("The abapro input is not valid.");

        // Make a position out of each pair then pushing to the back of the vector
        std::vector<Position> ret;
        for (size_t i = 0; i < abapro.size() - 1; i += 2)
        {
            int y = getLetterYAxis(abapro.at(i));
            int z = getNumberZAxis(abapro.at(i + 1));
            int x = - (y + z);
            ret.push_back(Position(x, y, z));
        }
        return ret;
    }
}
