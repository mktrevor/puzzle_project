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
#include <QErrorMessage>
#include <cmath>
#include <cstdlib>

#include "inputwidget.h"
#include "graphicswindow.h"
#include "guitile.h"

class MainWindow : public QMainWindow {
	Q_OBJECT
  
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
		QAction *trojans;
		QAction *USA;
		QAction *blackAndWhite;
		QAction *forest;
		QAction *whiteAndBlack;
		
		//Tool bar components
		QToolBar *toolBar;
		QRadioButton *manhattan;
		QRadioButton *outOfPlace;
		
		//Left dock widget components
		QDockWidget *inputs;
		InputWidget *inputWidget;
		
		//Central widget components
		GraphicsWindow *gameBoard;
		
		
		QErrorMessage *error;
		//QTimer *timer;
		//QPushButton *button;

	public slots:
		void pressStart();
		
		void trojansColor();
		void USAColor();
		void blackAndWhiteColor();
		void forestColor();
		void whiteAndBlackColor();
};

#endif
