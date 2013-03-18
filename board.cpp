#include <iostream>
#include <iomanip>
#include <map>
#include <set>
#include <cmath>
#include <cstdlib>
#include "board.h"
using namespace std;


/** Init a board of given size and scramble it with numInitMoves 
 * by moving the space tile with a randomly chosen direction N, W, S, E
 * some of which may be invalid, in which case we skip that move 
 * 
 *  @param size Number of tiles for the game.  \
 *      Should be a perfect square (4, 16, 25)
 *  @param numInitMoves Number of tile moves to attempt to scramble the board
 *  @param seed Use to seed the random number generator (srand) 
 */
Board::Board(int size, int numInitMoves, int seed )
{
  size_ = size;
  tiles_ = new int[size_];
  int dim = static_cast<int>(sqrt(size_));
  srand(seed);
  for(int i=0; i < size_; i++){
    tiles_[i] = i;
  }
  int blankLoc = 0;
  for(int i=0; i < numInitMoves; i++){
    int r = rand()%4;
    int randNeighbor = -1;
    if(r == 0){
      int n = blankLoc - dim;
      if(n >= 0){
	randNeighbor = n;
      }
    }
    else if(r == 1){
      int w = blankLoc - 1;
      if(blankLoc % dim != 0){
	randNeighbor = w;
      }
    }
    else if(r == 2){
      int s = blankLoc + dim;
      if(s  < size_){
	randNeighbor = s;
      }
    }
    else {
      int e = blankLoc + 1;
      if(blankLoc % dim != dim-1){
	randNeighbor = e;
      }
    }
    if(randNeighbor > -1){
      tiles_[blankLoc] = tiles_[randNeighbor];
      tiles_[randNeighbor] = 0;
      blankLoc = randNeighbor;
    }
  }
}


/** Default constructor. provide documentation here */
Board::Board()
{
  size_ = 4;
  tiles_ = new int[4];
  
  tiles_[0] = 1;
  tiles_[1] = 0;
  tiles_[2] = 2;
  tiles_[3] = 3;
}

/** Default destructor. provide documentation here */
Board::~Board()
{
  
	delete [] tiles_;

}

/** Copy constructor */
Board::Board(const Board &b)
{
	size_ = b.size_;
	tiles_ = new int[size_];
	for(int i = 0; i < size_; i++) {
		tiles_[i] = b.tiles_[i];
	}
}

/** Another kind of "copy" constructor */
Board::Board(int *tiles, int size) 
{
	 size_ = size;
	 tiles_ = new int[4];
	 for(int i = 0; i < size_; i++) {
	 	tiles_[i] = tiles[i];
	 }
}

bool Board::operator<(const Board& rhs) const
{
  if(size_ < rhs.size_){
    return true;
  }
  bool val = false;
  for(int i=0; i < size_; i++){
    if(tiles_[i] < rhs.tiles_[i]){
       //val = true;
       //break;
       return true;
     }
     else if(tiles_[i] > rhs.tiles_[i]){
       //break;
       return false;
     }
  }
  return val;
}

bool Board::operator==(const Board& rhs) const
{
	for(int i = 0; i < size_; i++) {
		if(tiles_[i] != rhs.tiles_[i]) {
			return 0;
		}
	}
	return 1;
}

bool Board::operator!=(const Board& rhs) const
{
	return !(*this == rhs);
}
		

/** Swaps the blank with the specified tile */
void Board::move(int tile) {
	for(int i = 0; i < size_; i++) {
		if(tiles_[i] == tile) {
			for(int j = 0; j < size_; j++) {
				if(tiles_[j] == 0) {
					tiles_[j] = tiles_[i];
					tiles_[i] = 0;
					break;
				}
			}
			break;
		}
	}
}
		

/** Generate potential moves and returns new boards
 * Key=tile, Value=Ptr to corresponding Board */
map<int, Board*> Board::potentialMoves() {
	map<int, Board*> moves;
	int dim = static_cast<int>(sqrt(size_)); // Dimension of board
	int blankLoc; // Location of the blank tile
	
	for(int i = 0; i < size_; i++) { // This loop finds the blank tile and stores its location
		if(tiles_[i] == 0) {
			blankLoc = i;
			break;
		}
	}
	
	if(blankLoc % dim != 0) {
		Board* newBoard1 = new Board(*this);
		newBoard1->move(tiles_[blankLoc-1]);
		moves[this->tiles_[blankLoc-1]] = newBoard1;
	}
	
	if(blankLoc % dim != (dim - 1)) {
		Board* newBoard2 = new Board(*this);
		newBoard2->move(tiles_[blankLoc+1]);
		moves[this->tiles_[blankLoc+1]] = newBoard2;
	}
	
	if(blankLoc >= dim) {
		Board* newBoard3 = new Board(*this);
		newBoard3->move(tiles_[blankLoc-dim]);
		moves[this->tiles_[blankLoc-dim]] = newBoard3;
	}
	if(blankLoc < (dim * (dim - 1))) {
		Board* newBoard4 = new Board(*this);
		newBoard4->move(tiles_[blankLoc+dim]);
		moves[this->tiles_[blankLoc+dim]] = newBoard4;
	}
	return moves;
}

/** Returns true if the board is solved, false otherwise */
bool Board::solved() {
	for(int i = 0; i < size_; i++) {
		if(tiles_[i] != i) {
			return 0;
		}
	}
	return 1;
}

int* Board::getTiles() {
	return tiles_;
}

int Board::getSize() {
	return size_;
}

std::ostream& operator<<(std::ostream &os, const Board &b) {
	int dim = static_cast<int>(sqrt(b.size_)); // Dimension of board

	for(int i = 0; i < b.size_; i++) {
		if(b.tiles_[i] != 0) {
			os << setw(2) << b.tiles_[i];
		} 
		else { cout << setw(2) << " "; }
		
		if((i + 1) % dim == 0) {
			os << endl;
		}
	}
	return os;
}
