#include "MarbleWidget.h"
#include "ui_MarbleWidget.h"

MarbleWidget::MarbleWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MarbleWidget)
{
    ui->setupUi(this);
}

MarbleWidget::~MarbleWidget()
{
    delete ui;
}
