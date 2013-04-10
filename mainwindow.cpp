#include "mainwindow.h"

MainWindow::MainWindow() {
		error = new QErrorMessage;
		
		//MENU BAR
		mb = menuBar();
		file = new QMenu("File");
		colorScheme = new QMenu("Color Scheme");
    
    quit = new QAction("Quit", file);
    start = new QAction("Start Game", file);
    
    file->addAction(start);
    file->addAction(quit);
       
    connect(quit, SIGNAL(triggered()), qApp, SLOT(quit()));
    connect(start, SIGNAL(triggered()), this, SLOT(pressStart()));
    
    trojans = new QAction("Cardinal and Gold", colorScheme);
    USA = new QAction("AMERICA", colorScheme);
    blackAndWhite = new QAction("Black and White", colorScheme);
    forest = new QAction("Forest", colorScheme);
    whiteAndBlack = new QAction("White and Black", colorScheme);
    
    colorScheme->addAction(trojans);
    colorScheme->addAction(USA);
    colorScheme->addAction(forest);
    colorScheme->addAction(blackAndWhite);
    colorScheme->addAction(whiteAndBlack);
    
    connect(trojans, SIGNAL(triggered()), this, SLOT(trojansColor()));
    connect(USA, SIGNAL(triggered()), this, SLOT(USAColor()));
    connect(blackAndWhite, SIGNAL(triggered()), this, SLOT(blackAndWhiteColor()));
    connect(whiteAndBlack, SIGNAL(triggered()), this, SLOT(whiteAndBlackColor()));
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
    
    connect(inputWidget->getQuitButton(), SIGNAL(clicked()), qApp, SLOT(quit()));
    connect(inputWidget->getStartButton(), SIGNAL(clicked()), this, SLOT(pressStart()));
      
    //GAME BOARD
    gameBoard = new GraphicsWindow(3);
    setCentralWidget(gameBoard->getView());
		
		this->setMinimumSize(800, 500);
}

MainWindow::~MainWindow() {
	delete error;

	//Deallocation of menu bar
	delete start;
	delete quit;
	delete file;
	delete trojans;
	delete USA;
	delete blackAndWhite;
	delete forest;
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
	int initMoves = inputWidget->getInitMoves()->text().toInt();
	
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
	
	if(initMoves < 0) {
		error->showMessage("Invalid initial moves.");
		inputWidget->getInitMoves()->clear();
		return;
	}
	
	delete gameBoard;
	
	int rowSize = sqrt(size);
	gameBoard = new GraphicsWindow(rowSize);
	setCentralWidget(gameBoard->getView());	
		
	srand(seed);
	
	int moves = 0;
	
	gameBoard->movable = true;
	
	while(moves < initMoves) {
		int num = rand() % size;
		if(gameBoard->moveTile(gameBoard->tileAt(num))) {
			moves++;
		}
	}
		
	gameBoard->started = true;
}

void MainWindow::trojansColor() {
	gameBoard->recolor(Qt::red, Qt::yellow, Qt::yellow, Qt::yellow);
}

void MainWindow::USAColor() {
	gameBoard->recolor(Qt::white, Qt::red, Qt::blue, Qt::red);
}

void MainWindow::blackAndWhiteColor() {
	gameBoard->recolor(Qt::black, Qt::white, Qt::white, Qt::white);
}

void MainWindow::forestColor() {
	gameBoard->recolor(Qt::darkGreen, Qt::green, Qt::green, Qt::darkYellow);
}

void MainWindow::whiteAndBlackColor() {
	gameBoard->recolor(Qt::white, Qt::black, Qt::black, Qt::black);
}
