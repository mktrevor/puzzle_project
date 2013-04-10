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
      
    //GAME BOARD
    gameBoard = new GraphicsWindow(3);
    setCentralWidget(gameBoard);

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
	}
}
