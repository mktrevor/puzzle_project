#ifndef GUITILE_H
#define GUITILE_H

#include <QGraphicsRectItem>
#include <QGraphicsSimpleTextItem>
#include <QString>

class GraphicsWindow;

class GUITile : public QGraphicsRectItem {
	private:
		QGraphicsSimpleTextItem *number;
		GraphicsWindow *gw;
		int value;
		
	public:
		GUITile(GraphicsWindow *g, int val, qreal xPos, qreal yPos, qreal w, qreal h);
		~GUITile();
		
		void setTextColor(QColor color);
	
	public slots:
		void mousePressEvent(QGraphicsSceneMouseEvent *e);
		
};

#endif
