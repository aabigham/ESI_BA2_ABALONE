#include "MarbleWidget.h"
#include "ui_MarbleWidget.h"

MarbleWidget::MarbleWidget(Board board, Position pos, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MarbleWidget),
    pos_(pos)
{
    ui->setupUi(this);
    // Color
    auto color = board.colorAt(pos);
    if(color.has_value())
    {
        QPixmap qpix{color == Color::BLACK ? ":/images/black_marble.png" : ":/images/white_marble.png"};
        qpix = qpix.scaled(ui->color->width() / 3, ui->color->height());
        ui->color->setPixmap(qpix);
    }
    else
    {
        QPixmap qpix{":/images/empty_circle.png"};
        qpix = qpix.scaled(ui->color->width() / 3, ui->color->height());
        ui->color->setPixmap(qpix);
    }
}

MarbleWidget::~MarbleWidget()
{
    delete ui;
}
