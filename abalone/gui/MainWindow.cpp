#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "Game.h"
#include <QPixmap>
#include "MarbleWidget.h"

MainWindow::MainWindow(Game game, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    game_(game),
    cptSelected_(0),
    positions_()
{
    ui->setupUi(this);
    this->setFixedSize(this->size());
    this->setStyleSheet("background-color: darkseagreen;"); // Window background
    setupPixes(); // pixes
    updateLabels(); // Cpt labels
    updateBoard(); // Board view
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
    for(int i{4}; i >= -4; --i)
    {
        int decalage = i / 2;
        for(int j{-4}; j <= 4; ++j)
        {
            Position pos(j, i);
            if(board.isInside(pos))
            {
                MarbleWidget *widget{new MarbleWidget(board, pos)};
                // Connecting the clicked signal
                connect(widget, SIGNAL(clicked()), this, SLOT(handle_marble_clicked()), Qt::UniqueConnection);
                if(i % 2 != 0) widget->setOffset();
                if(i == -1 || i == -3) ui->boardGrid->addWidget(widget, row, (col + decalage) - 1);
                else ui->boardGrid->addWidget(widget, row, col + decalage);
            }
            ++col;
            if(col > 8) col = 0;
        }
        ++row;
        if(row > 8) row = 0;
    }
}

void MainWindow::on_moveButton_clicked()
{
    std::vector<Position> positions;
    for (const auto &p : positions_) { positions.push_back(*p); };
    if(positions.size() > 1 && game_.play(positions))
    {
        game_.setCurrentPlayer(opposite(game_.getCurrentPlayer())); // changes current player
        updateLabels();
        updateBoard();
        positions_.clear(); // Clearing the previously selected positions
        cptSelected_ = 0; // Reset counter of selected positions
    }
    else { ui->feedbackLabel->setText("Could not move !"); }
}

void MainWindow::handle_marble_clicked()
{
    QObject *obj = sender();
    MarbleWidget *widget{dynamic_cast<MarbleWidget *>(obj)};
    Position pos{widget->getPosition()};
    int flagSelect{widget->setSelected(cptSelected_)};
    if(flagSelect == 0)
    {
        auto it = std::find(positions_.begin(), positions_.end(), std::make_unique<Position>(pos));
        positions_.erase(it);
        --cptSelected_;
    }
    else if (flagSelect == 1)
    {
        positions_.push_back(std::make_unique<Position>(pos));
        ++cptSelected_;
    }
    else{ ui->feedbackLabel->setText("Could not select !"); }
}
