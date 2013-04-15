/** A MainWindow class to hold the game board, menus, and text boxes of a sliding tile puzzle

	@author Trevor Reed
*/
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
#include <QPlainTextEdit>
#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QApplication>
#include <QToolBar>
#include <QRadioButton>
#include <QDockWidget>
#include <QErrorMessage>
#include <QListWidget>
#include <cmath>
#include <cstdlib>

#include "board.h"
#include "puzzle_heur.h"
#include "puzzle_solver.h"
#include "mylist.h"
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
		
		//Left dock widget components - Text boxes and buttons to start a new puzzle
		QDockWidget *inputs;
		InputWidget *inputWidget;
		
		//Central widget components
		GraphicsWindow *gameBoard;
		
		//Message for errors, etc.
		QErrorMessage *error;
		
		//Bottom dock widget components - Text box to display errors
		QDockWidget *outputs;
		QPlainTextEdit *textBox;
		
		//Right dock widget components - Text box to display A* results
		QDockWidget *cheater;
		QListWidget *cheatMoves;
		
		//Cheat implementation components
		QPushButton *cheatButton;
		Board *b;
		PuzzleHeuristic *heuristic;
		PuzzleSolver *solver;

	public slots:
		//Starts a new puzzle
		void pressStart();
		
		//Runs the A* algorithm
		void cheat();
		
		//Methods to change the color of the puzzle
		void trojansColor();
		void USAColor();
		void blackAndWhiteColor();
		void forestColor();
		void whiteAndBlackColor();
};

#endif
