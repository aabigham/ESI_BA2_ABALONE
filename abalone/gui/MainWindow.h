#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPixmap>
#include <QGridLayout>
#include <QPushButton>

#include "Game.h"
#include "MarbleWidget.h"

namespace Ui
{
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
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    /*!
     * \brief initialize initializes the main window.
     */
    void initialize(Color currentPlayer, Board board);

    /*!
     * \brief setupPixes sets up the pixes on the wain Window
     */
    void initPixes(Color currentPlayer);

    /*!
     * \brief updateLabels updates the labels ont the main window.
     */
    void updateLabels(int blackMarbleLost, int whiteMarbleLost,
                      Color currentPlayer);

    /*!
     * \brief updateBoard updates the board view with new MarbleWidgets,
     * also adds the connect feature to each one of them.
     */
    void updateBoard(Board board);

    /*!
     * \brief deleteBoardWidgets deletes the widgets that are newly created at every board update.
     */
    void deleteBoardWidgets();

    /*!
     * \brief updateView updates the view of the main window.
     */
    void updateView(Color currentPlayer, Board board);

    /*!
     * \brief showGameOver shows the game over dialog.
     */
    void showGameOver(Color currentPlayer);

    void disableButtons();

    void enableButtons();

    void setFeedbackLabel(QString text);

    QGridLayout *getBoardGrid();

    QPushButton *getMoveButton();

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
};

#endif // MAINWINDOW_H
