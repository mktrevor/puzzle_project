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
		GUITile(GraphicsWindow *g, int val, int xPos, int yPos, int w, int h);
		~GUITile();
		
		void setColor(QColor color);
		void setTextColor(QColor color);
		void setBorderColor(QColor color);
		
		int getVal();
	
	public slots:
		void mousePressEvent(QGraphicsSceneMouseEvent *e);
		
};

#endif
