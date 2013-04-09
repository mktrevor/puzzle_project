#include "mainwindow.h"

MainWindow::MainWindow() {
		
		//MENU BAR
		mb = menuBar();
		file = new QMenu("File");
		colorScheme = new QMenu("Color Scheme");
    
    quit = new QAction("Quit", file);
    start = new QAction("Start", file);
    
    file->addAction(start);
    file->addAction(quit);
       
    connect(quit, SIGNAL(triggered()), qApp, SLOT(quit()));
    connect(start, SIGNAL(triggered()), this, SLOT(start()));
    
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
    
    //gameBoard = new GraphicsWindow();
    //setCentralWidget(gameBoard);
    
    
}

MainWindow::~MainWindow() {
	delete start;
	delete quit;
	delete file;
	delete colorScheme;
	delete mb;
	
	delete manhattan;
	delete outOfPlace;
	delete toolBar;
	//delete gameBoard;
}

void MainWindow::show() {
	QMainWindow::show();
}
