#ifndef _CONTROLLER_H
#define _CONTROLLER_H

#include "Game.h"
#include "Board.h"
#include "ConsoleView.h"

/*!
 * \brief The Controller class
 *
 * The controller is responsible for the dynamics of the game and for updating the view as it progresses.
 */
class Controller
{
public:
    /*!
    * \brief Constructor of the Controller.
    *
    * \param game the game.
    *
    * \param view the view of the game.
    */
    Controller(Game game, View view);

    /*!
    * \brief Starts the game.
    */
    void startGame();

private:

    /*!
     * \brief The board of the game.
     */
    Game game_;

    /*!
     * \brief The board of the game.
     */
    View view_;
};

#endif //_CONTROLLER_H
