#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "Game.h"
#include <QPixmap>
#include "MarbleWidget.h"

MainWindow::MainWindow(Game game, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    game_(game)
{
    ui->setupUi(this);

    // Background
    this->setStyleSheet("background-color: gray;");

    // Black counter label + pix
    QPixmap black_marble_pic{":/images/black_marble.png"};
    black_marble_pic = black_marble_pic.scaled(ui->labelBMCpt->width() / 3, ui->labelBMCpt->height());
    ui->labelBMCpt->setPixmap(black_marble_pic);
    int black_lost = game.getBoard().getBlackMarblesLost();
    QString sBlackLabel{QString::number(black_lost) + QString::fromStdString("/6")};
    ui->blackLabelCpt->setText(sBlackLabel);

    // White counter label + pix
    QPixmap white_marble_pic{":/images/white_marble.png"};
    white_marble_pic = white_marble_pic.scaled(ui->labelBMCpt->width() / 3, ui->labelBMCpt->height());
    ui->labelWMCpt->setPixmap(white_marble_pic);
    int white_lost = game.getBoard().getWhiteMarblesLost();
    QString sWhiteLabel{QString::number(white_lost) + QString::fromStdString("/6")};
    ui->whiteLabelCpt->setText(sWhiteLabel);

    // Current player pix
    ui->labelCPM->setPixmap(game.getCurrentPlayer() == Color::BLACK ? black_marble_pic : white_marble_pic);

    // Board TODO : fix decalage
    Board board{game.getBoard()};
    int row = 0, col = 0;
    for(int i = 4; i >= -4; --i)
    {
        int decalage = i / 2;
        for(int j = -4; j <= 4; ++j)
        {
            Position pos(j, i);
            if(board.isInside(pos))
            {
                MarbleWidget *mw{new MarbleWidget(board, pos)};
                //if(decalage % 2 == 0)
                ui->boardGrid->addWidget(mw, row, col + decalage);
            }
            ++col;
            if(col > 8) col = 0;
        }
        ++row;
        if(row > 8) row = 0;
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_moveButton_clicked()
{

}
