#ifndef GAME_INCLUDED
#define GAME_INCLUDED

#include "Well.h"
#include "UserInterface.h"
#include <string>
// [Add other #include directives as necessary.]
#include "Piece.h"

class Game
{
  public:
    Game(int width, int height);
    void play();
    bool playOneLevel();
    void displayPrompt(std::string s);
    void displayStatus(); 
    // [Add other members as necessary.]
	~Game(); 
	bool checkCollisionDown(Piece* piece) const;
	bool checkCollisionRight(Piece* piece) const; 
	bool checkCollisionLeft(Piece* piece) const; 
	void updateGame(Piece* piece);
	int max(int a, int b) const; 
	void justify(std::string& one, std::string& two, std::string& three);

	// Accessors 
	int getLevel() const;
	int getScore() const; 

	// Mutators 
	void setScore(int rowsFilledatOnce); 

  private:
    Well    m_well; 
    Screen  m_screen;
    int     m_level = 1;
    // [Add other members as necessary.]
	Piece* currPiece; // 
	Piece* nextPiece; 
	int m_score = 0; 
	
	int m_rowsNeeded = 5; // Keeps track of how many rows needed to complete level
	
};

#endif // GAME_INCLUDED
