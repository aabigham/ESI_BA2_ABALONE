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
     * \param currentPlayer the current player.
     * \param board the game board.
     */
    void initialize(Color currentPlayer, Board board);

    /*!
     * \brief updateView updates the view of the main window.
     * \param currentPlayer the current player of the game.
     * \param board the game board.
     */
    void updateView(Color currentPlayer, Board board);

    /*!
     * \brief showGameOver shows the game over dialog.
     * \param currentPlayer the current player of the game.
     */
    void showGameOver(Color currentPlayer);

    /*!
     * \brief disableButtons disables the button on the view.
     */
    void disableButtons();

    /*!
     * \brief enableButtons enables the button.
     */
    void enableButtons();

    /*!
     * \brief setFeedbackLabel sets the feedback label.
     * \param text the new feedback.
     */
    void setFeedbackLabel(QString text);

    /*!
     * \brief getBoardGrid gets a pointer to the grid layout containing the marble widgets.
     * \return a pointer to the grid layout containing the marble widgets.
     */
    QGridLayout *getBoardGrid();

    /*!
     * \brief getMoveButton gets a pointer to the move button element.
     * \return a pointer to the move button element.
     */
    QPushButton *getMoveButton();

private:
    /*!
     * \brief setupPixes sets up the pixes on the wain Window
     * \param currentPlayer the current player.
     */
    void initPixes(Color currentPlayer);

    /*!
     * \brief updateLabels updates the labels ont the main window.
     * \param blackMarbleLost the count of lost black marble.
     * \param whiteMarbleLost the count of white black marble.
     * \param currentPlayer the current player.
     */
    void updateLabels(int blackMarbleLost, int whiteMarbleLost,
                      Color currentPlayer);

    /*!
     * \brief updateBoard updates the board view with new MarbleWidgets,
     * also adds the connect feature to each one of them.
     * \param board the game board.
     */
    void updateBoard(Board board);

    /*!
     * \brief deleteBoardWidgets deletes the widgets that are newly created at every board update.
     */
    void deleteBoardWidgets();

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
