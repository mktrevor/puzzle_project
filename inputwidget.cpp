#include "inputwidget.h"

InputWidget::InputWidget() {
	numbersOnly = new QIntValidator();
  puzzleSize = new QLineEdit();
  puzzleSize->setValidator(numbersOnly);
  seedNumber = new QLineEdit();
  seedNumber->setValidator(numbersOnly);
  initialMoves = new QLineEdit();
  initialMoves->setValidator(numbersOnly);
  
  inputLayout = new QFormLayout();
  inputLayout->addRow("Size (9 or 16)", puzzleSize);
  inputLayout->addRow("Initial Moves", initialMoves);
  inputLayout->addRow("Seed Number", seedNumber);

	setLayout(inputLayout);
}

InputWidget::~InputWidget() {
	delete numbersOnly;
	delete puzzleSize;
	delete seedNumber;
	delete initialMoves;
	delete inputLayout;
}
