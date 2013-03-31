#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include "puzzle_solver.h"
#include "pmminlist.h"

using namespace std;

PuzzleSolver::PuzzleSolver(const Board &b) {
	b_ = b;
	expansions_ = 0;
}

PuzzleSolver::~PuzzleSolver() { }

int PuzzleSolver::run(PuzzleHeuristic *ph) {

	PMMinList openList;
	BoardSet closedList;
	vector<PuzzleMove*> garbageList;
	MyList<int> solution;
	PuzzleMove *myMove;
	PuzzleMove *potentialMove;
	map<int, Board*> moves;
	map<int, Board*>::iterator it;
	
	PuzzleMove *initialState = new PuzzleMove(b_);
	initialState->h_ = ph->compute(initialState->b_->getTiles(), initialState->b_->getSize());
	openList.push(initialState);
	closedList.insert(initialState->b_);
	
	
	while(!openList.empty()) {
	
		myMove = openList.top();
		openList.pop();
		garbageList.push_back(myMove);	
			
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
			else {delete it->second;}
		}
	}
	
	while(!openList.empty()) {
		delete openList.top();
		openList.pop();
	}
	

		
	for(unsigned int i = 0; i < garbageList.size(); i++) {
		delete garbageList[i];
	}
	
	return 0;
}

int PuzzleSolver::getNumExpansions()
{
  return expansions_;
}
