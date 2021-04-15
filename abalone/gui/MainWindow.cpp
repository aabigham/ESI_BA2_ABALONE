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
    this->setStyleSheet("background-color: darkseagreen;"); // Window background
    QPixmap qpix{game.getCurrentPlayer() == Color::BLACK ? QPixmap{":/images/black_marble.png"}: QPixmap{":/images/white_marble.png"}};
    qpix = qpix.scaled(ui->labelBMCpt->width() / 3, ui->labelBMCpt->height());
    ui->labelCPM->setPixmap(qpix);
    updateLabels(game); // Cpt and current player labels
    updateBoard(game.getBoard()); // Board view
    setupConnections();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateLabels(Game game) const
{
    Board board{game.getBoard()};
    // Black counter label + pix
    QPixmap black_marble_pic{":/images/black_marble.png"};
    black_marble_pic = black_marble_pic.scaled(ui->labelBMCpt->width() / 3, ui->labelBMCpt->height());
    ui->labelBMCpt->setPixmap(black_marble_pic);
    int black_lost = board.getBlackMarblesLost();
    QString sBlackLabel{QString::number(black_lost) + QString::fromStdString("/6")};
    ui->blackLabelCpt->setText(sBlackLabel);
    // White counter label + pix
    QPixmap white_marble_pic{":/images/white_marble.png"};
    white_marble_pic = white_marble_pic.scaled(ui->labelBMCpt->width() / 3, ui->labelBMCpt->height());
    ui->labelWMCpt->setPixmap(white_marble_pic);
    int white_lost = board.getWhiteMarblesLost();
    QString sWhiteLabel{QString::number(white_lost) + QString::fromStdString("/6")};
    ui->whiteLabelCpt->setText(sWhiteLabel);
    // Curr player
    ui->labelCPM->setPixmap(game_.getCurrentPlayer() == Color::BLACK ? black_marble_pic : white_marble_pic);
}

void MainWindow::updateBoard(Board board) const
{
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
                if(i % 2 != 0) widget->setupDecalage();
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

void MainWindow::setupConnections() const
{
    for (int i{0}; i < ui->boardGrid->count(); ++i)
    {
        QLayoutItem *item = ui->boardGrid->itemAt(i);
        if (dynamic_cast<QWidgetItem *>(item))
            connect(item->widget(), SIGNAL(clicked()), this, SLOT(handle_marble_clicked()), Qt::UniqueConnection);
    }
}

void MainWindow::on_moveButton_clicked()
{
    std::vector<Position> positions;
    for (const auto &p : positions_) { positions.push_back(*p); };
    bool flagMove{game_.play(positions)};
    if(flagMove)
    {
        updateBoard(game_.getBoard());
        // Remake the connections cause new wigdets are added after the update
        setupConnections();
        // Reset counter of selecteds
        cptSelected_ = 0;
        // change
        game_.setCurrentPlayer(opposite(game_.getCurrentPlayer()));
        updateLabels(game_);
        // clearing the positions
        positions_.clear();
        // curr
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
        auto pit = std::find(positions_.begin(), positions_.end(),
                             std::make_unique<Position>(pos));
        positions_.erase(pit);
        --cptSelected_;
    }
    else if (flagSelect == 1)
    {
        positions_.push_back(std::make_unique<Position>(pos));
        ++cptSelected_;
    }
    else
    {
        ui->feedbackLabel->setText("Could not select !");
    }
    //setupConnections();
}
