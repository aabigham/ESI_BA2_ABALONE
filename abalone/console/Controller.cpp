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
        view_.displayMessage(game_.get_s_currentPlayer() + " is now playing.");
        auto positions = game_.askAbaPro();
        for (const auto& p : positions) {
            std::cout << p << std::endl;
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
