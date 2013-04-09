#ifndef INPUTWIDGET_H
#define INPUTWIDGET_H

#include <QWidget>
#include <QFormLayout>
#include <QLineEdit>
#include <QIntValidator>

class InputWidget : public QWidget {
	Q_OBJECT

	private:
    QFormLayout *inputLayout;
    QLineEdit *puzzleSize;
    QLineEdit *seedNumber;
    QLineEdit *initialMoves;
    QIntValidator *numbersOnly;
   
	public:
		InputWidget();
		~InputWidget();
};

#endif INPUTWIDGET_H
