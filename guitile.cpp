#include "guitile.h"
#include "graphicswindow.h"

GUITile::GUITile(GraphicsWindow *g, int val, int xPos, int yPos, int w, int h) : QGraphicsRectItem(0, 0, w, h) {
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
	
	destination = new QPoint;
	
	timer = new QTimer;
	timer->setInterval(1);
	connect(timer, SIGNAL(timeout()), this, SLOT(move()));
}

GUITile::~GUITile() {
	delete number;
	delete destination;
	delete timer;
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

void GUITile::setXVel(int x) {
	xVel = x;
}

void GUITile::setYVel(int y) {
	yVel = y;
}

void GUITile::move() {
	setPos(x() + xVel, y() + yVel);
	
	if(x() == destination->x() && y() == destination->y()) {
		timer->stop();
	}
}

QPoint* GUITile::getDest() {
	return destination;
}

QTimer* GUITile::getTimer() {
	return timer;
}
