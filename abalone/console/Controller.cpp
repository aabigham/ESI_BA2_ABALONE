#include "Controller.h"
#include "ConsoleView.h"

Controller::Controller()
    : game_{Game()},
      view_{ConsoleView()}
{
}

void Controller::startGame()
{
    view_.displayWelcome();
    view_.updateView(game_.getBoard());

    while (!game_.isGameOver())
    {
        std::string currPlayer = game_.getCurrentPlayer() == Color::BLACK ? "Black" : "White";
        view_.displayMessage(currPlayer + " is now playing.");
        auto positions = game_.askAbaPro();
        for (const auto &pos : positions) {
            std::cout << pos << std::endl;
        }
        bool moved = game_.play(positions);
        if(!moved)
        {
            view_.displayMessage("\nCould not move, please try again.");
        }
        else
        {
            view_.displayMessage("Move successful !\n");
            view_.updateView(game_.getBoard());
        }
    }
}
