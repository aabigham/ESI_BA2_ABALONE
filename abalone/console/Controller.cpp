#include "Controller.h"

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
        try
        {
            view_.displayMessage("--> " + game_.get_s_currentPlayer() + " is now playing.");
            auto positions = game_.askAbaPro();
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
        catch (const std::exception &e)
        {
            std::cout << "Unexpected exception : " << e.what() << std::endl;
        }
    }
}
