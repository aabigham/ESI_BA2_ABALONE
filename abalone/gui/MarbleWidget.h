#ifndef MARBLEWIDGET_H
#define MARBLEWIDGET_H

#include <QWidget>
#include "Position.h"
#include "Board.h"

namespace Ui {
class MarbleWidget;
}

class MarbleWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MarbleWidget(Position pos, Board board, QWidget *parent = nullptr);
    ~MarbleWidget();

private:
    Ui::MarbleWidget *ui;

    Position pos_;
};

#endif // MARBLEWIDGET_H
