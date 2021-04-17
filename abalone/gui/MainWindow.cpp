#include <QMessageBox>

#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "Game.h"
#include "MarbleWidget.h"

MainWindow::MainWindow(Game game, QWidget *parent)
    : QMainWindow{parent},
      ui{new Ui::MainWindow},
      game_{game},
      cptSelected_{0},
      positions_{}
{
    ui->setupUi(this);
    this->setFixedSize(this->size());
    this->setStyleSheet("background-color: darkseagreen;");
    this->setWindowTitle("Abalone - 54985 - 54247");
    initPixes();  // Pixes on the main window
    updateView(); // Updating view (labels of lost marbles + board)
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initPixes()
{
    // Black counter pix
    black_marble_pic_ = black_marble_pic_.scaled(ui->labelBMCpt->width() / 3, ui->labelBMCpt->height());
    ui->labelBMCpt->setPixmap(black_marble_pic_);
    // White counter pix
    white_marble_pic_ = white_marble_pic_.scaled(ui->labelBMCpt->width() / 3, ui->labelBMCpt->height());
    ui->labelWMCpt->setPixmap(white_marble_pic_);
    // Current player pix
    ui->labelCPM->setPixmap(game_.getCurrentPlayer() == Color::BLACK ? black_marble_pic_ : white_marble_pic_);
}

void MainWindow::updateLabels()
{
    // Black counter label
    int black_lost = game_.getBlackMarblesLost();
    QString sBlackLabel{QString::number(black_lost) + QString::fromStdString("/6")};
    ui->blackLabelCpt->setText(sBlackLabel);
    // White counter label
    int white_lost = game_.getWhiteMarblesLost();
    QString sWhiteLabel{QString::number(white_lost) + QString::fromStdString("/6")};
    ui->whiteLabelCpt->setText(sWhiteLabel);
    // Curr player
    ui->labelCPM->setPixmap(game_.getCurrentPlayer() == Color::BLACK ? black_marble_pic_ : white_marble_pic_);
}

void MainWindow::updateBoard()
{
    int row = 0, col = 0;
    for (int i{4}; i >= -4; --i)
    {
        int decalage = i / 2;
        for (int j{-4}; j <= 4; ++j)
        {
            Position pos(j, i);
            if (game_.isInside(pos))
            {
                MarbleWidget *widget{new MarbleWidget(game_.colorAt(pos), pos)}; // Widget to add
                // Connecting the clicked signal to the handle method :
                QObject::connect(widget, SIGNAL(clicked()), this,
                                 SLOT(handle_marble_clicked()), Qt::UniqueConnection);
                if (i % 2 != 0) // Offset management
                    widget->setOffset();
                if (i == -1 || i == -3) // Another offset management + Adding to grid
                    ui->boardGrid->addWidget(widget, row, (col + decalage) - 1);
                else // Adding to grid
                    ui->boardGrid->addWidget(widget, row, col + decalage);
            }
            if (++col > 8)
                col = 0; // Reseting col count
        }
        if (++row > 8)
            row = 0; // Reseting row count
    }
}

void MainWindow::updateView()
{
    updateLabels();
    updateBoard();
}

void MainWindow::on_moveButton_clicked()
{
    std::vector<Position> positions;
    for (const auto &p : positions_)
    {
        positions.push_back(*p);
    }
    if (positions.size() > 1 && game_.play(positions))
    {
        ui->feedbackLabel->clear();
        game_.setCurrentPlayer(opposite(game_.getCurrentPlayer()));
        updateView();
        positions_.clear(); // Clearing the previously selected positions
        cptSelected_ = 0;   // Resets counter of selected positions
        if (game_.isGameOver())
        {
            this->setEnabled(false); // Disabling ui
            // Displaying the winner in an information dialog
            std::string message{"Congratulations to the "
                                + std::string{game_.getCurrentPlayer() == Color::BLACK ? "White" : "Black"}
                                + " player."};
            QMessageBox::information(this, "Game over !", QString::fromStdString(message), QString{"Quit"});
            QApplication::quit(); // Quitting after the dialog has closed
        }
    }
    else
    {
        ui->feedbackLabel->setText("Could not move !");
    }
}

void MainWindow::handle_marble_clicked()
{
    MarbleWidget *widget{qobject_cast<MarbleWidget *>(QObject::sender())}; // Signal's sender
    Position pos{widget->getPosition()};
    int flagSelect{widget->setSelected(cptSelected_)}; // Checks if the marble got selected or unselected
    if (flagSelect == 0) // Marble is not selected
    {
        auto it = std::find(positions_.begin(), positions_.end(), std::make_unique<Position>(pos));
        positions_.erase(it);
        --cptSelected_;
    }
    else if (flagSelect == 1) // Marble is selected
    {
        positions_.push_back(std::make_unique<Position>(pos));
        ++cptSelected_;
    }
    else // Not able to select
    {
        ui->feedbackLabel->setText("Could not select !");
    }
}
