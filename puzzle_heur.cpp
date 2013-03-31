#include "puzzle_heur.h"
#include <cmath>

/** Computes the total distance of all tiles in a puzzle board from their correct positions
	@param Pointer to the board's tiles
	@param Size of board
	@return Total distance
*/
int ManhattanHeuristic::compute(int *tiles, int size) {
	// Total distance of incorrect tiles from correct position
	int totalDist = 0; 
	// X and Y distance of an individual incorrect tile from correct position
	int xDist = 0, yDist = 0;
	// Dimension of board
	int dim = static_cast<int>(sqrt(size)); // Dimension of board
	
	for(int i = 0; i < size; i++) {
		if(tiles[i] != i && tiles[i] != 0) {
			xDist = std::abs(i%dim - (tiles[i])%dim);
			yDist = std::abs(i/dim - (tiles[i])/dim);
			
			//Adds the X and Y distance of a tile from its correct position to the total distance
			totalDist = totalDist + xDist + yDist;
			
			xDist = 0;
			yDist = 0;
		}
	}
	
	//Returns the distance of all tiles from their correct positions
	return totalDist;
}

/** Counts the number of tiles that are in the incorrect position
	@param Pointer to the board's tiles
	@param Size of board
	@return Number of out of place tiles
*/
int OutOfPlaceHeuristic::compute(int *tiles, int size) {
	// Number of tiles that are out of place
	int badTiles = 0;
	
	for(int i = 0; i < size; i++) {
		if(tiles[i] != i && tiles[i] != 0) {
			badTiles++;
		}
	}
	
	return badTiles;
}
