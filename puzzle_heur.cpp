#include "puzzle_heur.h"
#include <cmath>

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
			
			totalDist = totalDist + xDist + yDist;
			
			xDist = 0;
			yDist = 0;
		}
	}
	return totalDist;
}

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
