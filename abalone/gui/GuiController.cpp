#include "GuiController.h"

GuiController::GuiController(Game game)
    : game_{game},
      mainwindow_{MainWindow{}},
      cptSelected_{0},
      positions_{}
{
}

GuiController::~GuiController()
{
}

void GuiController::initialize()
{
    mainwindow_.initialize(game_.getCurrentPlayer(), game_.getBoard());
    setupMarbleConnections();
    setupMoveConnection();
}

void GuiController::startGame()
{
    mainwindow_.show();
}

void GuiController::setupMarbleConnections()
{
    QGridLayout *boardgrid{mainwindow_.getBoardGrid()};
    for (int i{0}; i < boardgrid->count(); ++i)
    {
        MarbleWidget *widget{qobject_cast<MarbleWidget *>(boardgrid->itemAt(i)->widget())};
        QObject::connect(widget, SIGNAL(clicked()), this,
                         SLOT(handle_marble_clicked()), Qt::UniqueConnection);
    }
}

void GuiController::setupMoveConnection()
{
    QPushButton *moveButton{mainwindow_.getMoveButton()};
    QObject::connect(moveButton, SIGNAL(clicked()), this,
                     SLOT(on_moveButton_clicked()), Qt::UniqueConnection);
}

// Slots :
void GuiController::on_moveButton_clicked()
{
    mainwindow_.disableButtons();
    std::vector<Position> positions;
    for (const auto &p : positions_)
        positions.push_back(*p);

    if (positions.size() > 1 && game_.play(positions))
    {
        positions_.clear();               // Clearing the previously selected positions
        cptSelected_ = 0;                 // Resets counter of selected positions
        mainwindow_.deleteBoardWidgets(); // Deletes the previous board widgets
        mainwindow_.updateView(game_.getCurrentPlayer(), game_.getBoard());
        setupMarbleConnections(); // setup connections again cause deleted widgets

        if (game_.isGameOver())
            mainwindow_.showGameOver(game_.getCurrentPlayer());
    }
    else
    {
        mainwindow_.setFeedbackLabel("Could not move !");
    }
    mainwindow_.enableButtons();
}

void GuiController::handle_marble_clicked()
{
    // Signal's sender
    MarbleWidget *widget{qobject_cast<MarbleWidget *>(QObject::sender())};
    Position pos{widget->getPosition()};

    // Checks if marble got selected / unselected
    int flagSelect{widget->setSelected(cptSelected_)};
    if (flagSelect == 0)
    {
        // Marble got unselected
        auto it = std::find(positions_.begin(), positions_.end(),
                            std::make_unique<Position>(pos));
        positions_.erase(it);
        --cptSelected_;
    }
    else if (flagSelect == 1)
    {
        // Marble got selected
        positions_.push_back(std::make_unique<Position>(pos));
        ++cptSelected_;
        /*

        if(cptSelected_ == 2 && (*positions_[0]).isNextTo(*positions_[1]))
        {
            // Move
            on_moveButton_clicked();
        }
        else if(cptSelected_ == 3)
        {
            // Move
            on_moveButton_clicked();
        }*/
    }
    else // Not able to select
    {
        mainwindow_.setFeedbackLabel("Could not select !");
    }
}
