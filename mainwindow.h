#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QTimer>
#include <QTimeLine>
#include <QGraphicsItemAnimation>
#include <QPushButton>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QFormLayout>

#include "guitile.h"

class MainWindow : public QWidget {
    Q_OBJECT
    
public:
    explicit MainWindow();
    ~MainWindow();

    void show();
    
private:
    QGraphicsScene *scene;
    QGraphicsView *view;
    QLineEdit *line1;
    QLineEdit *line2;
    QLineEdit *line3;
    QLineEdit *puzzleSize;
    QLineEdit *seedNumber;
    QLineEdit *initialMoves;
    QVBoxLayout *inputLayout;
    QWidget *userInput;
    QFormLayout *textInput;
    QPushButton *startButton;
    QPushButton *quitButton;
    //QTimer *timer;
    //QPushButton *button;

public slots:
    //void handleTimer();
    //void buttonPress();

};

#endif // MAINWINDOW_H
