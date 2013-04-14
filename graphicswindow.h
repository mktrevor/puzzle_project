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
    GraphicsWindow(int dim);
    ~GraphicsWindow();
    
    QGraphicsView* getView();

		bool moveTile(GUITile* tile);

    void show();
    
    GUITile* tileAt(int loc);
    int getDim();
    
    void recolor(QColor color1, QColor color2, QColor color3, QColor color4);
    
    bool solved();
    
    void setMixed(bool x);
    
private:
    GUITile *tiles[16];
    
    GUITile *blankTile;
    
    int dimension;
    
    bool mixed;
    
    QErrorMessage *winner;
    
    QGraphicsScene *scene;
    QGraphicsView *view;

public slots:
    //void handleTimer();
    //void buttonPress();
};

#endif
