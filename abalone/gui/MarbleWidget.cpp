#include "MarbleWidget.h"
#include "ui_MarbleWidget.h"

MarbleWidget::MarbleWidget(Position pos, Board board, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MarbleWidget),
    pos_(pos)
{
    ui->setupUi(this);
    // Color
    auto color = board.colorAt(pos);
    if(color.has_value())
    {
        QPixmap pix(color == Color::BLACK ? ":/images/black_marble.png" : ":/images/white_marble.png");
        pix = pix.scaled(ui->color->width() / 3, ui->color->height());
        ui->color->setPixmap(pix);
    }
}

MarbleWidget::~MarbleWidget()
{
    delete ui;
}
