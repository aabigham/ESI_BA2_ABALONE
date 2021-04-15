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

    void setupConnections();

private slots:
    void on_moveButton_clicked();

    void handle_marble_clicked();

private:
    Ui::MainWindow *ui;

    Game game_;

    int cptSelected_;
};

#endif // MAINWINDOW_H
