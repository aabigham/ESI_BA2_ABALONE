#ifndef _CONSOLEVIEW_H
#define _CONSOLEVIEW_H

#include <iomanip>
#include "View.h"

/*!
* \brief The ConsoleView class
*
* The ConsoleView class displays the game in the console version.
*/
class ConsoleView : public View
{
public:
    /*!
    * \brief This method updates the console view.
    */
    void updateView(Board board);

    /*!
     * \brief displayWelcome Displays the welcome message.
     */
    void displayWelcome();

    /*!
     * \brief diplayMessage Display a message to the console.
     *
     * \param message the message to diplay to the console.
     */
    void displayMessageln(std::string message);
};

#endif //_CONSOLEVIEW_H
