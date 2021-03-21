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
    view_.updateView(game_.getBoard());

    while (!game_.isGameOver())
    {
        std::string currPlayer = game_.getCurrentPlayer() == Color::BLACK ? "White" : "Black";
        view_.displayMessage(currPlayer + " is now playing.");
        auto positions = game_.askAbaPro();
        bool moved = game_.play(positions);
        if(!moved)
        {
            view_.displayMessage("\nCould not move, please try again.");
        }
        else
        {
            view_.displayMessage("Move successful ! Next player's turn now.");
            view_.updateView(game_.getBoard());
        }
    }
}
