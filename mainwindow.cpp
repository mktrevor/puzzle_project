#include "mainwindow.h"

MainWindow::MainWindow() {

		error = new QErrorMessage;
		
		//MENU BAR
		mb = menuBar();
		file = new QMenu("File");
		colorScheme = new QMenu("Color Scheme");
    
    quit = new QAction("Quit", file);
    start = new QAction("Start", file);
    
    file->addAction(start);
    file->addAction(quit);
       
    connect(quit, SIGNAL(triggered()), qApp, SLOT(quit()));
    connect(start, SIGNAL(triggered()), this, SLOT(pressStart()));
    
    trojans = new QAction("Cardinal and Gold", colorScheme);
    USA = new QAction("AMERICA", colorScheme);
    blackAndWhite = new QAction("Black and White", colorScheme);
    forest = new QAction("Forest", colorScheme);
    
    colorScheme->addAction(trojans);
    colorScheme->addAction(USA);
    colorScheme->addAction(blackAndWhite);
    colorScheme->addAction(forest);
    
    connect(trojans, SIGNAL(triggered()), this, SLOT(trojansColor()));
    connect(USA, SIGNAL(triggered()), this, SLOT(USAColor()));
    connect(blackAndWhite, SIGNAL(triggered()), this, SLOT(blackAndWhiteColor()));
    connect(forest, SIGNAL(triggered()), this, SLOT(forestColor()));
    
    mb->addMenu(file);
    mb->addSeparator();
    mb->addMenu(colorScheme);
    
    //TOOL BAR
    toolBar = new QToolBar();
    manhattan = new QRadioButton("Manhattan Heuristic");
    outOfPlace = new QRadioButton("Out of Place Heuristic");
    toolBar->addWidget(manhattan);
    toolBar->addWidget(outOfPlace);
    addToolBar(toolBar);
    
    //LEFT DOCK WIDGET
    inputs = new QDockWidget();
    inputWidget = new InputWidget();
    inputs->setWidget(inputWidget);
    addDockWidget(Qt::LeftDockWidgetArea, inputs);
    inputs->setMaximumSize(200, 500);
      
    //GAME BOARD
    gameBoard = new GraphicsWindow(4);
    setCentralWidget(gameBoard->getView());
		
		this->setMinimumSize(800, 500);
}

MainWindow::~MainWindow() {
	delete error;

	//Deallocation of menu bar
	delete start;
	delete quit;
	delete file;
	delete colorScheme;
	delete mb;
	
	//Deallocation of tool bar
	delete manhattan;
	delete outOfPlace;
	delete toolBar;
	
	//Deallocation of left dock widget
	delete inputWidget;
	delete inputs;
	
	//Deallocation of game board
	delete gameBoard;
}

void MainWindow::show() {
	QMainWindow::show();
}

void MainWindow::pressStart() {
	if(inputWidget->getSize()->text().isEmpty() || inputWidget->getSeed()->text().isEmpty() || inputWidget->getInitMoves()->text().isEmpty()) {
		error->showMessage("Please fill in the inputs before running.");
		return;
	}
	int size = inputWidget->getSize()->text().toInt();
	int seed = inputWidget->getSeed()->text().toInt();
	int moves = inputWidget->getInitMoves()->text().toInt();
	
	if(size != 9 && size != 16) {
		error->showMessage("Size must be 9 or 16.");
		inputWidget->getSize()->clear();
		return;
	}
	
	if(seed < 1) {
		error->showMessage("Invalid seed number.");
		inputWidget->getSeed()->clear();
		return;
	}
	
	if(moves < 0) {
		error->showMessage("Invalid initial moves.");
		inputWidget->getInitMoves()->clear();
		return;
	}
	
	delete gameBoard;
	
	int rowSize = sqrt(size);
	gameBoard = new GraphicsWindow(rowSize);
	setCentralWidget(gameBoard->getView());
}

void MainWindow::trojansColor() {
	gameBoard->recolor(Qt::red, Qt::yellow, Qt::yellow, Qt::yellow);
}

void MainWindow::USAColor() {
	gameBoard->recolor(Qt::white, Qt::red, Qt::blue, Qt::red);
}

void MainWindow::blackAndWhiteColor() {
	gameBoard->recolor(Qt::white, Qt::black, Qt::black, Qt::black);
}

void MainWindow::forestColor() {
	gameBoard->recolor(Qt::darkGreen, Qt::green, Qt::green, Qt::darkYellow);
}
