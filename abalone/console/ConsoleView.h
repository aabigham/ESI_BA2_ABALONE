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
    * \brief Constructor of the ConsoleView class.
    */
    ConsoleView();

    ~ConsoleView();

    /*!
    * \brief This method updates the console view.
    */
    void updateView(Board board);
};

#endif //_CONSOLEVIEW_H
