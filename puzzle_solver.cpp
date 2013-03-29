#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include <vector>
#include "puzzle_solver.h"
#include "pmminlist.h"

using namespace std;

PuzzleSolver::PuzzleSolver(const Board &b) {
	b_ = b;
}

PuzzleSolver::~PuzzleSolver() { }

int PuzzleSolver::run(PuzzleHeuristic *ph) {

	PMMinList openList;
	BoardSet closedList;
	vector<PuzzleMove*> garbage;
	MyList<int> solution;
	
	PuzzleMove* firstMove = new PuzzleMove(b_);
	firstMove->h_ = ph->compute(firstMove->b_->getTiles(), firstMove->b_->getSize());
	openList.push(firstMove);
	closedList.insert(firstMove->b_);
	
	while(!openList.empty()) {
	
		PuzzleMove *myMove = openList.top();
		garbage.push_back(myMove);
		openList.pop();
		
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
			cout << endl << endl;
			
			break;
		}
		map<int, Board*> moves = myMove->b_->potentialMoves();
		map<int, Board*>::iterator it = moves.begin();
		
		for(it = moves.begin(); it != moves.end(); ++it) {
			
			if(closedList.find(it->second) == closedList.end()) {
				int tileMove = it->first;
			
				PuzzleMove *nextMove = new PuzzleMove(tileMove, it->second, myMove);
				nextMove->h_ = ph->compute(it->second->getTiles(), it->second->getSize());
				nextMove->prev_ = myMove;
				closedList.insert(nextMove->b_);
				openList.push(nextMove);
				expansions_++;
			}
		}
	}
	
	for(unsigned int i = 0; i < garbage.size(); i++) {
		delete garbage[i];
	}
	
	return solution.size();
}

int PuzzleSolver::getNumExpansions()
{
  return expansions_;
}
