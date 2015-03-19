#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QRect>
#include <QGridLayout>
#include <QPushButton>
#include <QPalette>

MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent)
{


    QRect r1 = this->contentsRect();
    qDebug() << " r1  " << r1;
    board = new TetrixBoard;

//    QPalette p(board->palette());
//    p.setColor(QPalette::Window, Qt::blue);
//    board->setAutoFillBackground(true);
//    board->setPalette(p);

    startButton = new QPushButton(tr("&Start"));
    startButton->setFocusPolicy(Qt::NoFocus);
    quitButton = new QPushButton(tr("&Quit"));
    quitButton->setFocusPolicy(Qt::NoFocus);
    pauseButton = new QPushButton(tr("&Pause"));

    pauseButton->setFocusPolicy(Qt::NoFocus);

    QGridLayout *layout = new QGridLayout;
    layout->addWidget(startButton, 4, 0);
    layout->addWidget(board, 0, 1, 6, 1);
    layout->addWidget(quitButton, 4, 2);
    layout->addWidget(pauseButton, 5, 2);
    setLayout(layout);
    resize(550, 370);

}

MainWindow::~MainWindow()
{    
}
