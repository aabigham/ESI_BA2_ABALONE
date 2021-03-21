#include <iostream>
#include "Game.h"

Game::Game()
    : board_{},
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

    if(flagMove)
    {
        Color oppositePlayer = (currentPlayer_ == Color::BLACK ? Color::WHITE : Color::BLACK);
        setCurrentPlayer(oppositePlayer);
    }

    return flagMove;
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
