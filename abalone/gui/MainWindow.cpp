#include <QMessageBox>

#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "Game.h"
#include "MarbleWidget.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow{parent},
      ui{new Ui::MainWindow}
{
    ui->setupUi(this);
    this->setStyleSheet("background-color: darkseagreen;");
    this->setWindowTitle("Abalone - 54985 - 54247");
    this->setWindowIcon(QIcon{":/images/favicon.png"});
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initialize(Color currentPlayer, Board board)
{
    initPixes(currentPlayer);
    updateView(currentPlayer, board);
}

void MainWindow::initPixes(Color currentPlayer)
{
    // Scaling pixes
    black_marble_pic_ = black_marble_pic_.scaled(ui->labelBMCpt->width() / 3,
                                                 ui->labelBMCpt->height());
    white_marble_pic_ = white_marble_pic_.scaled(ui->labelBMCpt->width() / 3,
                                                 ui->labelBMCpt->height());
    // Setting
    ui->labelBMCpt->setPixmap(black_marble_pic_);
    ui->labelWMCpt->setPixmap(white_marble_pic_);
    ui->labelCPM->setPixmap(currentPlayer == Color::BLACK
                                ? black_marble_pic_
                                : white_marble_pic_);
}

void MainWindow::updateLabels(int blackMarbleLost, int whiteMarbleLost,
                              Color currentPlayer)
{
    ui->feedbackLabel->clear();

    ui->blackLabelCpt->setText(QStringLiteral("%1/6").arg(blackMarbleLost));
    ui->whiteLabelCpt->setText(QStringLiteral("%1/6").arg(whiteMarbleLost));

    // Curr player
    ui->labelCPM->setPixmap(currentPlayer == Color::BLACK
                                ? black_marble_pic_
                                : white_marble_pic_);
}

void MainWindow::updateBoard(Board board)
{
    int row = 0, col = 0;
    for (int i{4}; i >= -4; --i)
    {
        int decalage = i / 2;
        for (int j{-4}; j <= 4; ++j)
        {
            Position pos{j, i};
            if (board.isInside(pos))
            {
                // Widget to add
                MarbleWidget *widget{new MarbleWidget(board.colorAt(pos), pos)};

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

void MainWindow::updateView(Color currentPlayer, Board board)
{
    updateLabels(board.getBlackMarblesLost(), board.getWhiteMarblesLost(),
                 currentPlayer);
    deleteBoardWidgets();
    updateBoard(board);
}

void MainWindow::showGameOver(Color currentPlayer)
{
    // Displaying winner in information dialog
    this->setEnabled(false);
    QString winner{currentPlayer == Color::BLACK ? "White" : "Black"};
    QString message{QStringLiteral("Congratulations to the %1 player.\n\nQuitting...")
                        .arg(winner)};
    QMessageBox::information(this, "Game over !", message);
    QApplication::quit(); // Quitting
}

void MainWindow::disableButtons()
{
    ui->moveButton->setDisabled(true);
}

void MainWindow::enableButtons()
{
    ui->moveButton->setDisabled(false);
}

void MainWindow::setFeedbackLabel(QString text)
{
    ui->feedbackLabel->setText(text);
}

QGridLayout *MainWindow::getBoardGrid()
{
    return ui->boardGrid;
}

QPushButton *MainWindow::getMoveButton()
{
    return ui->moveButton;
}
