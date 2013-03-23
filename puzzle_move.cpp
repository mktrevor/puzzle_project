#include "puzzle_move.h"

PuzzleMove::PuzzleMove(Board &b) {
	tileMove_ = 0;
	b_ = &b;
	g_ = 0;
	h_ = 0;
	prev_ = NULL;
}

PuzzleMove::PuzzleMove(int tile, Board *b, PuzzleMove *parent) {
	tileMove_ = tile;
	b_ = b;
	g_ = parent->g_ + 1;
	// h_ will be set later by PuzzleHeuristic object
	h_ = 0
	prev_ = parent;
}

PuzzleMove::~PuzzleMove() {
	delete b_;
	delete prev_;
}

// Compare to PuzzleMoves based on f distance (needed for priority queue)
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
bool PuzzleMove::operator==(const PuzzleMove& p) const
{
	return ((g_ + h_) == (p.g_ + p.h_) && (g_ == p.g_));
}
