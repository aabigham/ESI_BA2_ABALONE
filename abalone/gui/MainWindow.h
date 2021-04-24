#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPixmap>

#include "Game.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /*!
     * \brief MainWindow constructor of the main window.
     * \param game the model class of Abalone.
     * \param parent the parent of the main window.
     */
    explicit MainWindow(Game game, QWidget *parent = nullptr);
    ~MainWindow();

    /*!
     * \brief initialize initializes the main window.
     */
    void initialize();

private:
    /*!
     * \brief setupPixes sets up the pixes on the wain Window
     */
    void initPixes();

    /*!
     * \brief updateLabels updates the labels ont the main window.
     */
    void updateLabels();

    /*!
     * \brief updateBoard updates the board view with new MarbleWidgets,
     * also adds the connect feature to each one of them.
     */
    void updateBoard();

    /*!
     * \brief deleteBoardWidgets deletes the widgets that are newly created at every board update.
     */
    void deleteBoardWidgets();

    /*!
     * \brief updateView updates the view of the main window.
     */
    void updateView();

    /*!
     * \brief showGameOver shows the game over dialog.
     */
    void showGameOver();

private slots:
    /*!
     * \brief on_moveButton_clicked slot for the move button.
     */
    void on_moveButton_clicked();

    /*!
     * \brief handle_marble_clicked slot for a clicked marble.
     */
    void handle_marble_clicked();

private:
    Ui::MainWindow *ui;

    /*!
     * \brief black_marble_pic_ the black marble qpix.
     */
    QPixmap black_marble_pic_{":/images/black_marble.png"};

    /*!
     * \brief white_marble_pic_ the white marble qpix.
     */
    QPixmap white_marble_pic_{":/images/white_marble.png"};

    /*!
     * \brief game_ the model class of Abalone.
     */
    Game game_;

    /*!
     * \brief cptSelected_ counts the currenctly selected marbles.
     */
    int cptSelected_;

    /*!
     * \brief positions_ the positions of the each of the selected marbles.
     */
    std::vector<std::unique_ptr<Position>> positions_;
};

#endif // MAINWINDOW_H
