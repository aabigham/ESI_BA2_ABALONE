#ifndef MARBLEWIDGET_H
#define MARBLEWIDGET_H

#include <QWidget>

namespace Ui {
class MarbleWidget;
}

class MarbleWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MarbleWidget(QWidget *parent = nullptr);
    ~MarbleWidget();

private:
    Ui::MarbleWidget *ui;
};

#endif // MARBLEWIDGET_H
