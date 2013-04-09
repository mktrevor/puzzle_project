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
#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QApplication>
#include <QToolBar>
#include <QRadioButton>
#include <QDockWidget>

#include "inputwidget.h"
#include "graphicswindow.h"
#include "guitile.h"

class MainWindow : public QMainWindow {
    
public:
    explicit MainWindow();
    ~MainWindow();

    void show();
    
private:
		//Menu Bar components
    QMenuBar *mb;
    QMenu *file;
    QMenu *colorScheme;
    QAction *start;
    QAction *quit;
    
    //Tool bar components
    QToolBar *toolBar;
    QRadioButton *manhattan;
    QRadioButton *outOfPlace;
    
    //Left dock widget components
    QDockWidget *inputs;
    InputWidget *inputWidget;
    
    /*QVBoxLayout *inputLayout;
    QWidget *userInput;
    QFormLayout *textInput;
    QPushButton *startButton;
    QPushButton *quitButton;*/
    
    //QTimer *timer;
    //QPushButton *button;

public slots:
    void start();

};

#endif MAINWINDOW_H
