#include "guitile.h"
#include "graphicswindow.h"

GUITile::GUITile(GraphicsWindow *g, int val, qreal xPos, qreal yPos, qreal w, qreal h) : QGraphicsRectItem(xPos, yPos, w, h) {
	gw = g;
	value = val;
	number = new QGraphicsSimpleTextItem();
	QString s = QString::number(val);
	number->setText(s);
}

GUITile::~GUITile() {
	delete number;
}

void GUITile::setTextColor(QColor color) {
	QBrush brush(color);
	number->setBrush(brush);
}

void GUITile::mousePressEvent(QGraphicsSceneMouseEvent *e) {
	//gw->moveTile(this);
}
