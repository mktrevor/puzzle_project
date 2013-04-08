#include "mainwindow.h"

MainWindow::MainWindow() {

    scene = new QGraphicsScene();
    view = new QGraphicsView( scene );
    
    userInput = new QWidget(view);
    inputLayout = new QVBoxLayout(userInput);
    textInput = new QFormLayout();
    
    line1 = new QLineEdit("Size (9 or 16):");
    line1->setReadOnly(true);
    line2 = new QLineEdit("Seed Number:");
    line2->setReadOnly(true);
    line3 = new QLineEdit("Initial Moves:");
    line3->setReadOnly(true);
    puzzleSize = new QLineEdit();
    seedNumber = new QLineEdit();
    initialMoves = new QLineEdit();
    startButton = new QPushButton("Start");
    quitButton = new QPushButton("Quit");
    
    textInput->addRow(line1, puzzleSize);
    textInput->addRow(line2, seedNumber);
    textInput->addRow(line3, initialMoves);
    
    inputLayout->addLayout(textInput);
    inputLayout->addWidget(startButton);
    inputLayout->addWidget(quitButton);
    
    //userInput->setLayout(inputLayout);
}

MainWindow::~MainWindow() {
	delete line1;
	delete line2;
	delete line3;
	delete puzzleSize;
	delete seedNumber;
	delete initialMoves;
	delete textInput;
	delete startButton;
	delete quitButton;
	delete inputLayout;
	delete userInput;
	delete scene;
	delete view;
}

void MainWindow::show() {
	view->show();
}
