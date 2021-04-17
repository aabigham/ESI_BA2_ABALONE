#include <QMouseEvent>

#include "MarbleWidget.h"
#include "ui_MarbleWidget.h"

MarbleWidget::MarbleWidget(std::optional<Color> color, Position pos, QWidget *parent)
    : QWidget{parent},
      ui{new Ui::MarbleWidget},
      color_{color},
      pos_{pos},
      selected_{false}
{
    ui->setupUi(this);
    // Color of the marble widget
    QPixmap qpix;
    if (color.has_value())
        qpix = QPixmap{color == Color::BLACK ? ":/images/black_marble.png" : ":/images/white_marble.png"};
    else
        qpix = QPixmap{":/images/grey_marble.png"};

    qpix = qpix.scaled(ui->color->width() / 3, ui->color->height());
    ui->color->setPixmap(qpix);
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
    // If trying to select but there's too many that already are selected
    if (!selected_ && cptSelected >= 3)
        return -1;

    if (selected_) // Marble is currently selected
    {
        selected_ = false;
        QPixmap qpix;
        if (color_.has_value())
            qpix = QPixmap{color_ == Color::BLACK ? ":/images/black_marble.png" : ":/images/white_marble.png"};
        else
            qpix = QPixmap{":/images/grey_marble.png"};

        qpix = qpix.scaled(ui->color->width() / 2, ui->color->height() / 2);
        ui->color->setPixmap(qpix);
        return 0; // Success on unselection
    }
    else // Marble is not currently selected
    {
        selected_ = true;
        QPixmap qpix;
        if (color_.has_value())
            qpix = QPixmap{color_ == Color::BLACK ? ":/images/black_selected.png" : ":/images/white_selected.png"};
        else
            qpix = QPixmap{":/images/grey_selected.png"};

        qpix = qpix.scaled(ui->color->width() / 2, ui->color->height() / 2);
        ui->color->setPixmap(qpix);
        return 1; // Success on selection
    }
}

void MarbleWidget::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
        emit clicked();
}
