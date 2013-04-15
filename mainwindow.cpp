#include "mainwindow.h"

/** Default constructor for MainWindow */
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
    cheatButton = new QPushButton("Cheat!");
    colorChoices = new QComboBox();
    colorLabel = new QLabel("Color Scheme: ");
    
    colorChoices->addItem("Black and White (default)");
    colorChoices->addItem("Cardinal and Gold");
    colorChoices->addItem("USA");
    colorChoices->addItem("White and Black");
    colorChoices->addItem("Forest");
    connect(colorChoices, SIGNAL(currentIndexChanged(int)), this, SLOT(colorChange(int)));
    
    toolBar->addWidget(manhattan);
    toolBar->addSeparator();
    toolBar->addWidget(outOfPlace);
    toolBar->addSeparator();
    toolBar->addWidget(cheatButton);
    toolBar->addSeparator();
    toolBar->addWidget(colorLabel);
    toolBar->addWidget(colorChoices);
    addToolBar(toolBar);
    
    connect(cheatButton, SIGNAL(clicked()), this, SLOT(cheat()));
    
    //LEFT DOCK WIDGET
    inputs = new QDockWidget();
    inputWidget = new InputWidget();
    inputs->setWidget(inputWidget);
    addDockWidget(Qt::LeftDockWidgetArea, inputs);
    inputs->setMaximumSize(200, 500);
    inputs->setFeatures(0x00);
    
    connect(inputWidget->getQuitButton(), SIGNAL(clicked()), qApp, SLOT(quit()));
    connect(inputWidget->getStartButton(), SIGNAL(clicked()), this, SLOT(pressStart()));
    
    //BOTTOM DOCK WIDGET
    outputs = new QDockWidget();
    textBox = new QPlainTextEdit();
    textBox->setReadOnly(true);
    outputs->setWidget(textBox);
    addDockWidget(Qt::BottomDockWidgetArea, outputs);
    outputs->setMaximumSize(800, 80);
    outputs->setFeatures(0x00);
    
    //Right DOCK WIDGET
    cheater = new QDockWidget();
    cheatMoves = new QListWidget();
    cheater->setWidget(cheatMoves);
    addDockWidget(Qt::RightDockWidgetArea, cheater);
    cheater->setMaximumSize(200, 600);
    cheater->setFeatures(0x00);
    
    //GAME BOARD
    gameBoard = new GraphicsWindow(3);
		
		this->setMinimumSize(1000, 700);
}

/** Deconstructor - deallocates all memory from the MainWindow */
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
	delete cheatButton;
	delete colorChoices;
	delete colorLabel;
	delete toolBar;
	
	//Deallocation of left dock widget
	delete inputWidget;
	delete inputs;
	
	//Deallocation of bottom dock widget
	delete textBox;
	delete outputs;
	
	//Deallocation of right dock widget
	delete cheatMoves;
	delete cheater;
	
	//Deallocation of game board
	delete gameBoard;
}

/** Displays the MainWindow */
void MainWindow::show() {
	QMainWindow::show();
}

/** Creates a new board when the start button is pressed if all fields are properly filled */
void MainWindow::pressStart() {
	if(inputWidget->getSize()->text().isEmpty() || inputWidget->getSeed()->text().isEmpty() || inputWidget->getInitMoves()->text().isEmpty()) {
		error->showMessage("Please fill in the inputs before running.");
		textBox->clear();
		textBox->insertPlainText("ERROR: Please fill in the inputs before running.");
		return;
	}
	int size = inputWidget->getSize()->text().toInt();
	int seed = inputWidget->getSeed()->text().toInt();
	int initMoves = inputWidget->getInitMoves()->text().toInt();
	
	if(size != 9 && size != 16) {
		error->showMessage("Size must be 9 or 16.");
		textBox->clear();
		textBox->insertPlainText("ERROR: Size must be 9 or 16.");
		inputWidget->getSize()->clear();
		return;
	}
	
	if(seed < 1) {
		error->showMessage("Invalid seed number.");
		textBox->clear();
		textBox->insertPlainText("ERROR: Invalid seed number.");
		inputWidget->getSeed()->clear();
		return;
	}
	
	if(initMoves < 0) {
		error->showMessage("Invalid initial moves.");
		textBox->clear();
		textBox->insertPlainText("ERROR: Invalid initial moves.");
		inputWidget->getInitMoves()->clear();
		return;
	}
	
	//Clear out text boxes
	cheatMoves->clear();
	textBox->clear();
	
	//Delete old gameboard
	delete gameBoard;
	
	int rowSize = sqrt(size);
	gameBoard = new GraphicsWindow(rowSize);
	
	setCentralWidget(gameBoard->getView());	
	
	//Unfreeze the board so the tiles can be moved
	gameBoard->setFrozen(false);
		
	srand(seed);
	
	int moves = 0;
	
	//Scramble the board according to the user input
	while(moves < initMoves) {
		int num = rand() % size;
		if(gameBoard->moveTile(gameBoard->tileAt(num))) {
			moves++;
		}
	}
	gameBoard->setMixed(true);
}

/** Recolor the tiles */
void MainWindow::trojansColor() {
	gameBoard->recolor(Qt::red, Qt::yellow, Qt::yellow, Qt::yellow);
}

/** Recolor the tiles */
void MainWindow::USAColor() {
	gameBoard->recolor(Qt::white, Qt::red, Qt::blue, Qt::red);
}

/** Recolor the tiles */
void MainWindow::blackAndWhiteColor() {
	gameBoard->recolor(Qt::black, Qt::white, Qt::white, Qt::white);
}

/** Recolor the tiles */
void MainWindow::forestColor() {
	gameBoard->recolor(Qt::darkGreen, Qt::green, Qt::green, Qt::darkYellow);
}

/** Recolor the tiles */
void MainWindow::whiteAndBlackColor() {
	gameBoard->recolor(Qt::white, Qt::black, Qt::black, Qt::black);
}

/** Method to run the A* algorithm when the cheat button is pressed */
void MainWindow::cheat() {
	if(!manhattan->isChecked() && !outOfPlace->isChecked()) {
		error->showMessage("Please choose a heuristic before attempting to cheat.");
		textBox->clear();
		textBox->insertPlainText("ERROR: Please choose a heuristic before attempting to cheat.");
		return;
	}
	
	if(gameBoard->solved()) {
		error->showMessage("Please start a new game before attempting to cheat.");
		textBox->clear();
		textBox->insertPlainText("ERROR: Please start a new game before attempting to cheat.");
		return;
	}
	
	//Create an array to hold the tile values	
	int dimension = gameBoard->getDim();
	int currentSize = dimension * dimension;
	int currentTiles[currentSize];
	GUITile *tile;
	
	//Fill in the array with the tile values in their current positions
	for(int i = 0; i < dimension; i++) {
		for(int j = 0; j < dimension; j++) {
			for(int k = 0; k < currentSize; k++) {
				tile = gameBoard->tileAt(k);
				if(tile->x() == i * 100 && tile->y() == j * 100) {
					currentTiles[dimension * j + i] = tile->getVal();
					break;
				}
			}
		}
	}
	
	//Create a new board with the current tile positions
	b = new Board(currentTiles, currentSize);
	
	solver = new PuzzleSolver(*b);
	
	if(manhattan->isChecked()) {
		heuristic = new ManhattanHeuristic;
	}
	else {
		heuristic = new OutOfPlaceHeuristic;
	}
	
	solver->run(heuristic);
	
	//Print out the results of the A* algorithm
	textBox->clear();
	
	if(solver->getSolution()->size() == 0) {
		textBox->insertPlainText("Puzzle is already solved!");
	}
	else {
		cheatMoves->clear();
		for(int i = 0; i < solver->getSolution()->size(); i++) {	
			cheatMoves->insertItem(0, QString::number(solver->getSolution()->at(i)));
		}
		cheatMoves->insertItem(0, "Try these moves: ");
	}
	
	//Deallocate the board solving objects
	delete b;
	delete solver;
	delete heuristic;
}

void MainWindow::colorChange(int x) {
	switch(x) {
		case 0: blackAndWhiteColor();
		break;
		
		case 1: trojansColor();
		break;
		
		case 2: USAColor();
		break;
		
		case 3: whiteAndBlackColor();
		break;
		
		case 4: forestColor();
		break;
	}
}		
