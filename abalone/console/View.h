#ifndef VIEW_H
#define VIEW_H

#include "Game.h"

/*!
 * \brief The View class
 *
 * The View class is being implemented by the GuiView and the ConsoleView.
 */
class View
{
public:
    /*!
    * \brief Constructor of the View class.
    */
    View();

    virtual ~View();

    /*!
    * \brief This method updates the view (gui or console).
    */
    virtual void updateView(Board board);
};

#endif // VIEW_H
