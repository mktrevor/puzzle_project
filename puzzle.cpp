/** @mainpage CSCI 102 PA 3
	@section purpose Purpose/Overview
		This is a program which emulates a sliding tile puzzle. It must follow all of the logic behind a sliding tile puzzle. Also, it must be able to find a solution for
		a certain puzzle if the user chooses to "cheat".
	@section requirements Requirements
		This program requires multiples classes to store puzzle boards, puzzle moves, a priority queue, heuristic methods, and a puzzle solving class.
		It must be able to take user input as command line arguments to create a board, as well as input for moving the puzzle's tiles. Also, it must 
		find the optimal solution for the puzzle when the user requests it.
*/

#include <iostream>
#include <cstdlib>
#include <deque>
#include "board.h"
#include "puzzle_heur.h"
#include "puzzle_solver.h"

using namespace std;

int main(int argc, char *argv[])
{
	if(argc < 4){
  	cerr << "Usage: ./puzzle size initMoves seed" << endl;
  	return 1;
  }
  
  if(argc > 4) {
  	cerr << "Too many arguments. Please try again." << endl;
  	return 1;
  }
  
  int size, initMoves, seed;

  size = atoi(argv[1]);
  initMoves = atoi(argv[2]);
  seed = atoi(argv[3]);
  
	//Instantiating the puzzle board
  Board b(size,initMoves,seed);
  
  map<int, Board*> moves;
	map<int, Board*>::iterator it;

	//User input for the tile to be moved
  int input;
  
  //Manhattan Heuristic object for the puzzle solver
  ManhattanHeuristic *mh = new ManhattanHeuristic;
    
  while(!b.solved()) {

	  cout << b << endl;
  	cout << "Enter tile number to move or -1 for a cheat: ";
  	cin >> input;
  	
  	//Making sure the user input is valid
  	if(cin.fail()) {
  		cin.clear();
  		cin.ignore(1000, '\n');
  		cout << endl << "INVALID INPUT" << endl << endl;
  		continue;
  	}
  	
  	//If the user inputs -1, the puzzle solver runs on the current puzzle
  	if(input == -1) {
  		PuzzleSolver *solver = new PuzzleSolver(b);
  		cout << endl;
  		solver->run(mh);
  		cout << "(Expansions: " << solver->getNumExpansions() << ")" << endl << endl;
  		delete solver;
  		continue;
  	}
  	
  	//The user can only move tiles which are in the potentialMoves map for the current board
  	moves = b.potentialMoves();
  	it = moves.find(input);
  	
  	if(it != moves.end()) {
			b.move(input);
	 		cout << endl;
	 	}
	 	else {
	 		cout << endl << "INVALID TILE" << endl << endl;
		}
		
		//Deallocation of puzzle boards from the potentialMoves map
		for(it = moves.begin(); it != moves.end(); ++it) {
			delete it->second;
		}
	}
		
	//Once the puzzle board is solved, the user wins
	cout << b << endl;
	cout << "YOU WIN!" << endl;
	
	//Deallocation of the manhattan heuristic
	delete mh;

  return 0;
}
