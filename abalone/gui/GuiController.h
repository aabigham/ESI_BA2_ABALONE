#ifndef GUICONTROLLER_H
#define GUICONTROLLER_H

#include <QObject>

#include "Game.h"
#include "MainWindow.h"
#include "MarbleWidget.h"

class GuiController : public QObject
{
    Q_OBJECT

public:
    GuiController(Game game);

    virtual ~GuiController();

    void initialize();

    void startGame();

    void setupMarbleConnections();

    void setupMoveConnection();

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
    /*!
     * \brief game_ the game model of abalone.
     */
    Game game_;

    /*!
     * \brief mainwindow_ the main window view.
     */
    MainWindow mainwindow_;

    /*!
     * \brief cptSelected_ counts the currenctly selected marbles.
     */
    int cptSelected_;

    /*!
     * \brief positions_ the positions of the each of the selected marbles.
     */
    std::vector<std::unique_ptr<Position>> positions_;
};

#endif // GUICONTROLLER_H
