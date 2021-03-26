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
            view_.displayMessageln("--> " + game_.get_s_currentPlayer() + " is now playing.");
            auto positions{game_.askAbaPro()};
            bool moved{game_.play(positions)};
            if(moved)
            {
                view_.displayMessageln("Move successful !\n");
                game_.setCurrentPlayer(opposite(game_.getCurrentPlayer()));
                view_.updateView(game_.getBoard());
            }
            else
            {
                view_.displayMessageln("\nCould not move, please try again.");
            }
        }
        catch (const std::exception &e)
        {
            std::cout << "Unexpected exception : " << e.what() << std::endl;
        }
    }
    std::string winner{game_.getCurrentPlayer() == Color::BLACK ? "White" : "Black"};
    view_.displayMessageln(winner + " player won, congratulations !");
}
