#include <iostream>

#include "Game.h"

Game::Game()
    : board_{Board()},
      currentPlayer_{Color::BLACK}
{
}

bool Game::play(std::vector<Position> positions)
{
    if(!colorAt(positions.at(0)).has_value())
        return false;
    else if(colorAt(positions.at(0)).value() != currentPlayer_)
        return false;
    else if(positions.size() == 3 && colorAt(positions.at(1)) != currentPlayer_)
        return false;

    bool flagMove;
    if(positions.size() == 2)
        flagMove = board_.move(positions.at(0), positions.at(1));
    else
        flagMove = board_.move(positions.at(0), positions.at(1), positions.at(2));

    if(flagMove)
        setCurrentPlayer(opposite(currentPlayer_));

    return flagMove;
}

bool Game::isInside(Position pos) const
{
    return board_.isInside(pos);
}

std::optional<Color> Game::colorAt(Position pos) const
{
    return board_.colorAt(pos);
}
