#include "Controller.h"

Controller::Controller()
    : game_{Game()},
      view_{ConsoleView()}
{
}

std::vector<Position> Controller::askAbaPro() const
{
    std::string abapro;
    std::cout << "Please enter an ABAPRO notation :\n";
    std::getline(std::cin, abapro);
    std::transform(abapro.begin(), abapro.end(),abapro.begin(), ::toupper);
    while (!abapro::isAbaproValid(abapro))
    {
        std::cout << "Input is not valid, please try again :\n";
        std::getline(std::cin, abapro);
        std::transform(abapro.begin(), abapro.end(),abapro.begin(), ::toupper);
    }
    return abapro::abaproToPosition(abapro);
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
            auto positions{askAbaPro()};
            if(game_.play(positions))
            {
                view_.displayMessageln("Move successful !\n");
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
