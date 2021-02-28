#ifndef _CONSOLEVIEW_H
#define _CONSOLEVIEW_H

#include <array>
#include <View.h>
#include "Cell.h"

/*!
* \brief The ConsoleView class
*
* The ConsoleView class displays the game in the console version.
*/
class ConsoleView: public View {
public: 
    
    /*!
    * \brief Constructor of the ConsoleView class.
    */
    ConsoleView();

    /*!
    * \brief This method updates the console view.
    */
    void updateView();
};

#endif //_CONSOLEVIEW_H
