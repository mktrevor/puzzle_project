#include "guitile.h"
#include "graphicswindow.h"

/** Constructor for GUITile
	@param GraphicsWindow
	@param value
	@param x position
	@param y position
	@param width
	@param height
*/
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
	
	//Timer is connected to the move() method of the tile
	timer = new QTimer;
	timer->setInterval(1);
	connect(timer, SIGNAL(timeout()), this, SLOT(move()));
}

/** Deconstructor */
GUITile::~GUITile() {
	delete number;
	delete destination;
	delete timer;
}

/** Sets background color of tile
	@param color
*/
void GUITile::setColor(QColor color) {
	QBrush brush(color);
	this->setBrush(brush);
}

/** Sets text color of tile
	@param color
*/
void GUITile::setTextColor(QColor color) {
	QBrush brush(color);
	number->setBrush(brush);
}

/** Sets border color of tile
	@param color
*/
void GUITile::setBorderColor(QColor color) {
	QPen pen(color);
	this->setPen(pen);
}
	
/** Method to call moveTile function when tile is clicked */
void GUITile::mousePressEvent(QGraphicsSceneMouseEvent *e) {
	gw->moveTile(this);
}

/** Returns value */
int GUITile::getVal() {
	return value;
}

/** Sets x velocity */
void GUITile::setXVel(int x) {
	xVel = x;
}

/** Sets y velocity */
void GUITile::setYVel(int y) {
	yVel = y;
}

/** Moves the tile according to its x and y velocity until it reaches its destination */
void GUITile::move() {
	setPos(x() + xVel, y() + yVel);
	
	if(x() == destination->x() && y() == destination->y()) {
		timer->stop();
	}
}

/** Returns pointer to destination */
QPoint* GUITile::getDest() {
	return destination;
}

/** Returns pointer to timer */
QTimer* GUITile::getTimer() {
	return timer;
}
