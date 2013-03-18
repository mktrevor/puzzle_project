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
  
  int size, initMoves, seed;

  size = atoi(argv[1]);
  initMoves = atoi(argv[2]);
  seed = atoi(argv[3]);

  Board b(size,initMoves,seed);

  //**** Implement the gameplay here
  int input;
    
  while(!b.solved()) {
    map<int, Board*> moves = b.potentialMoves();
  	map<int, Board*>::iterator it;
	  cout << b << endl;
  	cout << "Enter tile number to move or -1 for a cheat: ";
  	cin >> input;
  	
  	it = moves.find(input);
  	
  	if(it != moves.end()) {
			b.move(input);
	 		cout << endl;
	 	}
	 	else
	 		cout << "INVALID TILE" << endl << endl;
	}
		
	cout << b << endl;
	cout << "YOU WIN!" << endl;

  return 0;
}
