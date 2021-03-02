#ifndef VIEW_H
#define VIEW_H

#include "Game.h"

/*!
 * \brief The View class
 *
 * The View class is being implemented by the GuiView and the ConsoleView.
 */
class View {
public:

    /*!
    * \brief Constructor of the View class.
    */
    View();

    /*!
    * \brief This method updates the view (gui or console).
    */
    virtual void updateView(int whiteMarblesLost, int blackMarblesLost,
                            std::unordered_map<Position, Cell> cells);
};

#endif // VIEW_H
