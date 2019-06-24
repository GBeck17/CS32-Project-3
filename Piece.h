#ifndef PIECE_INCLUDED
#define PIECE_INCLUDED
#include "UserInterface.h"


const int numOrientations = 4; 

class Game;
class Screen; 

enum PieceType {
    PIECE_I, PIECE_L, PIECE_J, PIECE_T, PIECE_O, PIECE_S, PIECE_Z,
    PIECE_VAPOR, PIECE_FOAM, PIECE_CRAZY, NUM_PIECE_TYPES
};

PieceType chooseRandomPieceType();

class Piece {
public: 
	Piece(); 
	virtual ~Piece(); 
	virtual void moveLeft(); 
	virtual void moveRight(); 
	void moveDown();
	void rotate();   
	virtual void displayPiece(Screen& screen) const = 0; // A general piece will never need to be displayed/created
	int getOrientation() const;
	void setOrientation(int n); 
	int getxCoord() const; 
	int getyCoord() const; 
	void setxCoord(int n); 
	void setyCoord(int n); 
	PieceType getPieceType() const; 
	void setPieceType(PieceType piece_type); 
	int xCoord0() const; 
	int xCoord1() const; 
	int xCoord2() const; 
	int xCoord3() const; 
	int yCoord0() const; 
	int yCoord1() const; 
	int yCoord2() const; 
	int yCoord3() const; 
private: 
	int orientation;
	int xCoord; 
	int yCoord; 
	PieceType type; 
};

class I_Piece : public Piece {
public: 
	I_Piece();  
	virtual ~I_Piece(); 
	virtual void displayPiece(Screen& screen) const; 

};

class L_Piece : public Piece {
public: 
	L_Piece();  
	virtual ~L_Piece(); 
	virtual void displayPiece(Screen& screen) const; 
	
};

class J_Piece : public Piece {
public: 
	J_Piece(); 
	virtual ~J_Piece(); 
	virtual void displayPiece(Screen& screen) const; 
	
};
class T_Piece : public Piece {
public: 
	T_Piece();  
	virtual ~T_Piece(); 
	virtual void displayPiece(Screen& screen) const; 
	
};

class O_Piece : public Piece {
public: 
	O_Piece();
	virtual ~O_Piece(); 
	virtual void displayPiece(Screen& screen) const; 
	
};

class S_Piece : public Piece {
public: 
	S_Piece(); 
	virtual ~S_Piece(); 
	virtual void displayPiece(Screen& screen) const; 
	
private: 
	 
};

class Z_Piece : public Piece {
public: 
	Z_Piece();  
	virtual ~Z_Piece(); 
	virtual void displayPiece(Screen& screen) const;  

};

class VAPORBOMB : public Piece {
public: 
	VAPORBOMB(); 
	virtual ~VAPORBOMB(); 
	virtual void displayPiece(Screen& screen) const; 
};

class FOAMBOMB : public Piece {
public: 
	FOAMBOMB(); 
	virtual ~FOAMBOMB(); 
	virtual void displayPiece(Screen& screen) const;
};

class CRAZYSHAPE : public Piece {
public: 
	CRAZYSHAPE(); 
	virtual ~CRAZYSHAPE(); 
	virtual void moveLeft(); 
	virtual void moveRight(); 
	virtual void displayPiece(Screen& screen) const; 
};


#endif // PIECE_INCLUDED
