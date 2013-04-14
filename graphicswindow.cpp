#include "graphicswindow.h"

using namespace std;

GraphicsWindow::GraphicsWindow(int dim) {
	winner = new QErrorMessage();
  scene = new QGraphicsScene();
  //scene->setSceneRect(0, 0, 100 * dim, 100 * dim);
  view = new QGraphicsView( scene );
  dimension = dim;
      
  int nextValue = 0;
  for(int i = 0; i < dim; i++) {
  	for(int j = 0; j < dim; j++) {
  		tiles[nextValue] = new GUITile(this, nextValue, 100*j, 100*i, 100, 100);
  		if(nextValue != 0) {
  			tiles[nextValue]->setColor(Qt::black);
  			tiles[nextValue]->setTextColor(Qt::white);
  			tiles[nextValue]->setBorderColor(Qt::white);
  		}
  		scene->addItem(tiles[nextValue]);
  		nextValue++;
  	}
  }
  
  blankTile = tiles[0];
}

GraphicsWindow::~GraphicsWindow() {
	delete winner;
	for(int i = 0; i < dimension * dimension; i++) {
		delete tiles[i];
	}
	delete scene;
	delete view;
}

void GraphicsWindow::show() {
	view->show();
}

GUITile* GraphicsWindow::tileAt(int loc) {
	return tiles[loc];
}

int GraphicsWindow::getDim() {
	return dimension;
}

QGraphicsView* GraphicsWindow::getView() {
	return view;
}

bool GraphicsWindow::moveTile(GUITile* tile) {
	int x = tile->x();
	int y = tile->y();
	int blankX = blankTile->x();
	int blankY = blankTile->y();
	
	int xDif = x - blankX;
	int yDif = y - blankY;
	
	if((xDif == 100 && yDif == 0) || (xDif == -100 && yDif == 0) || (xDif == 0 && yDif == 100) || (xDif == 0 && yDif == -100)) {
		blankTile->setPos(x, y);
		tile->setPos(blankX, blankY);
		
		if(mixed && solved()) {
			winner->showMessage("YOU WIN! Please start a new game or press quit and return to reality.");
			mixed = false;
		}
		return 1;
	}	
	return 0;
}

void GraphicsWindow::setMixed(bool x) {
	mixed = x;
}

void GraphicsWindow::recolor(QColor color1, QColor color2, QColor color3, QColor color4) {
	for(int i = 1; i < dimension * dimension; i++) {
		if(i % 2 == 0) {
			tiles[i]->setTextColor(color2);
		} else {
			tiles[i]->setTextColor(color3);
		}
		tiles[i]->setColor(color1);
		tiles[i]->setBorderColor(color4);
	}
}

bool GraphicsWindow::solved() {
	int index = 0;
	for(int i = 0; i < dimension; i++) {
  	for(int j = 0; j < dimension; j++) {
  		if(tiles[index]->x() != 100 * j || tiles[index]->y() != 100 * i) {
  			return 0;
  		}
  		index++;
  	}
  }
  return 1;
}
