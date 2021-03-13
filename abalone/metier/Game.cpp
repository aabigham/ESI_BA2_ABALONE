#include "Game.h"

Game::Game():
    board_{},
    currentPlayer_{Color::BLACK}
{}

bool Game::isGameOver()
{
    return board_.getBlackMarblesLost()==6||board_.getWhiteMarblesLost()==6;
}
