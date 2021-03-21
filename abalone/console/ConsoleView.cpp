#include <iostream>
#include <iomanip>
#include "ConsoleView.h"
#include "Position.h"

void ConsoleView::displayWelcome()
{
    std::cout << "==============WELCOME==============\n";
    std::cout << "================TO=================\n";
    std::cout << "==============ABALONE==============\n\n";
}

void ConsoleView::displayMessage(std::string message)
{
    std::cout << message << std::endl;
}

void ConsoleView::updateView(Board board)
{
    std::cout << "White marble(s) lost : " << board.getWhiteMarblesLost() << std::endl;
    std::cout << "Black marble(s) lost : " << board.getBlackMarblesLost() << std::endl << std::endl;
    for(int i = 4; i >= -4; --i)
    {
        std::cout << std::endl << "  ";

        int decalage = i < 0 ? -i : i;
        for (int z = 0; z < decalage / 2 ; ++z)
            std::cout << std::setw(2) << " " << "   ";

        if(decalage % 2 != 0)
            std::cout << std::setw(2) << " ";

        for (const auto &[c, y] : Position::letters_y) {
            if(i == y)
                std::cout << c << (i > 0 ? "/" : i == 0 ? "|" : "\\") << std::setw(4) << " ";
        }

        for(int j = -4; j <= 4; ++j)
        {
            Position pos(j, i);
            if(board.isInside(pos))
                std::cout << std::setw(2) << board.getCellAt(pos) << "   ";
        }
        if(i < 0)
            std::cout << std::setw(2) << " " << "/" <<i + 10 ;
        std::cout << std::endl;
    }
    std::cout << std::endl << std::setw(21) << " " << "1    2    3    4    5" << std::endl << std::endl;
}
