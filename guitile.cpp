#include "guitile.h"
#include "graphicswindow.h"

GUITile::GUITile(GraphicsWindow *g, int val, qreal xPos, qreal yPos, qreal w, qreal h) : QGraphicsRectItem(0, 0, w, h) {
	QFont font("Arial", 65);
	
	gw = g;
	value = val;
	QString s = QString::number(val);
	number = new QGraphicsSimpleTextItem(this);
	if(val != 0) {
		number->setText(s);
		number->setFont(font);
	}
	setPos(xPos, yPos);
}

GUITile::~GUITile() {
	delete number;
}

void GUITile::setColor(QColor color) {
	QBrush brush(color);
	this->setBrush(brush);
}

void GUITile::setTextColor(QColor color) {
	QBrush brush(color);
	number->setBrush(brush);
}

void GUITile::setBorderColor(QColor color) {
	QPen pen(color);
	this->setPen(pen);
}
	
void GUITile::mousePressEvent(QGraphicsSceneMouseEvent *e) {
	gw->moveTile(this);
}

int GUITile::getVal() {
	return value;
}
