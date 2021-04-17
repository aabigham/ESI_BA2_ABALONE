#ifndef MARBLEWIDGET_H
#define MARBLEWIDGET_H

#include <QWidget>

#include "Game.h"

namespace Ui {
class MarbleWidget;
}

class MarbleWidget : public QWidget
{
    Q_OBJECT

public:
    /*!
     * \brief MarbleWidget the marble widget for each marble on the board.
     * \param game the model class of the game.
     * \param pos the position of the marble on the board.
     * \param parent the parent of this widget.
     */
    explicit MarbleWidget(std::optional<Color> color, Position pos, QWidget *parent = nullptr);
    ~MarbleWidget();

    /*!
     * \brief getPosition gets the positons of the marble.
     * \return the position of the marble.
     */
    inline Position getPosition() const;

    /*!
     * \brief setDecalage sets the offset of the marble to reach an hexagon shape.
     */
    void setOffset() const;

    /*!
     * \brief setSelected selects or unselect a marble on the board, and loads the according QPixMap.
     * \param cptSelected the number of currently selected marbles.
     * \return 1 is the selection was succesful, 0 if the unselection was succesful and
     * -1 if the player was not able to select or unselect.
     */
    int setSelected(int cptSelected);

signals:
    /*!
     * \brief clicked the clicked signal of the marble widget.
     */
    void clicked();

protected:
    /*!
     * \brief mousePressEvent the mouse press event handler of the marble widget.
     * \param event the mouse event.
     */
    void mousePressEvent(QMouseEvent *event) override;

private:
    Ui::MarbleWidget *ui;

    /*!
     * \brief game_ the model class of the game.
     */
    std::optional<Color> color_;

    /*!
     * \brief pos_ the position of the marble widget on the board.
     */
    Position pos_;

    /*!
     * \brief selected_ the selected flag of the marble widget.
     */
    bool selected_;
};

Position MarbleWidget::getPosition() const
{
    return pos_;
}

#endif // MARBLEWIDGET_H
