#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Game.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(Game game, QWidget *parent = nullptr);
    ~MainWindow();

    void updateBoard(Board board);

    void updateLabels(Game game);

private slots:
    void on_moveButton_clicked();

private:
    Ui::MainWindow *ui;

    Game game_;
};

#endif // MAINWINDOW_H
