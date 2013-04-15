/** A QWidget to hold the puzzle tiles and handle their movement

	@author Trevor Reed
*/
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
    
    GUITile *blankTile; //Pointer to the blank tile
    
    int dimension;
    
    bool mixed; //Whether or not the board has been mixed up
    bool frozen; //Whether or not the board tiles are movable
    
    QErrorMessage *winner; //Message box to display a winning message
    
    QGraphicsScene *scene;
    QGraphicsView *view;
};

#endif
