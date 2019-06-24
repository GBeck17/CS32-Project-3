#ifndef WELL_INCLUDED
#define WELL_INCLUDED
#include "Piece.h"
#include <vector>

class Screen;
class Game;

const int WELL_DEPTH = 18; 
const int WELL_WIDE = 10; 

class Well
{
  public:
	Well(); 
	void display(Screen& screen, int x, int y);
	void updateWell(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4);  
	void updateWellVapor(Piece* vaporPiece); 
	void updateWellFoam(Piece* foamPiece);
	bool updateWellFoamHelp(int sr, int sc, Piece* foamPiece); 
	void vaporizeRowHelp(int row); 
	int vaporizeRows(); 
	int topRow() const;
	char getCell(int x, int y) const; 
	bool isTaken(int x, int y) const; 
	void clearGrid(); 
private: 
	char wellGrid[WELL_DEPTH][WELL_WIDE];  // grid setup for the well 
	
};

#endif // WELL_INCLUDED
