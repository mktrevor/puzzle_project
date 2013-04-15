#include "graphicswindow.h"

using namespace std;

/** Constructor - creates a new GraphicsWindow with either 9 or 16 tiles 
	@param dimension of board (3 or 4)
*/
GraphicsWindow::GraphicsWindow(int dim) {
	winner = new QErrorMessage();
  scene = new QGraphicsScene();
  view = new QGraphicsView( scene );
  dimension = dim;
      
  //Create and recolor all of the tiles
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
  
  //Freeze board tiles and show that it is not mixed
  mixed = false;
  frozen = true;
}

/** Deconstructor - deletes the messageBox, tiles, scene and view */
GraphicsWindow::~GraphicsWindow() {
	delete winner;
	for(int i = 0; i < dimension * dimension; i++) {
		delete tiles[i];
	}
	delete scene;
	delete view;
}

/** Displays the GraphicsWindow */
void GraphicsWindow::show() {
	view->show();
}

/** Returns pointer to a tile 
	@param location of tile
	@return pointer to tile
*/
GUITile* GraphicsWindow::tileAt(int loc) {
	return tiles[loc];
}

/** Returns board dimension
	@return dimension of board
*/
int GraphicsWindow::getDim() {
	return dimension;
}

/** Returns pointer to the view 
	@return pointer to view
*/
QGraphicsView* GraphicsWindow::getView() {
	return view;
}

/** Tries to move a tile and returns whether or not it was successful
	@param tile to be moved
	@return successful or not
*/
bool GraphicsWindow::moveTile(GUITile* tile) {
	//If board is frozen, no moves are allowed
	if(frozen) {
		winner->showMessage("Please start a new game");
		return 0;
	}

	//Initial positions of blankTile and tile to be moved
	int x = tile->x();
	int y = tile->y();
	int blankX = blankTile->x();
	int blankY = blankTile->y();
	
	int xDif = blankX - x;
	int yDif = blankY - y;
	
	//Checks to see if tile is adjacent to blankTile
	if((xDif == 100 && yDif == 0) || (xDif == -100 && yDif == 0) || (xDif == 0 && yDif == 100) || (xDif == 0 && yDif == -100)) {
		if(!mixed) {
			blankTile->setPos(x, y);
			tile->setPos(blankX, blankY);
		} else {
			tile->getDest()->setX(blankX);
			tile->getDest()->setY(blankY);
			tile->setXVel(xDif/100);
			tile->setYVel(yDif/100);
			tile->getTimer()->start();
			blankTile->setPos(x, y);
			
			//If the puzzle is solved, display a message
			if(solved(tile)) {
				winner->showMessage("YOU WIN! Please start a new game or press quit and return to reality.");
				mixed = false;
				frozen = true;
			}
		}
		return 1;
	}	
	
	//Return 0 if move was unsuccessful
	return 0;
}

/** Sets the mixed variable
	@param mixed or not
*/
void GraphicsWindow::setMixed(bool x) {
	mixed = x;
}

/** Sets the frozen variable
	@param frozen or not
*/
void GraphicsWindow::setFrozen(bool x) {
	frozen = x;
}

/** Recolors all of the tiles in the board
	@param 4 colors
*/
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

/** Checks if the board is solved or not. If the last tile is still moving, it will still return true
	@param tile currently moving
	@return solved or not
*/
bool GraphicsWindow::solved(GUITile *tile) {
	int index = 0;
	for(int i = 0; i < dimension; i++) {
  	for(int j = 0; j < dimension; j++) {
  		if(tiles[index] != tile && (tiles[index]->x() != 100 * j || tiles[index]->y() != 100 * i)) {
  			return 0;
  		}
  		index++;
  	}
  }
  return 1;
}

/** Checks if the board is solved or not
	@return solved or not
*/
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
