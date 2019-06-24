#include "Well.h"
#include "UserInterface.h"
#include <iostream>

Well::Well() {
	for (int i = 0; i < WELL_DEPTH; i++) {
		for (int j = 0; j < WELL_WIDE; j++) {
			if (j == 0 || j == WELL_WIDE - 1 || i == WELL_DEPTH - 1) // Put boundary of well into well's grid system 
				wellGrid[i][j] = '@'; 
			else 
			wellGrid[i][j] = ' ';
		}
	}

}
void Well::display(Screen& screen, int x, int y) {
	for (int i = x; i < WELL_DEPTH; i++) {
		for (int j = x; j < WELL_WIDE; j++) {
			screen.gotoXY(j, i);
			screen.printChar(wellGrid[i][j]); // Prints all contents of well to screen
		}
	}
}

void Well::updateWell(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) // Takes in the 4 coordinates of collided piece, turns them into $s in well grid 
{
	wellGrid[y1][x1] = '$'; 
	wellGrid[y2][x2] = '$'; 
	wellGrid[y3][x3] = '$'; 
	wellGrid[y4][x4] = '$'; 
}

void Well::updateWellVapor(Piece* vaporPiece)
{
	for (int i = vaporPiece->getyCoord()-2; i <= vaporPiece->getyCoord() + 2; i++) {
		for (int j = vaporPiece->getxCoord() + 1; j <= vaporPiece->getxCoord() + 2; j++) {
			if (!(wellGrid[i][j] == '@'))
				wellGrid[i][j] = ' '; 
		}
	}
}

void Well::updateWellFoam(Piece * foamPiece)
{
	wellGrid[foamPiece->getyCoord() + foamPiece->yCoord0()][foamPiece->getxCoord() + foamPiece->xCoord0()] = ' ';
	updateWellFoamHelp(foamPiece->getyCoord() + foamPiece->yCoord0(), foamPiece->getxCoord() + foamPiece->xCoord0(), foamPiece); 
}

bool Well::updateWellFoamHelp(int sr, int sc, Piece* foamPiece)
{
	// Base Case 1: Check if position in well is not already occupied 
	if (!(wellGrid[sr][sc] == ' '))
		return false; 
	// Base Case 2: Check if outside of well bounds
	if (sr < 0 || sc < 0)
		return false; 
	// Base Case 3: Check vertical bounds
	if ((sr < foamPiece->getyCoord() + foamPiece->yCoord0() - 2) || (sr > foamPiece->getyCoord() + foamPiece->yCoord0() + 2))
		return false; 
	// Base Case 4: Check horizontal bounds 
	if ((sc < foamPiece->getxCoord() + foamPiece->xCoord0() - 2) || (sc > foamPiece->getxCoord() + foamPiece->xCoord0() + 2))
		return false; 
	wellGrid[sr][sc] = '*';  // Fill piece with '*' char 

	// Check above 
	if (updateWellFoamHelp(sr - 1, sc, foamPiece))
		return true; 
	// Check to right
	if (updateWellFoamHelp(sr, sc + 1, foamPiece))
		return true; 
	// Check down 
	if (updateWellFoamHelp(sr + 1, sc, foamPiece))
		return true;
	// Check left 
	if (updateWellFoamHelp(sr, sc - 1, foamPiece))
		return true; 
	
	return false; 

}

void Well::vaporizeRowHelp(int row)
// Vaporizes rows by deleting the row and shifting all those above it down 1 row
{
	int col = 1;
	while (col < WELL_WIDE) {
		wellGrid[row][col] = ' '; 
	}
	for (row; row >= 0; row--) {
		for (col = 1; col < WELL_WIDE; col++) {
			wellGrid[row][col] = wellGrid[row - 1][col];
		}
	}
}



int Well::vaporizeRows()
// Identifies which rows need to be vaporized for the helper function
{
	int numRowsGone = 0; 
	int count = 0; 
	for (int i = 0; i < WELL_DEPTH; i++) {
		for (int j = 0; j < WELL_WIDE; j++) {
			if (wellGrid[i][j] == '$' || wellGrid[i][j] == '*') {
				count++; 
			}
		}
		if (count == WELL_WIDE - 2) {
			vaporizeRowHelp(i); // Call helper function to vaporize row 
			numRowsGone++; 
		}
		count = 0;
	}
	return numRowsGone; 
}

int Well::topRow() const // Checks to make sure no fallen pieces exceed well height 
// Does this by scanning for first '$' char it finds in well grid 
{
	for (int i = 0; i < WELL_DEPTH; i++) {
		for (int j = 0; j < WELL_WIDE; j++) {
			if (wellGrid[i][j] == '$')
				return i; 
		}
	}
	return WELL_DEPTH; 
}

char Well::getCell(int x, int y) const
{
	return wellGrid[y][x]; 
}

bool Well::isTaken(int x, int y) const
{
	char cell = getCell(x, y); 
	if (cell == '$' || cell == '@' || cell == '*')
		return true;
	else
		return false; 
}

void Well::clearGrid() // Utilize same process as construction to prepare new well for next level
{
	for (int i = 0; i < WELL_DEPTH; i++) {
		for (int j = 0; j < WELL_WIDE; j++) {
			if (j == 0 || j == WELL_WIDE - 1 || i == WELL_DEPTH - 1) // Put boundary of well into well's grid system 
				wellGrid[i][j] = '@';
			else
				wellGrid[i][j] = ' ';
		}
	}
}
