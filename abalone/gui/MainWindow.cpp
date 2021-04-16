#include <QPixmap>
#include <QMessageBox>

#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "Game.h"
#include "MarbleWidget.h"

MainWindow::MainWindow(Game game, QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow),
      game_(game),
      cptSelected_(0),
      positions_()
{
    ui->setupUi(this);
    this->setFixedSize(this->size());
    this->setStyleSheet("background-color: darkseagreen;");
    setupPixes();   // Pixes on the window
    updateLabels(); // Cpt labels
    updateBoard();  // Displaying board
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setupPixes()
{
    // Black counter pix
    QPixmap black_marble_pic{":/images/black_marble.png"};
    black_marble_pic = black_marble_pic.scaled(ui->labelBMCpt->width() / 3, ui->labelBMCpt->height());
    ui->labelBMCpt->setPixmap(black_marble_pic);
    // White counter pix
    QPixmap white_marble_pic{":/images/white_marble.png"};
    white_marble_pic = white_marble_pic.scaled(ui->labelBMCpt->width() / 3, ui->labelBMCpt->height());
    ui->labelWMCpt->setPixmap(white_marble_pic);
    // Current player pix
    QPixmap qpix{game_.getCurrentPlayer() == Color::BLACK
                     ? QPixmap{":/images/black_marble.png"}
                     : QPixmap{":/images/white_marble.png"}};
    qpix = qpix.scaled(ui->labelBMCpt->width() / 3, ui->labelBMCpt->height());
    ui->labelCPM->setPixmap(qpix);
}

void MainWindow::updateLabels()
{
    Board board{game_.getBoard()};
    // Black counter label
    int black_lost = board.getBlackMarblesLost();
    QString sBlackLabel{QString::number(black_lost) + QString::fromStdString("/6")};
    ui->blackLabelCpt->setText(sBlackLabel);
    // White counter label
    int white_lost = board.getWhiteMarblesLost();
    QString sWhiteLabel{QString::number(white_lost) + QString::fromStdString("/6")};
    ui->whiteLabelCpt->setText(sWhiteLabel);
    // Curr player
    ui->labelCPM->setPixmap(game_.getCurrentPlayer() == Color::BLACK
                                ? QPixmap{":/images/black_marble.png"}
                                : QPixmap{":/images/white_marble.png"});
}

void MainWindow::updateBoard()
{
    Board board{game_.getBoard()};
    int row = 0, col = 0;
    for (int i{4}; i >= -4; --i)
    {
        int decalage = i / 2;
        for (int j{-4}; j <= 4; ++j)
        {
            Position pos(j, i);
            if (board.isInside(pos))
            {
                MarbleWidget *widget{new MarbleWidget(board, pos)}; // Widget to add
                // Connecting the clicked signal to the handle method
                connect(widget, SIGNAL(clicked()), this, SLOT(handle_marble_clicked()), Qt::UniqueConnection);
                if (i % 2 != 0) // Offset management
                    widget->setOffset();
                if (i == -1 || i == -3) // Offset management + Adding to grid
                    ui->boardGrid->addWidget(widget, row, (col + decalage) - 1);
                else // Adding to grid
                    ui->boardGrid->addWidget(widget, row, col + decalage);
            }
            ++col;
            if (col > 8)
                col = 0; // Reseting col count
        }
        ++row;
        if (row > 8)
            row = 0; // Reseting row count
    }
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
        updateBoard();
        game_.setCurrentPlayer(opposite(game_.getCurrentPlayer()));
        updateLabels();
        positions_.clear(); // Clearing the previously selected positions
        cptSelected_ = 0;   // Reset counter of selected positions
        if (game_.isGameOver())
        {
            this->setEnabled(false);
            // Displaying the winner in a information dialog
            std::string message{"Congratulations to the "
                                + std::string{game_.getCurrentPlayer() == Color::BLACK ? "White" : "Black"}
                                + " player."};
            QMessageBox::information(this, "Game over !",
                                     QString::fromStdString(message),
                                     QString{"Quit"});
            QApplication::quit(); // Quitting when the button is pressed
        }
    }
    else
    {
        ui->feedbackLabel->setText("Could not move !");
    }
}

void MainWindow::handle_marble_clicked()
{
    QObject *obj = sender();                                 // Signal sender
    MarbleWidget *widget{dynamic_cast<MarbleWidget *>(obj)}; // Casting to a MarbleWidget
    Position pos{widget->getPosition()};
    int flagSelect{widget->setSelected(cptSelected_)}; // Checks if the marble got selected or unselected
    if (flagSelect == 0)                               // Unselected
    {
        auto it = std::find(positions_.begin(), positions_.end(), std::make_unique<Position>(pos));
        positions_.erase(it);
        --cptSelected_;
    }
    else if (flagSelect == 1) // Selected
    {
        positions_.push_back(std::make_unique<Position>(pos));
        ++cptSelected_;
    }
    else
    {
        ui->feedbackLabel->setText("Could not select !");
    }
}
