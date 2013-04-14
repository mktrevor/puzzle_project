#ifndef GRAPHICSWINDOW_H
#define GRAPHICSWINDOW_H

#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
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
    
    bool solved(GUITile *tile);
    bool solved();
    
    void setMixed(bool x);
    void setFrozen(bool x);
    
private:
    GUITile *tiles[16];
    
    GUITile *blankTile;
    
    int dimension;
    
    bool mixed;
    bool frozen;
    
    QErrorMessage *winner;
    
    QGraphicsScene *scene;
    QGraphicsView *view;
};

#endif
