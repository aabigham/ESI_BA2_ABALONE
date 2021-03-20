#include "View.h"

View::View()
{
}

View::~View()
{
}

void View::updateView(Board board)
{
    std::cout << "White marble(s) lost : " << board.getBlackMarblesLost() << std::endl;
}
