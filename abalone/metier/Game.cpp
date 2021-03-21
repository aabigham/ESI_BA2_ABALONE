#include <iostream>
#include "Game.h"

Game::Game()
    : board_{},
      currentPlayer_{Color::BLACK}
{
}

void Game::play()
{
    // TODO
    std::cout << "PLAY\n";
}

std::vector<Position> Game::askAbaPro() const
{
    std::string abapro;
    std::cout << "Please enter an ABAPRO notation :\n";
    std::getline(std::cin, abapro);
    while (!isAbaproValid(abapro))
    {
        std::cout << "Input is not valid, please enter an valid notation :\n";
        std::getline(std::cin, abapro);
    }
    return abaproToPosition(abapro);
}
