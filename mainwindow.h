#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "tetrixboard.h"

#include <QWidget>

class QPushButton;

namespace Ui {
class MainWindow;
}

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

    ~MainWindow();

private:    
    TetrixBoard *board;

    QPushButton *startButton;
    QPushButton *quitButton;
    QPushButton *pauseButton;
};

#endif // MAINWINDOW_H
