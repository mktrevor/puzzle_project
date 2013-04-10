#include "inputwidget.h"

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

InputWidget::~InputWidget() {
	delete numbersOnly;
	delete puzzleSize;
	delete seedNumber;
	delete initialMoves;
	delete startButton;
	delete quitButton;
	delete inputLayout;
}

QLineEdit* InputWidget::getSize() {
	return puzzleSize;
}

QLineEdit* InputWidget::getSeed() {
	return seedNumber;
}
		
QLineEdit* InputWidget::getInitMoves() {
	return initialMoves;
}

QPushButton* InputWidget::getStartButton() {
	return startButton;
}

QPushButton* InputWidget::getQuitButton() {
	return quitButton;
}
