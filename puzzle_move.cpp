#include "puzzle_move.h"

/** Constructor for initial PuzzleMove
	@param A puzzle board
*/
PuzzleMove::PuzzleMove(Board &b) {
	tileMove_ = 0;
	b_ = &b;
	g_ = 0;
	// h_ will be set later by PuzzleHeuristic object
	h_ = 0;
	prev_ = NULL;
}

/** Constructor for subsequent PuzzleMoves
	@param Tile which was moved
	@param Pointer to puzzle board
	@param Pointer to the parent PuzzleMove
*/
PuzzleMove::PuzzleMove(int tile, Board *b, PuzzleMove *parent) {
	tileMove_ = tile;
	b_ = b;
	g_ = parent->g_ + 1;
	// h_ will be set later by PuzzleHeuristic object
	h_ = 0;
	prev_ = parent;
}

/** Destructor */
PuzzleMove::~PuzzleMove() { }

// Compare to PuzzleMoves based on f distance (needed for priority queue)
/** < operator overloader to compare the f scores of two PuzzleMoves
*/
bool PuzzleMove::operator<(const PuzzleMove& p) const
{
  if((g_ + h_) < (p.g_ + p.h_)){
    return true;
  }
  else if((g_ + h_ == p.g_ + p.h_) && (g_ > p.g_)){
    return true;
  }
  else {
    return false;
  }
}

/** > operator overloader to compare the f scores of two PuzzleMoves
*/
bool PuzzleMove::operator>(const PuzzleMove& p) const
{
  if( (g_ + h_) > (p.g_ + p.h_) ){
    return true;
  }
  else if((g_ + h_ == p.g_ + p.h_) && (g_ < p.g_) ){
    return true;
  }
  else {
     return false;
  }
  
}

/** == operator overloader to compare the f scores of two PuzzleMoves
*/
bool PuzzleMove::operator==(const PuzzleMove& p) const
{
	return ((g_ + h_) == (p.g_ + p.h_) && (g_ == p.g_));
}
