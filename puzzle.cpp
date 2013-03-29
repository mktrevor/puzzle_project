#include <iostream>
#include <cstdlib>
#include <deque>
#include "board.h"
#include "puzzle_heur.h"
#include "puzzle_solver.h"

using namespace std;

int main(int argc, char *argv[])
{
	if(argc < 3){
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

  Board b(size,initMoves,seed);
  
  map<int, Board*> moves;
	map<int, Board*>::iterator it;

  //**** Implement the gameplay here
  int input;
  ManhattanHeuristic *mh = new ManhattanHeuristic;
    
  while(!b.solved()) {
  cout << "a" << endl << b << endl;
  	moves = b.potentialMoves();

	  cout << b << endl;
  	cout << "Enter tile number to move or -1 for a cheat: ";
  	cin >> input;
  	
  	if(cin.fail()) {
  		cin.clear();
  		cin.ignore(1000, '\n');
  		cout << "INVALID INPUT" << endl << endl;
  		continue;
  	}
  	cout << "b" << endl << b << endl;
  	
  	if(input < -1 || input == 0) {
  		cout << "INVALID INPUT" << endl << endl;
  		continue;
  	}
  	cout << "c" << endl << b << endl;
  	
  	if(input == -1) {
  	cout << "d" << endl << b << endl;
  		Board* tempBoard = new Board(b);
  		PuzzleSolver solver(*tempBoard);
  		cout << "f" << endl << b << endl;
  		solver.run(mh);
  		cout << "g" << endl << b << endl;
  		delete tempBoard;
  		continue;
  	}
  	
  	it = moves.find(input);
  	
  	if(it != moves.end()) {
			b.move(input);
	 		cout << endl;
	 	}
	 	else
	 		cout << "INVALID TILE" << endl << endl;
	 	
	 	
	 	cout << "i" << endl << b << endl;
	}
		
	cout << b << endl;
	cout << "YOU WIN!" << endl;
	
	delete mh;

  return 0;
}
