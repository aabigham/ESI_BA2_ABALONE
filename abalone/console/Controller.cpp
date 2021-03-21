#include "Controller.h"
#include "ConsoleView.h"

Controller::Controller(Game game, ConsoleView cv)
    : game_{game},
      view_{cv}
{
}

void Controller::startGame()
{
    view_.displayWelcome();
    while (!game_.isGameOver())
    {
        view_.updateView(game_.getBoard());

        std::string currPlayer = game_.getCurrentPlayer() == Color::BLACK ? "White" : "Black";
        view_.displayMessage(currPlayer + " is now playing : ");

        auto positions = game_.askAbaPro();
        bool moved = game_.play(positions);
        if(!moved)
            view_.displayMessage("Could not move, please try again.");
        else
            view_.displayMessage("Move successful ! Next player's turn now.");
    }
}
