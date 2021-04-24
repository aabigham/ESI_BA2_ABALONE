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
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initialize()
{
    this->setStyleSheet("background-color: darkseagreen;");
    this->setWindowTitle("Abalone - 54985 - 54247");
    this->setWindowIcon(QIcon{":/images/favicon.png"});
    initPixes();
    updateView();
}

void MainWindow::initPixes()
{
    // Scaling pixes
    black_marble_pic_ = black_marble_pic_.scaled(ui->labelBMCpt->width() / 3,
                                                 ui->labelBMCpt->height());
    white_marble_pic_ = white_marble_pic_.scaled(ui->labelBMCpt->width() / 3,
                                                 ui->labelBMCpt->height());
    // Setting
    ui->labelBMCpt->setPixmap(black_marble_pic_);
    ui->labelWMCpt->setPixmap(white_marble_pic_);
    ui->labelCPM->setPixmap(game_.getCurrentPlayer() == Color::BLACK
                                ? black_marble_pic_
                                : white_marble_pic_);
}

void MainWindow::updateLabels()
{
    ui->feedbackLabel->clear();

    int black_lost = game_.getBlackMarblesLost();
    ui->blackLabelCpt->setText(QStringLiteral("%1/6").arg(black_lost));
    int white_lost = game_.getWhiteMarblesLost();
    ui->whiteLabelCpt->setText(QStringLiteral("%1/6").arg(white_lost));

    // Curr player
    ui->labelCPM->setPixmap(game_.getCurrentPlayer() == Color::BLACK
                                ? black_marble_pic_
                                : white_marble_pic_);
}

void MainWindow::updateBoard()
{
    int row = 0, col = 0;
    for (int i{4}; i >= -4; --i)
    {
        int decalage = i / 2;
        for (int j{-4}; j <= 4; ++j)
        {
            Position pos{j, i};
            if (game_.isInside(pos))
            {
                // Widget to add
                MarbleWidget *widget{new MarbleWidget(game_.colorAt(pos), pos)};
                // And connecting the widget's clicked signal to the handle method
                QObject::connect(widget, SIGNAL(clicked()), this,
                                 SLOT(handle_marble_clicked()), Qt::UniqueConnection);

                if (i % 2 != 0) // Offset management
                    widget->setOffset();
                if (i == -1 || i == -3) // Another offset management
                    ui->boardGrid->addWidget(widget, row, (col + decalage) - 1);
                else // Adding to grid if no offset needed
                    ui->boardGrid->addWidget(widget, row, col + decalage);
            }
            if (++col > 8)
                col = 0; // Reseting col count
        }
        if (++row > 8)
            row = 0; // Reseting row count
    }
}

void MainWindow::deleteBoardWidgets()
{
    QLayoutItem *child{nullptr};
    while ((child = ui->boardGrid->takeAt(0)) != 0)
        delete child->widget();
}

void MainWindow::updateView()
{
    updateLabels();
    updateBoard();
}

void MainWindow::showGameOver()
{
    // Displaying winner in information dialog
    this->setEnabled(false);
    QString winner{game_.getCurrentPlayer() == Color::BLACK ? "White" : "Black"};
    QString message{QStringLiteral("Congratulations to the %1 player.\n\nQuitting...")
                        .arg(winner)};
    QMessageBox::information(this, "Game over !", message);
    QApplication::quit(); // Quitting
}

// Slots :
void MainWindow::on_moveButton_clicked()
{
    ui->moveButton->setDisabled(true);
    std::vector<Position> positions;
    for (const auto &p : positions_)
        positions.push_back(*p);

    if (positions.size() > 1 && game_.play(positions))
    {
        positions_.clear();   // Clearing the previously selected positions
        cptSelected_ = 0;     // Resets counter of selected positions
        deleteBoardWidgets(); // Deletes the previous board widgets
        updateView();

        if (game_.isGameOver())
            showGameOver();
    }
    else
    {
        ui->feedbackLabel->setText("Could not move !");
    }
    ui->moveButton->setDisabled(false);
}

void MainWindow::handle_marble_clicked()
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
    }
    else // Not able to select
    {
        ui->feedbackLabel->setText("Could not select !");
    }
}
