#ifndef _GAME_H
#define _GAME_H

#include <iostream>

#include "Board.h"

/*!
 * \brief The Game class
 * The Game class gathers the necessary elements for the game to present a
 * facade to the view. The view only interacts with this class to access the
 * model
 */
class Game
{
public:
    /*!
     * \brief Constructor of Game.
     */
    Game();

    /*!
     * \brief This method plays a round of abalone.
     */
    bool play(std::vector<Position> positions);

    /*!
     * \brief Checks if the game is over.
     * \return true if the game is over, false otherwise.
     */
    inline bool isGameOver() const; //done

    /*!
     * \brief Asks an ABA-PRO notation to the player.
     * \return the vector of positions according to the ABA-PRO notation.
     */
    std::vector<Position> askAbaPro() const;

    /*!
     * \brief Getter of the game board.
     * \return the board of the game.
     */
    inline Board& getBoard();

    /*!
     * \brief Getter of the current Player.
     * \return the current player as a Color.
     */
    inline Color getCurrentPlayer() const;

    /*!
     * \brief Getter of the current Player.
     * \return the current player as a string.
     */
    inline std::string get_s_currentPlayer() const;

    /*!
     * \brief Setter of the game board.
     * \param color the color of the future current player.
     */
    inline void setCurrentPlayer(Color color);

    /*!
    * \brief Getter of the lost white marbles.
    * \return the number of lost white marble.
    */
    inline int getWhiteMarblesLost() const;

    /*!
    * \brief Getter of the lost black marbles.
    * \return the number of lost black marble.
    */
    inline int getBlackMarblesLost() const;

    /*!
    * \brief Checks if a position is inside the game board.
    * \param pos the position we want to be checking.
    * \return true if the position is inside, false otherwise.
    */
    bool isInside(Position pos) const;

    /*!
    * \brief Gets the color located at the position in parameter.
    * \param pos the position at which we want to find its color
    * \return the color located at the position in parameter.
    */
    std::optional<Color> colorAt(Position pos) const;

private:
    /*!
     * \brief The board of the game.
     */
    Board board_;

    /*!
     * \brief The current player of the game.
     * \return the board of the game.
     */
    Color currentPlayer_;
};

bool Game::isGameOver() const
{
    return board_.getBlackMarblesLost() == 6 || board_.getWhiteMarblesLost() == 6;
}

Board &Game::getBoard()
{
    return board_;
}

Color Game::getCurrentPlayer() const
{
    return currentPlayer_;
}

std::string Game::get_s_currentPlayer() const
{
    return currentPlayer_ == Color::BLACK ? "Black" : "White";
}

void Game::setCurrentPlayer(Color color)
{
    currentPlayer_ = color;
}

int Game::getWhiteMarblesLost() const
{
    return board_.getWhiteMarblesLost();
}

int Game::getBlackMarblesLost() const
{
    return board_.getBlackMarblesLost();
}

#endif //_GAME_H
