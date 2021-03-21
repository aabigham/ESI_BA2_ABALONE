#include <iostream>
#include <iomanip>
#include "ConsoleView.h"

void ConsoleView::updateView(Board board)
{
    std::cout << "White marble(s) lost : " << board.getWhiteMarblesLost() << std::endl;
    std::cout << "Black marble(s) lost : " << board.getBlackMarblesLost() << std::endl << std::endl;
    for(int i = 4; i >= -4; --i)
    {
        std::cout << "+----+----+----+----+----+----+----+----+----+" << std::endl << "| ";

        int decalage = i < 0 ? -i : i;
        for (int z = 0; z < decalage / 2 ; ++z)
        {
            std::cout << std::setw(2) << " " << " | ";
        }

        for(int j = -4; j <= 4; ++j)
        {
            Position pos(j, i);
            if(board.isInside(pos))
                std::cout << std::setw(2) << board.getCellAt(pos) << " | ";
        }

        for (int z = 0; z < decalage / 2 ; ++z)
        {
            std::cout << std::setw(2) << " " << " | ";
        }

        std::cout << std::endl;
    }
    std::cout << "+----+----+----+----+----+----+----+----+----+" << std::endl << std::endl;
}
