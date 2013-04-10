#ifndef INPUTWIDGET_H
#define INPUTWIDGET_H

#include <QWidget>
#include <QFormLayout>
#include <QLineEdit>
#include <QIntValidator>
#include <QPushButton>

class InputWidget : public QWidget {
	Q_OBJECT

	private:
    QFormLayout *inputLayout;
    QIntValidator *numbersOnly;
    QLineEdit *puzzleSize;
    QLineEdit *seedNumber;
    QLineEdit *initialMoves;
    QPushButton *startButton;
    QPushButton *quitButton;
   
  public:
		InputWidget();
		~InputWidget();
		QLineEdit* getSize();
		QLineEdit* getSeed();
		QLineEdit* getInitMoves();
		QPushButton* getStartButton();
		QPushButton* getQuitButton();
};

#endif
