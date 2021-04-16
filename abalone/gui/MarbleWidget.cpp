#include "MarbleWidget.h"
#include "ui_MarbleWidget.h"
#include <QMouseEvent>

MarbleWidget::MarbleWidget(Board board, Position pos, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MarbleWidget),
    board_(board),
    pos_(pos),
    selected_(false)
{
    ui->setupUi(this);
    // Color
    auto marble_color = board.colorAt(pos);
    if(marble_color.has_value())
    {
        QPixmap qpix{marble_color == Color::BLACK ? ":/images/black_marble.png" : ":/images/white_marble.png"};
        qpix = qpix.scaled(ui->color->width() / 3, ui->color->height());
        ui->color->setPixmap(qpix);
    }
    else
    {
        QPixmap qpix{":/images/grey_marble.png"};
        qpix = qpix.scaled(ui->color->width() / 3, ui->color->height());
        ui->color->setPixmap(qpix);
    }
}

MarbleWidget::~MarbleWidget()
{
    delete ui;
}

void MarbleWidget::setOffset() const
{
    ui->marble->setContentsMargins(25, 0, 0, 0);
}

int MarbleWidget::setSelected(int cptSelected)
{
    int ret;
    auto color = board_.colorAt(pos_);
    QPixmap qpix;
    if(!selected_)
    {
        if(cptSelected < 3)
        {
            selected_ = true;
            if(color.has_value())
                qpix = QPixmap{color == Color::BLACK ? ":/images/black_selected.png" : ":/images/white_selected.png"};
            else
                qpix = QPixmap{":/images/grey_selected.png"};
            ret = 1;
        }
        else{ return -1; }
    }
    else
    {
        selected_ = false;
        if(color.has_value())
            qpix = QPixmap{color == Color::BLACK ? ":/images/black_marble.png" : ":/images/white_marble.png"};
        else
            qpix = QPixmap{":/images/grey_marble.png"};
        ret = 0;
    }
    qpix = qpix.scaled(ui->color->width() / 2, ui->color->height() / 2);
    ui->color->setPixmap(qpix);
    return ret;
}

void MarbleWidget::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
        emit clicked();
}
