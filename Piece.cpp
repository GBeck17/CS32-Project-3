#include "Piece.h"
#include "Game.h"

Piece::Piece()
	: orientation(0), xCoord(16), yCoord(4) {
	
}

Piece::~Piece()
{

}

void Piece::moveDown()
{
	yCoord++;
}

void Piece::moveLeft() {
	xCoord--; 
}

void Piece::moveRight() {
	xCoord++; 
}

void Piece::rotate() {
	switch (orientation) {
	case 0: 
		setOrientation(1); 
		break; 
	case 1: 
		setOrientation(2); 
		break; 
	case 2: 
		setOrientation(3); 
		break; 
	case 3: 
		setOrientation(0);
		break; 
	default: 
		break; 
	}
}

void Piece::displayPiece(Screen & screen) const
{
	// Pure Virtual function, do nothing 
}

int Piece::getOrientation() const
{
	return orientation; 
}

void Piece::setOrientation(int n)
{
	orientation = n; 
}

int Piece::getxCoord() const
{
	return xCoord;
}

int Piece::getyCoord() const
{
	return yCoord;
}

void Piece::setxCoord(int n)
{
	xCoord = n; 
}

void Piece::setyCoord(int n)
{
	yCoord = n; 
}

PieceType Piece::getPieceType() const
{
	return type; 
}

void Piece::setPieceType(PieceType piece_type)
{
	type = piece_type; 
}

int Piece::xCoord0() const
{
	if (type == PIECE_I) {
		switch (orientation) {
		case 0:
			return 0; 
			break;
		case 1:
			return 1; 
			break;
		case 2:
			return 0; 
			break;
		case 3:
			return 1; 
			break;
		default:
			break;
		}
	}
	if (type == PIECE_L) {
		switch (orientation) {
		case 0:
			return 0; 
			break;
		case 1:
			return 1; 
			break;
		case 2:
			return 0; 
			break;
		case 3:
			return 1; 
			break;
		default:
			break;
		}
	}
	if (type == PIECE_J) {
		switch (orientation) {
		case 0:
		case 1: 
		case 2: 
		case 3: 
			return 1; 
			break; 
		default:
			break;
		}
	}
	if (type == PIECE_T) {
		switch (orientation) {
		case 0:
			return 0; 
			break;
		case 1:
			return 1; 
			break;
		case 2:
			return 0; 
			break;
		case 3:
			return 0; 
			break;
		default:
			break;
		}
	}
	if (type == PIECE_O) {
		switch (orientation) {
		case 0:
		case 1:
		case 2:
		case 3:
			return 0; 
			break; 
		default:
			break;
		}
	}
	if (type == PIECE_S) {
		switch (orientation) {
		case 0:
			return 0; 
			break;
		case 1:
			return 1; 
			break;
		case 2:
			return 0; 
			break;
		case 3:
			return 1; 
			break;
		default:
			break;
		}
	}
	if (type == PIECE_Z) {
		switch (orientation) {
		case 0:
			return 0; 
			break;
		case 1:
			return 1; 
			break;
		case 2:
			return 0; 
			break;
		case 3:
			return 1; 
			break;
		default:
			break;
		}
	}
	if (type == PIECE_VAPOR)
		return 1;
	if (type == PIECE_FOAM)
		return 1;
	if (type == PIECE_CRAZY) {
		switch (orientation) {
		case 0: 
			return 0;
			break;
		case 1: 
			return 3; 
			break; 
		case 2: 
			return 0;
			break; 
		case 3: 
			return 0; 
			break;
		default: 
			break; 
		}
	}
	return 0; 
}

int Piece::xCoord1() const
{
	if (type == PIECE_I) {
		switch (orientation) {
		case 0:
			return 1;
			break;
		case 1:
			return 1;
			break;
		case 2:
			return 1;
			break;
		case 3:
			return 1;
			break;
		default:
			break;
		}
	}
	if (type == PIECE_L) {
		switch (orientation) {
		case 0:
			return 0;
			break;
		case 1:
			return 2;
			break;
		case 2:
			return 1;
			break;
		case 3:
			return 2;
			break;
		default:
			break;
		}
	}
	if (type == PIECE_J) {
		switch (orientation) {
		case 0:
			return 2;
			break;
		case 1:
			return 2;
			break;
		case 2:
			return 1;
			break;
		case 3:
			return 1;
			break;
		default:
			break;
		}
	}
	if (type == PIECE_T) {
		switch (orientation) {
		case 0:
			return 1;
			break;
		case 1:
			return 1;
			break;
		case 2:
			return 1;
			break;
		case 3:
			return 1;
			break;
		default:
			break;
		}
	}
	if (type == PIECE_O) {
		switch (orientation) {
		case 0:
		case 1:
		case 2:
		case 3:
			return 0;
			break;
		default:
			break;
		}
	}
	if (type == PIECE_S) {
		switch (orientation) {
		case 0:
			return 1;
			break;
		case 1:
			return 1;
			break;
		case 2:
			return 1;
			break;
		case 3:
			return 1;
			break;
		default:
			break;
		}
	}
	if (type == PIECE_Z) {
		switch (orientation) {
		case 0:
			return 1;
			break;
		case 1:
			return 1;
			break;
		case 2:
			return 1;
			break;
		case 3:
			return 1;
			break;
		default:
			break;
		}
	}
	if (type == PIECE_VAPOR)
		return 2; 
	if (type == PIECE_CRAZY) {
		switch (orientation) {
		case 0: 
			return 1; 
			break; 
		case 1: 
			return 2; 
			break; 
		case 2: 
			return 1; 
			break; 
		case 3: 
			return 1; 
			break; 
		default:
			break; 
		}
	}
	return 0; 
}

int Piece::xCoord2() const
{
	if (type == PIECE_I) {
		switch (orientation) {
		case 0:
			return 2;
			break;
		case 1:
			return 1;
			break;
		case 2:
			return 2;
			break;
		case 3:
			return 1;
			break;
		default:
			break;
		}
	}
	if (type == PIECE_L) {
		switch (orientation) {
		case 0:
			return 1;
			break;
		case 1:
			return 2;
			break;
		case 2:
			return 2;
			break;
		case 3:
			return 1;
			break;
		default:
			break;
		}
	}
	if (type == PIECE_J) {
		switch (orientation) {
		case 0:
			return 3;
			break;
		case 1:
			return 2;
			break;
		case 2:
			return 2;
			break;
		case 3:
			return 1;
			break;
		default:
			break;
		}
	}
	if (type == PIECE_T) {
		switch (orientation) {
		case 0:
			return 1;
			break;
		case 1:
			return 1;
			break;
		case 2:
			return 1;
			break;
		case 3:
			return 1;
			break;
		default:
			break;
		}
	}
	if (type == PIECE_O) {
		switch (orientation) {
		case 0:
		case 1:
		case 2:
		case 3:
			return 1;
			break;
		default:
			break;
		}
	}
	if (type == PIECE_S) {
		switch (orientation) {
		case 0:
			return 1;
			break;
		case 1:
			return 2;
			break;
		case 2:
			return 1;
			break;
		case 3:
			return 2;
			break;
		default:
			break;
		}
	}
	if (type == PIECE_Z) {
		switch (orientation) {
		case 0:
			return 1;
			break;
		case 1:
			return 2;
			break;
		case 2:
			return 1;
			break;
		case 3:
			return 2;
			break;
		default:
			break;
		}
	}
	if (type == PIECE_CRAZY) {
		switch (orientation) {
		case 0: 
			return 2; 
			break; 
		case 1: 
			return 2; 
			break; 
		case 2: 
			return 2; 
			break; 
		case 3: 
			return 1; 
			break; 
		default: 
			break; 
		}
	}
	return 0;
}

int Piece::xCoord3() const
{
	if (type == PIECE_I) {
		switch (orientation) {
		case 0:
			return 3;
			break;
		case 1:
			return 1;
			break;
		case 2:
			return 3;
			break;
		case 3:
			return 1;
			break;
		default:
			break;
		}
	}
	if (type == PIECE_L) {
		switch (orientation) {
		case 0:
			return 2;
			break;
		case 1:
		case 2: 
		case 3:
			return 2;
			break;
		default:
			break;
		}
	}
	if (type == PIECE_J) {
		switch (orientation) {
		case 0:
			return 3;
			break;
		case 1:
			return 2;
			break;
		case 2:
			return 3;
			break;
		case 3:
			return 2;
			break;
		default:
			break;
		}
	}
	if (type == PIECE_T) {
		switch (orientation) {
		case 0:
		case 1: 
		case 2: 
			return 2; 
			break; 
		case 3:
			return 1;
			break;
		default:
			break;
		}
	}
	if (type == PIECE_O) {
		switch (orientation) {
		case 0:
		case 1:
		case 2:
		case 3:
			return 1;
			break;
		default:
			break;
		}
	}
	if (type == PIECE_S) {
		switch (orientation) {
		case 0:
		case 1: 
		case 2: 
		case 3: 
			return 2; 
			break; 
		default:
			break;
		}
	}
	if (type == PIECE_Z) {
		switch (orientation) {
		case 0:
		case 1: 
		case 2: 
		case 3: 
			return 2; 
			break; 
		default:
			break;
		}
	}
	if (type == PIECE_CRAZY) {
		switch (orientation) {
		case 0:
		case 1:
		case 2:
			return 3;
			break;
		case 3:
			return 0;
			break;
		default:
			break;
		}
	}
	return 0; 
}

int Piece::yCoord0() const
{
	if (type == PIECE_I) {
		switch (orientation) {
		case 0:
			return 1;
			break;
		case 1:
			return 0;
			break;
		case 2:
			return 1;
			break;
		case 3:
			return 0;
			break;
		default:
			break;
		}
	}
	if (type == PIECE_L) {
		switch (orientation) {
		case 0:
			return 1;
			break;
		case 1:
			return 0;
			break;
		case 2:
			return 2;
			break;
		case 3:
			return 1;
			break;
		default:
			break;
		}
	}
	if (type == PIECE_J) {
		switch (orientation) {
		case 0:
			return 1; 
			break; 
		case 1: 
			return 3; 
			break; 
		case 2: 
			return 1; 
			break; 
		case 3:
			return 0;
			break;
		default:
			break;
		}
	}
	if (type == PIECE_T) {
		switch (orientation) {
		case 0:
		case 2: 
		case 3: 
			return 1; 
			break; 
		case 1: 
			return 0; 
			break; 
		default:
			break;
		}
	}
	if (type == PIECE_O) {
		switch (orientation) {
		case 0:
		case 1:
		case 2:
		case 3:
			return 0;
			break;
		default:
			break;
		}
	}
	if (type == PIECE_S) {
		switch (orientation) {
		case 0:
			return 2;
			break;
		case 1:
			return 0;
			break;
		case 2:
			return 2;
			break;
		case 3:
			return 0;
			break;
		default:
			break;
		}
	}
	if (type == PIECE_Z) {
		switch (orientation) {
		case 0:
			return 1;
			break;
		case 1:
			return 0;
			break;
		case 2:
			return 1;
			break;
		case 3:
			return 0;
			break;
		default:
			break;
		}
	}
	if (type == PIECE_VAPOR)
		return 0; 
	if (type == PIECE_FOAM)
		return 1; 
	if (type == PIECE_CRAZY) {
		switch (orientation) {
		case 0: 
			return 0; 
			break; 
		case 1: 
			return 0; 
			break; 
		case 2: 
			return 3; 
			break; 
		case 3: 
			return 0; 
			break; 
		default: 
			break;
		}
	}
	return 0; 
}

int Piece::yCoord1() const
{
	if (type == PIECE_I) {
		switch (orientation) {
		case 0:
		case 1: 
		case 2: 
		case 3: 
			return 1; 
			break; 
		default:
			break;
		}
	}
	if (type == PIECE_L) {
		switch (orientation) {
		case 0:
			return 2;
			break;
		case 1:
			return 0;
			break;
		case 2:
			return 2;
			break;
		case 3:
			return 2;
			break;
		default:
			break;
		}
	}
	if (type == PIECE_J) {
		switch (orientation) {
		case 0:
			return 1;
			break;
		case 1:
			return 1;
			break;
		case 2:
			return 2;
			break;
		case 3:
			return 1;
			break;
		default:
			break;
		}
	}
	if (type == PIECE_T) {
		switch (orientation) {
		case 0:
			return 0;
			break;
		case 1:
			return 1;
			break;
		case 2:
			return 1;
			break;
		case 3:
			return 0;
			break;
		default:
			break;
		}
	}
	if (type == PIECE_O) {
		switch (orientation) {
		case 0:
		case 1:
		case 2:
		case 3:
			return 1;
			break;
		default:
			break;
		}
	}
	if (type == PIECE_S) {
		switch (orientation) {
		case 0:
		case 1: 
		case 2: 
		case 3: 
			return 1; 
			break; 
		default:
			break;
		}
	}
	if (type == PIECE_Z) {
		switch (orientation) {
		case 0:
			return 1;
			break;
		case 1:
			return 2;
			break;
		case 2:
			return 1;
			break;
		case 3:
			return 2;
			break;
		default:
			break;
		}
	}
	if (type == PIECE_VAPOR)
		return 0; 
	if (type == PIECE_CRAZY) {
		switch (orientation) {
		case 0: 
			return 1; 
			break; 
		case 1: 
			return 1; 
			break; 
		case 2: 
			return 2; 
			break; 
		case 3: 
			return 1; 
			break; 
		default: 
			break;
		}
	}
	return 0; 
}

int Piece::yCoord2() const
{
	if (type == PIECE_I) {
		switch (orientation) {
		case 0:
			return 1; 
			break; 
		case 1:
			return 2; 
			break; 
		case 2:
			return 1; 
			break; 
		case 3:
			return 2;
			break;
		default:
			break;
		}
	}
	if (type == PIECE_L) {
		switch (orientation) {
		case 0:
			return 1;
			break;
		case 1:
			return 1;
			break;
		case 2:
			return 1;
			break;
		case 3:
			return 3;
			break;
		default:
			break;
		}
	}
	if (type == PIECE_J) {
		switch (orientation) {
		case 0:
			return 1;
			break;
		case 1:
			return 2;
			break;
		case 2:
			return 2;
			break;
		case 3:
			return 2;
			break;
		default:
			break;
		}
	}
	if (type == PIECE_T) {
		switch (orientation) {
		case 0:
			return 1;
			break;
		case 1:
			return 2;
			break;
		case 2:
			return 2;
			break;
		case 3:
			return 1;
			break;
		default:
			break;
		}
	}
	if (type == PIECE_O) {
		switch (orientation) {
		case 0:
		case 1:
		case 2:
		case 3:
			return 0;
			break;
		default:
			break;
		}
	}
	if (type == PIECE_S) {
		switch (orientation) {
		case 0:
			return 2; 
			break; 
		case 1:
			return 1; 
			break; 
		case 2:
			return 2; 
			break; 
		case 3:
			return 1;
			break;
		default:
			break;
		}
	}
	if (type == PIECE_Z) {
		switch (orientation) {
		case 0:
			return 2;
			break;
		case 1:
			return 0;
			break;
		case 2:
			return 2;
			break;
		case 3:
			return 0;
			break;
		default:
			break;
		}
	}
	if (type == PIECE_CRAZY) {
		switch (orientation) {
		case 0:
			return 1;
			break;
		case 1:
		case 2: 
		case 3: 
			return 2; 
			break; 
		default:
			break;
		}
	}
	return 0; 
}

int Piece::yCoord3() const
{
	if (type == PIECE_I) {
		switch (orientation) {
		case 0:
			return 1;
			break;
		case 1:
			return 3;
			break;
		case 2:
			return 1;
			break;
		case 3:
			return 3;
			break;
		default:
			break;
		}
	}
	if (type == PIECE_L) {
		switch (orientation) {
		case 0:
			return 1;
			break;
		case 1:
			return 2;
			break;
		case 2:
			return 2;
			break;
		case 3:
			return 3;
			break;
		default:
			break;
		}
	}
	if (type == PIECE_J) {
		switch (orientation) {
		case 0:
			return 2;
			break;
		case 1:
			return 3;
			break;
		case 2:
			return 2;
			break;
		case 3:
			return 0;
			break;
		default:
			break;
		}
	}
	if (type == PIECE_T) {
		switch (orientation) {
		case 0:
		case 1: 
		case 2: 
			return 1; 
			break; 
		case 3:
			return 2;
			break;
		default:
			break;
		}
	}
	if (type == PIECE_O) {
		switch (orientation) {
		case 0:
		case 1:
		case 2:
		case 3:
			return 1;
			break;
		default:
			break;
		}
	}
	if (type == PIECE_S) {
		switch (orientation) {
		case 0:
			return 1;
			break;
		case 1:
			return 2;
			break;
		case 2:
			return 1;
			break;
		case 3:
			return 2;
			break;
		default:
			break;
		}
	}
	if (type == PIECE_Z) {
		switch (orientation) {
		case 0:
			return 2;
			break;
		case 1:
			return 1;
			break;
		case 2:
			return 2;
			break;
		case 3:
			return 1;
			break;
		default:
			break;
		}
	}
	if (type == PIECE_CRAZY) {
		switch (orientation) {
		case 0:
			return 0;
			break;
		case 1:
		case 2: 
		case 3: 
			return 3; 
			break; 
		default:
			break;
		}
	}
	return 0; 
}

I_Piece::I_Piece()
{
	setPieceType(PIECE_I); 
}

I_Piece::~I_Piece()
{
}

void I_Piece::displayPiece(Screen& screen) const
{
	switch (getOrientation()) {
	case 0: 
		for (int i = 0; i < 4; i++) {
			screen.gotoXY(getxCoord() + i, getyCoord() + 1);
			screen.printChar('#'); 
		}
		break; 
	case 1: 
		for (int i = 0; i < 4; i++) {
			screen.gotoXY(getxCoord() + 1, getyCoord() + i);
			screen.printChar('#'); 
		}
		break; 
	case 2: 
		for (int i = 0; i < 4; i++) {
			screen.gotoXY(getxCoord() + i, getyCoord() + 1); 
			screen.printChar('#'); 
		}
		break; 
	case 3: 
		for (int i = 0; i < 4; i++) {
			screen.gotoXY(getxCoord() + 1, getyCoord() + i); 
			screen.printChar('#'); 
		}
		break; 
	default: 
		break; 
	}

}

L_Piece::L_Piece()
{
	setPieceType(PIECE_L); 
}

L_Piece::~L_Piece()
{
}

void L_Piece::displayPiece(Screen & screen) const
{
	switch (getOrientation()) {
	case 0: 
		for (int i = 0; i < 3; i++) {
			screen.gotoXY(getxCoord() + i, getyCoord() + 1); 
			screen.printChar('#'); 
		}
		screen.gotoXY(getxCoord(), getyCoord() + 2); 
		screen.printChar('#'); 
		break; 
	case 1: 
		for (int i = 0; i < 3; i++) {
			screen.gotoXY(getxCoord() + 2, getyCoord() + i); 
			screen.printChar('#'); 
		}
		screen.gotoXY(getxCoord() + 1, getyCoord()); 
		screen.printChar('#'); 
		break; 
	case 2: 
		for (int i = 0; i < 3; i++) {
			screen.gotoXY(getxCoord() + i, getyCoord() + 2); 
			screen.printChar('#'); 
		}
		screen.gotoXY(getxCoord() + 2, getyCoord() + 1); 
		screen.printChar('#'); 
		break; 
	case 3: 
		for (int i = 0; i < 3; i++) {
			screen.gotoXY(getxCoord() + 1, getyCoord() + 1 + i); 
			screen.printChar('#'); 
		}
		screen.gotoXY(getxCoord() + 2, getyCoord() + 3); 
		screen.printChar('#'); 
		break; 
	default: 
		break; 
	}
}

J_Piece::J_Piece()
{
	setPieceType(PIECE_J); 
}

J_Piece::~J_Piece()
{
}

void J_Piece::displayPiece(Screen & screen) const
{
	switch (getOrientation()) {
	case 0: 
		for (int i = 0; i < 3; i++) {
			screen.gotoXY(getxCoord() + 1 + i, getyCoord() + 1); 
			screen.printChar('#'); 
		}
		screen.gotoXY(getxCoord() + 3, getyCoord() + 2); 
		screen.printChar('#'); 
		break; 
	case 1: 
		for (int i = 0; i < 3; i++) {
			screen.gotoXY(getxCoord() + 2, getyCoord() + 1 + i); 
			screen.printChar('#'); 
		}
		screen.gotoXY(getxCoord() + 1, getyCoord() + 3); 
		screen.printChar('#'); 
		break; 
	case 2: 
		for (int i = 0; i < 3; i++) {
			screen.gotoXY(getxCoord() + 1 + i, getyCoord() + 2); 
			screen.printChar('#');
		}
		screen.gotoXY(getxCoord() + 1, getyCoord() + 1); 
		screen.printChar('#'); 
		break; 
	case 3: 
		for (int i = 0; i < 3; i++) {
			screen.gotoXY(getxCoord() + 1, getyCoord() + i); 
			screen.printChar('#'); 
		}
		screen.gotoXY(getxCoord() + 2, getyCoord()); 
		screen.printChar('#'); 
		break; 
	default: 
		break; 
	}
}

T_Piece::T_Piece()
{
	setPieceType(PIECE_T); 
}

T_Piece::~T_Piece()
{
}

void T_Piece::displayPiece(Screen& screen) const
{
	switch (getOrientation()) {
	case 0: 
		screen.gotoXY(getxCoord() + 1, getyCoord()); 
		screen.printChar('#'); 
		for (int i = 0; i < 3; i++) {
			screen.gotoXY(getxCoord() + i, getyCoord()+1);
			screen.printChar('#'); 
		}
		break; 
	case 1: 
		for (int i = 0; i< 3; i++) {
			screen.gotoXY(getxCoord() + 1, getyCoord() + i); 
			screen.printChar('#'); 
		}
		screen.gotoXY(getxCoord() + 2, getyCoord() + 1); 
		screen.printChar('#');
		break; 
	case 2: 
		for (int i = 0; i < 3; i++) {
			screen.gotoXY(getxCoord() + i, getyCoord() + 1); 
			screen.printChar('#'); 
		}
		screen.gotoXY(getxCoord() + 1, getyCoord() + 2); 
		screen.printChar('#'); 
		break; 
	case 3: 
		for (int i = 0; i < 3; i++) {
			screen.gotoXY(getxCoord() + 1, getyCoord() + i); 
			screen.printChar('#'); 
		}
		screen.gotoXY(getxCoord(), getyCoord() + 1); 
		screen.printChar('#'); 
		break; 
	default: 
		break; 
	}
}

O_Piece::O_Piece()
{
	setPieceType(PIECE_O); 
}

O_Piece::~O_Piece()
{
}

void O_Piece::displayPiece(Screen & screen) const
{
	switch (getOrientation()) {
	case 0: 
	case 1: 
	case 2: 
	case 3: 
		for (int i = 0; i < 2; i++) {
			screen.gotoXY(getxCoord() + i, getyCoord()); 
			screen.printChar('#'); 
		}
		for (int i = 0; i < 2; i++) {
			screen.gotoXY(getxCoord() + i, getyCoord() + 1); 
			screen.printChar('#'); 
		}
		break; 
	default: 
		break; 
	}
}

S_Piece::S_Piece()
{
	setPieceType(PIECE_S); 
}

S_Piece::~S_Piece()
{
}

void S_Piece::displayPiece(Screen & screen) const
{
	switch (getOrientation()) {
	case 0:
		for (int i = 0; i < 2; i++) {
			screen.gotoXY(getxCoord() + 1 + i, getyCoord() + 1);
			screen.printChar('#');
		}
		for (int i = 0; i < 2; i++) {
			screen.gotoXY(getxCoord() + i, getyCoord() + 2);
			screen.printChar('#');
		}
		break;
	case 1:
		for (int i = 0; i < 2; i++) {
			screen.gotoXY(getxCoord() + 1, getyCoord() + i);
			screen.printChar('#');
		}
		for (int i = 0; i < 2; i++) {
			screen.gotoXY(getxCoord() + 2, getyCoord() + 1 + i);
			screen.printChar('#');
		}
		break;
	case 2:
		for (int i = 0; i < 2; i++) {
			screen.gotoXY(getxCoord() + 1 + i, getyCoord() + 1);
			screen.printChar('#');
		}
		for (int i = 0; i < 2; i++) {
			screen.gotoXY(getxCoord() + i, getyCoord() + 2);
			screen.printChar('#');
		}
		break;
	case 3:
		for (int i = 0; i < 2; i++) {
			screen.gotoXY(getxCoord() + 1, getyCoord() + i);
			screen.printChar('#');
		}
		for (int i = 0; i < 2; i++) {
			screen.gotoXY(getxCoord() + 2, getyCoord() + 1 + i);
			screen.printChar('#');
		}
		break;
	default:
		break;
	}
}

Z_Piece::Z_Piece()
{
	setPieceType(PIECE_Z); 
}

Z_Piece::~Z_Piece()
{
}

void Z_Piece::displayPiece(Screen & screen) const
{
	switch (getOrientation()) {
	case 0: 
		for (int i = 0; i < 2; i++) {
			screen.gotoXY(getxCoord() + i, getyCoord() + 1); 
			screen.printChar('#'); 
		}
		for (int i = 0; i < 2; i++) {
			screen.gotoXY(getxCoord() + 1 + i, getyCoord() + 2); 
			screen.printChar('#');
		}
		break; 
	case 1: 
		for (int i = 0; i < 2; i++) {
			screen.gotoXY(getxCoord() + 2, getyCoord() + i); 
			screen.printChar('#'); 
		}
		for (int i = 0; i < 2; i++) {
			screen.gotoXY(getxCoord() + 1, getyCoord() + 1 + i); 
			screen.printChar('#'); 
		}
		break; 
	case 2: 
		for (int i = 0; i < 2; i++) {
			screen.gotoXY(getxCoord() + i, getyCoord() + 1); 
			screen.printChar('#'); 
		}
		for (int i = 0; i < 2; i++) {
			screen.gotoXY(getxCoord() + 1 + i, getyCoord() + 2); 
			screen.printChar('#'); 
		}
		break; 
	case 3: 
		for (int i = 0; i < 2; i++) {
			screen.gotoXY(getxCoord() + 2, getyCoord() + i); 
			screen.printChar('#'); 
		}
		for (int i = 0; i < 2; i++) {
			screen.gotoXY(getxCoord() + 1, getyCoord() + 1 + i); 
			screen.printChar('#'); 
		}
		break; 
	default:
		break; 
	}
}

VAPORBOMB::VAPORBOMB()
{
	setPieceType(PIECE_VAPOR); 
}

VAPORBOMB::~VAPORBOMB()
{

}

void VAPORBOMB::displayPiece(Screen & screen) const
{
	switch (getOrientation()) {
	case 0: 
	case 1: 
	case 2: 
	case 3: 
		screen.gotoXY(getxCoord() + 1, getyCoord()); 
		screen.printChar('#'); 
		screen.gotoXY(getxCoord() + 2, getyCoord()); 
		screen.printChar('#'); 
	default: 
		break; 
	}
}

FOAMBOMB::FOAMBOMB()
{
	setPieceType(PIECE_FOAM); 
}

FOAMBOMB::~FOAMBOMB()
{

}

void FOAMBOMB::displayPiece(Screen & screen) const
{
	switch (getOrientation()) {
	case 0: 
	case 1: 
	case 2: 
	case 3: 
		screen.gotoXY(getxCoord() + 1, getyCoord() + 1); 
		screen.printChar('#'); 
	default: 
		break; 
	}
}


CRAZYSHAPE::CRAZYSHAPE() 
{
	setPieceType(PIECE_CRAZY);	
}

CRAZYSHAPE::~CRAZYSHAPE()
{

}

void CRAZYSHAPE::moveLeft() //Account for adverse effects of crazy shape for both left and right movements 
{
	setxCoord(getxCoord() + 1); 
}

void CRAZYSHAPE::moveRight()
{
	setxCoord(getxCoord() - 1); 
}

void CRAZYSHAPE::displayPiece(Screen& screen) const
{
	switch (getOrientation()) {
	case 0: 
		screen.gotoXY(getxCoord(), getyCoord()); 
		screen.printChar('#'); 
		screen.gotoXY(getxCoord() + 1, getyCoord() + 1); 
		screen.printChar('#'); 
		screen.gotoXY(getxCoord() + 2, getyCoord() + 1); 
		screen.printChar('#'); 
		screen.gotoXY(getxCoord() + 3, getyCoord()); 
		screen.printChar('#'); 
		break; 
	case 1: 
		for (int i = 0; i < 2; i++) {
			screen.gotoXY(getxCoord() + 2, getyCoord() + 1 + i); 
			screen.printChar('#'); 
		}
		screen.gotoXY(getxCoord() + 3, getyCoord()); 
		screen.printChar('#'); 
		screen.gotoXY(getxCoord() + 3, getyCoord() + 3); 
		screen.printChar('#'); 
		break; 
	case 2: 
		screen.gotoXY(getxCoord(), getyCoord() + 3); 
		screen.printChar('#'); 
		for (int i = 0; i < 2; i++) {
			screen.gotoXY(getxCoord() + 1 + i, getyCoord() + 2); 
			screen.printChar('#'); 
		}
		screen.gotoXY(getxCoord() + 3, getyCoord() + 3); 
		screen.printChar('#'); 
		break; 
	case 3: 
		screen.gotoXY(getxCoord(), getyCoord()); 
		screen.printChar('#'); 
		for (int i = 0; i < 2; i++) {
			screen.gotoXY(getxCoord() + 1, getyCoord() + 1 + i); 
			screen.printChar('#'); 
		}
		screen.gotoXY(getxCoord(), getyCoord() + 3); 
		screen.printChar('#'); 
		break; 
	default: 
		break; 
	}
}
