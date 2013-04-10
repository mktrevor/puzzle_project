#ifndef GRAPHICSWINDOW_H
#define GRAPHICSWINDOW_H

#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QTimer>
#include <QTimeLine>
#include <QGraphicsItemAnimation>
#include <QErrorMessage>

#include "guitile.h"

class GraphicsWindow : public QWidget {
    Q_OBJECT
    
public:
		bool started;
		bool movable;
		
    GraphicsWindow(int dim);
    ~GraphicsWindow();
    
    QGraphicsView* getView();

		bool moveTile(GUITile* tile);

    void show();
    
    GUITile* tileAt(int loc);
    
    void recolor(QColor color1, QColor color2, QColor color3, QColor color4);
    
    bool solved();
    
private:
    GUITile *tiles[16];
    
    GUITile *blankTile;
    
    int dimension;
    
    QErrorMessage *winner;
    
    QGraphicsScene *scene;
    QGraphicsView *view;

    
    //QTimer *timer;
    //QPushButton *button;

public slots:
    //void handleTimer();
    //void buttonPress();
};

#endif
