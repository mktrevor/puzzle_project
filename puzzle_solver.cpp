#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include "puzzle_solver.h"
#include "pmminlist.h"

using namespace std;

/** Constructor
	@param A puzzle board
*/
PuzzleSolver::PuzzleSolver(const Board &b) {
	b_ = b;
	expansions_ = 0;
}

/** Destructor */
PuzzleSolver::~PuzzleSolver() { }

/** A method to find the optimal solution for a puzzle board.
	@pre Board is unsolved
	@post List of moves which will solve the puzzle the fastest is printed out
	@param Pointer to a certain puzzle heuristic
	@return Minimum number of moves required to solve the puzzle
*/
int PuzzleSolver::run(PuzzleHeuristic *ph) {

	//Initialization of lists to hold moves and moves themselves
	PMMinList openList;
	BoardSet closedList;
	vector<PuzzleMove*> garbageList;
	PuzzleMove *myMove;
	PuzzleMove *potentialMove;
	map<int, Board*> moves;
	map<int, Board*>::iterator it;

	PuzzleMove *initialState = new PuzzleMove(b_);
	initialState->h_ = ph->compute(initialState->b_->getTiles(), initialState->b_->getSize());
	openList.push(initialState);
	closedList.insert(initialState->b_);

	//Implementation of A* search algorithm
	while(!openList.empty()) {

		myMove = openList.top();
		openList.pop();
		garbageList.push_back(myMove);	

		//If the puzzle is solved, print out the solution
		if(myMove->b_->solved()) {
			PuzzleMove *temp = myMove;
			while(temp->prev_ != NULL) {
				solution.push_back(temp->tileMove_);
				temp = temp->prev_;
			}

			cout << "Try this combination: ";
			for(int i = solution.size() - 1; i >= 0; i--) {
				cout << solution[i] << " ";
			}
			cout << endl;

			break;
		}

		moves = myMove->b_->potentialMoves();

		for(it = moves.begin(); it != moves.end(); ++it) {
			if(closedList.find(it->second) == closedList.end()) {
				potentialMove = new PuzzleMove(it->first, it->second, myMove);
				potentialMove->h_ = ph->compute(potentialMove->b_->getTiles(), potentialMove->b_->getSize());

				closedList.insert(potentialMove->b_);
				openList.push(potentialMove);
				expansions_++;
			}
			//If the board isn't needed, deallocate it
			else {delete it->second;}
		}
	}

	//Deallocating any puzzle moves left in the open list
	while(!openList.empty()) {
		delete openList.top();
		openList.pop();
	}

	//Deallocating any boards left in the closed list
	BoardSet::iterator it2;
	for(it2 = closedList.begin(); it2 != closedList.end(); ++it2) {
		if((*it2) != &b_) {
			delete (*it2);
		}
	}

	//Deallocating all of the puzzle moves in the garbage list
	for(unsigned int i = 0; i < garbageList.size(); i++) {
		delete garbageList[i];
	}

	return 0;
}

/** Returns the number of expansions that were searched to find the fastest solution */
int PuzzleSolver::getNumExpansions()
{
  return expansions_;
}
