#ifndef MARBLEWIDGET_H
#define MARBLEWIDGET_H

#include <QWidget>
#include <QLabel>
#include "Position.h"
#include "Board.h"

namespace Ui {
class MarbleWidget;
}

class MarbleWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MarbleWidget(Board board, Position pos, QWidget *parent = nullptr);
    ~MarbleWidget();

    inline Position getPosition() const;

    void setupDecalage() const;

    // 1 slect 0 unselect -1 error
    int setSelected(int cptSelected);

signals:
    void clicked();

protected:
    void mousePressEvent(QMouseEvent *event) override;

private:
    Ui::MarbleWidget *ui;

    Board board_;

    Position pos_;

    bool selected_;
};

Position MarbleWidget::getPosition() const
{
    return pos_;
}

#endif // MARBLEWIDGET_H
