#ifndef _VIEW_H
#define _VIEW_H

#include <array>
#include "Cell.h"

class View {
public: 
    
/*!
 * \brief Constructor of the View class.
 */
View();
    
/*!
 * \brief Displays the board of the game.
 *
 * \param cells the cells of the board.
 */
void displayBoard(std::array<Cell, 61> cells);
    
/*!
 * \brief Displays the number of lost marbles to the players.
 */
void displayNbMarblesLost();
    
/*!
 * \brief Displays the game over message.
 */
void displayGameOver();
};

#endif //_VIEW_H
