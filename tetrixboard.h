#ifndef TETRIXBOARD_H
#define TETRIXBOARD_H

#include <QObject>
#include <QFrame>
#include <QWidget>
#include <QPainter>


class TetrixBoard : public QFrame
{
    Q_OBJECT

public:
    TetrixBoard(QWidget *parent = 0);
    ~TetrixBoard();

    QSize sizeHint() const Q_DECL_OVERRIDE;
    QSize minimumSizeHint() const Q_DECL_OVERRIDE;

    // QWidget interface
    void drawSquare(QPainter &painter, int x, int y, QColor color);
    void paintEvent(QPaintEvent *event);

private:
    int squareWidth() { int w = contentsRect().width();
                        return w / BoardWidth; }
    int squareHeight() { int h = contentsRect().height();
                         return h / BoardHeight; }

private:
    enum { BoardWidth = 11, BoardHeight = 22 };


};

#endif // TETRIXBOARD_H
