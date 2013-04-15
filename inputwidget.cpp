#include "inputwidget.h"

/** Constructor - creates a new widget with input text boxes and buttons */
InputWidget::InputWidget() {
	numbersOnly = new QIntValidator();
  puzzleSize = new QLineEdit();
  puzzleSize->setValidator(numbersOnly);
  seedNumber = new QLineEdit();
  seedNumber->setValidator(numbersOnly);
  initialMoves = new QLineEdit();
  initialMoves->setValidator(numbersOnly);
  
  startButton = new QPushButton("Start Game");
  quitButton = new QPushButton("Quit");
  
  inputLayout = new QFormLayout();
  inputLayout->addRow("Size (9 or 16)", puzzleSize);
  inputLayout->addRow("Initial Moves", initialMoves);
  inputLayout->addRow("Seed Number", seedNumber);
  inputLayout->addRow(startButton, quitButton);

	setLayout(inputLayout);
}

/** Deconstructor */
InputWidget::~InputWidget() {
	delete numbersOnly;
	delete puzzleSize;
	delete seedNumber;
	delete initialMoves;
	delete startButton;
	delete quitButton;
	delete inputLayout;
}

/** Returns pointer to the puzzle size text box */
QLineEdit* InputWidget::getSize() {
	return puzzleSize;
}

/** Returns pointer to the seed number text box */
QLineEdit* InputWidget::getSeed() {
	return seedNumber;
}
		
/** Returns pointer to the initial moves text box */
QLineEdit* InputWidget::getInitMoves() {
	return initialMoves;
}

/** Returns pointer to the start button */
QPushButton* InputWidget::getStartButton() {
	return startButton;
}

/** Returns pointer to the quit button */
QPushButton* InputWidget::getQuitButton() {
	return quitButton;
}
