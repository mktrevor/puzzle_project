/** A class to represent tiles in the sliding tile puzzle
	@author Trevor Reed
*/
#ifndef GUITILE_H
#define GUITILE_H

#include <QGraphicsRectItem>
#include <QGraphicsSimpleTextItem>
#include <QString>
#include <QTimer>

class GraphicsWindow;

class GUITile : public QObject, public QGraphicsRectItem {
	Q_OBJECT

	private:
		QGraphicsSimpleTextItem *number;
		GraphicsWindow *gw;
		int value;
		
		//A point of destination and a timer for the tile animation
		QPoint *destination;
		QTimer *timer;
		
		int xVel;
		int yVel;
		
	public:
		GUITile(GraphicsWindow *g, int val, int xPos, int yPos, int w, int h);
		~GUITile();
		
		void setColor(QColor color);
		void setTextColor(QColor color);
		void setBorderColor(QColor color);
		
		int getVal();
		
		QPoint* getDest();
		QTimer* getTimer();
		
		void setXVel(int x);
		void setYVel(int y);
	
	public slots:
		void mousePressEvent(QGraphicsSceneMouseEvent *e);
		void move();
};

#endif
