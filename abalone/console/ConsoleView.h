#ifndef _CONSOLEVIEW_H
#define _CONSOLEVIEW_H

#include <array>
#include <iomanip>
#include "View.h"
#include "Game.h"
#include "Cell.h"

/*!
* \brief The ConsoleView class
*
* The ConsoleView class displays the game in the console version.
*/
class ConsoleView : public View
{
public:
    /*!
     * \brief displayWelcome Displays the welcome message.
     */
    void displayWelcome();

    /*!
    * \brief This method updates the console view.
    */
    void updateView(Board board);

    /*!
     * \brief diplayMessage Display a message to the console.
     *
     * \param message the message to diplay to the console.
     */
    void displayMessage(std::string message);
};

#endif //_CONSOLEVIEW_H
