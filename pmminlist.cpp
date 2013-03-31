#include "puzzle_move.h"
#include "pmminlist.h"

/**
 * Default Constructor
 */
PMMinList::PMMinList() : slist_()
{

}

/**
 * Destructor
 */
PMMinList::~PMMinList()
{

}

/**
 * Adds the value val to the internal list in sorted
 * order from smallest to largest (if 
 * @param val Value to add to the sorted PuzzleMove list
 * @return nothing
 */
void PMMinList::push(PuzzleMove* pm)
{  
	std::list<PuzzleMove*>::iterator it;
	
	//If the list is empty, simply insert the new move
	if(slist_.empty()) {
		slist_.push_back(pm);
		return;
	}
	
	//Otherwise, insert the move before the first move that is bigger than it, or at the end of the list if it's bigger than all other moves
	for(it = slist_.begin(); it != slist_.end(); ++it) {
		if(*(*it) > *pm) {
			break;
		}
	}
	
	slist_.insert(it, pm);	
}

/**
 * Removes the top (minimum) item
 * @return nothing
 */
void PMMinList::pop()
{
  slist_.pop_front();
}

/**
 * Returns the top (minimum) item
 * @return pointer to the minimum-scored PuzzleMove
 */
PuzzleMove* PMMinList::top()
{
  return slist_.front();
}

