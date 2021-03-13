#ifndef _GAME_H
#define _GAME_H

#include "Position.h"
#include "Board.h"

/*!
 * \brief The Game class
 *
 * The Game class gathers the necessary elements for the game to present a
 * facade to the view. The view only interacts with this class to access the
 * model
 */
class Game {
public: 
    
    /*!
     * \brief Constructor of Game.
     */
    Game();

    /*!
     * \brief Starts the game.
     */
    void start();

    /*!
     * \brief Checks if the game is over.
     *
     * \return true if the game is over, false otherwise.
     */
    bool isGameOver();//done

    /*!
     * \brief This method plays a round of abalone.
     */
    void play();

    /*!
     * \brief Asks an ABA-PRO notation to the player.
     *
     * \return a case position according to the ABA-PRO notation.
     */
    Position askAbaPro();

    /*!
     * \brief Getter of the game board.
     *
     * \return the board of the game.
     */
    inline Board& getBoard() ;//done

    /*!
     * \brief Getter of the current Player.
     *
     * \return the current player, as a Color.
     */
    inline Color getCurrentPlayer() const;//done

    /*!
     * \brief Setter of the game board.
     *
     * \param color the color of the future current player.
     */
    inline void setCurrentPlayer(Color color);//done

private:

    /*!
     * \brief The board of the game.
     */
    Board board_;

    /*!
     * \brief The current player of the game.
     *
     * \return the board of the game.
     */
    Color currentPlayer_;
};

Board& Game::getBoard()
{
    return board_;
}

Color Game::getCurrentPlayer() const
{
    return currentPlayer_;
}

void Game::setCurrentPlayer(Color color)
{
    currentPlayer_=color;
}
#endif //_GAME_H
