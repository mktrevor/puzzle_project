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
    QIntValidator *numbersOnly;
    QLineEdit *puzzleSize;
    QLineEdit *seedNumber;
    QLineEdit *initialMoves;
   
  public:
		InputWidget();
		~InputWidget();
		QLineEdit* getSize();
		QLineEdit* getSeed();
		QLineEdit* getInitMoves();
};

#endif
