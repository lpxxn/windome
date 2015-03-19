#include "tetrixboard.h"

#include <QPainter>
#include <QRect>
#include <QDebug>


TetrixBoard::TetrixBoard(QWidget *parent)
{
    QPalette p(this->palette());
    p.setColor(QPalette::Window, Qt::gray);
    this->setAutoFillBackground(true);
    this->setPalette(p);


}

TetrixBoard::~TetrixBoard()
{

}

QSize TetrixBoard::sizeHint() const
{
    return QSize(BoardWidth * 15 + frameWidth() * 2,
                 BoardHeight * 15 + frameWidth() * 2);
}

QSize TetrixBoard::minimumSizeHint() const
{
    return QSize(BoardWidth * 5 + frameWidth() * 2,
                 BoardHeight * 5 + frameWidth() * 2);
}

void TetrixBoard::drawSquare(QPainter &painter, int x, int y, QColor color)
{
    painter.fillRect(x + 1, y + 1, squareWidth() - 2, squareHeight() - 2,
                     color);

    ///
    //painter.setPen(color.light());
    painter.setPen(Qt::green);
    painter.drawLine(x, y + squareHeight() - 1, x, y);
    painter.drawLine(x, y, x + squareWidth() - 1, y);

    //painter.setPen(color.dark());
    painter.setPen(Qt::blue);
    painter.drawLine(x + 1, y + squareHeight() - 1,
                     x + squareWidth() - 1,
                     y + squareHeight() - 1);

    painter.drawLine( x + squareWidth() - 1, y + squareHeight() - 1,
                      x + squareWidth() - 1, y + 1);
}

int paintInt = 0;
void TetrixBoard::paintEvent(QPaintEvent *event)
{
    qDebug() << " enter Paint count : " << ++paintInt;

    QFrame::paintEvent(event);

    QPainter painter(this);
    QRect rect = contentsRect();
    int boardTop = rect.bottom() - BoardHeight*squareHeight();

    //    int j = 0;
    //    int i = 21;
    int j = 2;
    int i = 19;
    int x = rect.left() + j * squareHeight();
    int y = boardTop + i * squareHeight();

    static const QRgb colorTable[8] = {
        0x000000, 0xCC6666, 0x66CC66, 0x6666CC,
        0xCCCC66, 0xCC66CC, 0x66CCCC, 0xDAAA00
    };



    QColor color = colorTable[int(1)];

//    painter.fillRect(x + 1, y + 1, squareWidth() - 2, squareHeight() - 2,
//                     color);

//    ///
//    painter.setPen(Qt::blue);
//    painter.drawLine(x, y + squareHeight() - 1, x, y);
//    painter.drawLine(x, y, x + squareWidth() - 1, y);

//    painter.drawLine(x + 1, y + squareHeight() - 1,
//                     x + squareWidth() - 1,
//                     y + squareHeight() - 1);

//    painter.drawLine( x + squareWidth() - 1, y + squareHeight() - 1,
//                      x + squareWidth() - 1, y + 1);

    int coordsTable[4][2] = {{ 0, -1 },  { 0, 0 },   { -1, 0 },  { -1, 1 }};
    int curX = 4;
    int curY = 19;
    for (int i = 0; i < 1; i++) {
        int x = curX + coordsTable[i][0]; // x
        int y = curY - coordsTable[i][1]; // y

        qDebug() << "rect.left  : " <<rect.left() << "  x  :" << x << "  squareWidth  :" << squareWidth()
                 << "  rect.left() + x * squareWidth()  :" << rect.left() + x * squareWidth();
        drawSquare(painter, rect.left() + x * squareWidth(), boardTop + (BoardHeight - y -1) * squareHeight(), color);
    }
}
