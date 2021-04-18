#include <iostream>

#include "Game.h"

Game::Game()
    : board_{Board()},
      currentPlayer_{Color::BLACK}
{
}

bool Game::play(std::vector<Position> positions)
{
    bool flagMove;
    if(positions.size() == 2)
        flagMove = board_.move(positions.at(0), positions.at(1), currentPlayer_);
    else
        flagMove = board_.move(positions.at(0), positions.at(1), positions.at(2), currentPlayer_);

    return flagMove;
}

std::vector<Position> Game::askAbaPro() const
{
    std::string abapro;
    std::cout << "Please enter an ABAPRO notation :\n";
    std::getline(std::cin, abapro);
    std::transform(abapro.begin(), abapro.end(),abapro.begin(), ::toupper);
    while (!isAbaproValid(abapro))
    {
        std::cout << "Input is not valid, please try again :\n";
        std::getline(std::cin, abapro);
        std::transform(abapro.begin(), abapro.end(),abapro.begin(), ::toupper);
    }
    return abaproToPosition(abapro);
}

bool Game::isInside(Position pos) const
{
    return board_.isInside(pos);
}

std::optional<Color> Game::colorAt(Position pos) const
{
    return board_.colorAt(pos);
}
