#include "Game.h"
#include "Well.h"
#include "UserInterface.h"
#include <string>
#include <iomanip>

const int SCREEN_WIDTH = 80;
const int SCREEN_HEIGHT = 25;

const int WELL_X = 0;
const int WELL_Y = 0;

const int PROMPT_Y = 20;
const int PROMPT_X = 0;

const int SCORE_X = 16;
const int SCORE_Y = 8;

const int ROWS_LEFT_X = 16;
const int ROWS_LEFT_Y = 9;

const int LEVEL_X = 16;
const int LEVEL_Y = 10;

const int NEXT_PIECE_TITLE_X = 16;
const int NEXT_PIECE_TITLE_Y = 3;

const int NEXT_PIECE_X = 16;
const int NEXT_PIECE_Y = 4;

Game::Game(int width, int height)
 : m_screen(SCREEN_WIDTH, SCREEN_HEIGHT), m_level(1)
{
}

void Game::play()
{
    m_well.display(m_screen, WELL_X, WELL_Y);
    displayStatus();  //  score, rows left, level
    displayPrompt("Press the Enter key to begin playing Chetyris!");
    waitForEnter();  // [in UserInterface.h]

    for(;;)
    {
        if ( ! playOneLevel())
            break;
        displayPrompt("Good job!  Press the Enter key to start next level!");
        waitForEnter();
        m_level++;
		// If level is completed, clear screen, delete dynamic memory and redisplay well, status 
		m_screen.clear();
		if (currPiece != nullptr)
			delete currPiece;
		delete nextPiece;
		m_well.clearGrid();
    }
    displayPrompt("Game Over!  Press the Enter key to exit!");
    waitForEnter();
}

void Game::displayPrompt(std::string s)     
{
    m_screen.gotoXY(PROMPT_X, PROMPT_Y);
    m_screen.printStringClearLine(s);   // overwrites previous text
    m_screen.refresh();
}

void Game::displayStatus()
{
    // [Replace this with code to display the status.]
	m_screen.gotoXY(16, 3); 
	m_screen.printString("Next piece:"); 
	std::string one = "";
	std::string two = "";
	std::string three = "";
	justify(one, two, three); 

	m_screen.gotoXY(SCORE_X, SCORE_Y);
	m_screen.printString("Score:     " + one + std::to_string(m_score));
	
	m_screen.gotoXY(ROWS_LEFT_X,ROWS_LEFT_Y); 
	m_screen.printString("Rows left: " + two + std::to_string(m_rowsNeeded));

	m_screen.gotoXY(LEVEL_X,LEVEL_Y);
	m_screen.printString("Level:     " + three + std::to_string(m_level));

}

Game::~Game()
{
	delete currPiece; 
	delete nextPiece; 
}

bool Game::checkCollisionDown(Piece* piece) const // Checks if any of four points below current piece are taken by well 
// Switch statement is needed for each type of piece 
{
	if (piece->getPieceType() == PIECE_VAPOR) {
		if (!m_well.isTaken(piece->xCoord0() + piece->getxCoord(), piece->yCoord0() + piece->getyCoord() + 1)) {
			if (!m_well.isTaken(piece->xCoord1() + piece->getxCoord(), piece->yCoord1() + piece->getyCoord() + 1)) {
				return false; 
			}
		}
		return true; 
	}
	if (piece->getPieceType() == PIECE_FOAM) {
		if (!m_well.isTaken(piece->xCoord0() + piece->getxCoord(), piece->yCoord0() + piece->getyCoord() + 1))
			return false; 
		return true; 
	}
	else {
		if (!m_well.isTaken(piece->xCoord0() + piece->getxCoord(), piece->yCoord0() + piece->getyCoord() + 1)) {
			if (!m_well.isTaken(piece->xCoord1() + piece->getxCoord(), piece->yCoord1() + piece->getyCoord() + 1)) {
				if (!m_well.isTaken(piece->xCoord2() + piece->getxCoord(), piece->yCoord2() + piece->getyCoord() + 1)) {
					if (!m_well.isTaken(piece->xCoord3() + piece->getxCoord(), piece->yCoord3() + piece->getyCoord() + 1))
						return false;
				}
			}
		}
	}
	return true; 
}

bool Game::checkCollisionRight(Piece * piece) const
{
	if (piece->getPieceType() == PIECE_VAPOR) {
		if (!m_well.isTaken(piece->xCoord0() + piece->getxCoord() + 1, piece->yCoord0() + piece->getyCoord())) {
			if (!m_well.isTaken(piece->xCoord1() + piece->getxCoord() + 1, piece->yCoord1() + piece->getyCoord())) {
				return false; 
			}
		}
		return true; 
	}
	if (piece->getPieceType() == PIECE_FOAM) {
		if (!m_well.isTaken(piece->xCoord0() + piece->getxCoord() + 1, piece->yCoord0() + piece->getyCoord()))
			return false;
		return true;

	}
	else {
		if (!m_well.isTaken(piece->xCoord0() + piece->getxCoord() + 1, piece->yCoord0() + piece->getyCoord())) {
			if (!m_well.isTaken(piece->xCoord1() + piece->getxCoord() + 1, piece->yCoord1() + piece->getyCoord())) {
				if (!m_well.isTaken(piece->xCoord2() + piece->getxCoord() + 1, piece->yCoord2() + piece->getyCoord())) {
					if (!m_well.isTaken(piece->xCoord3() + piece->getxCoord() + 1, piece->yCoord3() + piece->getyCoord()))
						return false;
				}
			}
		}
	}
	return true;
}

bool Game::checkCollisionLeft(Piece * piece) const
{
	if (piece->getPieceType() == PIECE_VAPOR) {
		if (!m_well.isTaken(piece->xCoord0() + piece->getxCoord() - 1, piece->yCoord0() + piece->getyCoord())) {
			if (!m_well.isTaken(piece->xCoord1() + piece->getxCoord() - 1, piece->yCoord1() + piece->getyCoord()))
				return false; 
		}
		return true; 
	}
	if (piece->getPieceType() == PIECE_FOAM) {
		if (!m_well.isTaken(piece->xCoord0() + piece->getxCoord() - 1, piece->yCoord0() + piece->getyCoord()))
			return false; 
		return true; 
	}
	else {
		if (!m_well.isTaken(piece->xCoord0() + piece->getxCoord() - 1, piece->yCoord0() + piece->getyCoord())) {
			if (!m_well.isTaken(piece->xCoord1() + piece->getxCoord() - 1, piece->yCoord1() + piece->getyCoord())) {
				if (!m_well.isTaken(piece->xCoord2() + piece->getxCoord() - 1, piece->yCoord2() + piece->getyCoord())) {
					if (!m_well.isTaken(piece->xCoord3() + piece->getxCoord() - 1, piece->yCoord3() + piece->getyCoord()))
						return false;
				}
			}
		}
	}
	return true;
}

void Game::updateGame(Piece * piece)
{
	if (currPiece->getPieceType() == PIECE_VAPOR) // Effects of VaporBomb 
	{
		// Call well's update function for vapor bomb 
		m_well.updateWellVapor(piece); 
	}
	else if (currPiece->getPieceType() == PIECE_FOAM) // Effects of FoamBomb 
	{
		// Call well's RECURSIVE update function for foam bomb 
		m_well.updateWellFoam(currPiece); 
	}
	else {
		// Just normal piece or crazy piece, either option yields no special effects upon collision 
		m_well.updateWell(currPiece->xCoord0() + currPiece->getxCoord(), currPiece->yCoord0() + currPiece->getyCoord(), currPiece->xCoord1() + currPiece->getxCoord(),
			currPiece->yCoord1() + currPiece->getyCoord(), currPiece->xCoord2() + currPiece->getxCoord(), currPiece->yCoord2() + currPiece->getyCoord(),
			currPiece->xCoord3() + currPiece->getxCoord(), currPiece->yCoord3() + currPiece->getyCoord());
	}

	// Delete current piece and assign it to the next piece 
	delete currPiece;
	currPiece = nextPiece;

	// After next piece transfers piece to current, determine 'new' next piece 
	switch (chooseRandomPieceType()) {
	case PIECE_I:
		nextPiece = new I_Piece;
		break;
	case PIECE_L:
		nextPiece = new L_Piece;
		break;
	case PIECE_J:
		nextPiece = new J_Piece;
		break;
	case PIECE_T:
		nextPiece = new T_Piece;
		break;
	case PIECE_O:
		nextPiece = new O_Piece;
		break;
	case PIECE_S:
		nextPiece = new S_Piece;
		break;
	case PIECE_Z:
		nextPiece = new Z_Piece;
		break;
	case PIECE_VAPOR:
		nextPiece = new VAPORBOMB;
		break;
	case PIECE_FOAM:
		nextPiece = new FOAMBOMB;
		break;
	case PIECE_CRAZY:
		nextPiece = new CRAZYSHAPE;
		break;
	default:
		break;
	}
	// Set coords for current piece to fall from 
	currPiece->setxCoord(3);
	currPiece->setyCoord(0);
	// Check for any rows to vaporize and change well, score, and rows needed accordingly 
	int count = m_well.vaporizeRows();
	if (count > 0) {
		m_rowsNeeded -= count;
		setScore(count);
	}
	// Display well (with pieces inside) and status at end of each 'cycle' 
	m_well.display(m_screen, WELL_X, WELL_Y);
	displayStatus(); 
}

int Game::max(int a, int b) const
{
	if (a > b)
		return a;
	else
		return b; 
}

void Game::justify(std::string &one, std::string &two, std::string &three)
{
	std::string score = std::to_string(m_score);
	int amount1 = 7 - (score.length());
	std::string rows = std::to_string(m_rowsNeeded);
	int amount2 = 7 - (rows.length());
	std::string level = std::to_string(m_level);
	int amount3 = 7 - (level.length());
	
	while (one.length() < amount1) {
		one += " ";
	}
	while (two.length() < amount2) {
		two += " ";
	}
	while (three.length() < amount3) {
		three += " ";
	}
}

bool Game::playOneLevel()
{ 
	m_rowsNeeded = 5 * m_level; 
	Timer m_timer;
	//First, determine the first set of current and next piece... this portion will only run ONCE per level 

	switch (chooseRandomPieceType()) {
	case PIECE_I:
		currPiece = new I_Piece; 
		break;
	case PIECE_L:
		currPiece = new L_Piece; 
		break;
	case PIECE_J:
		currPiece = new J_Piece; 
		break;
	case PIECE_T:
		currPiece = new T_Piece;
		break;
	case PIECE_O:
		currPiece = new O_Piece; 
		break;
	case PIECE_S:
		currPiece = new S_Piece; 
		break;
	case PIECE_Z:
		currPiece = new Z_Piece; 
		break;
	case PIECE_VAPOR: 
		currPiece = new VAPORBOMB; 
		break; 
	case PIECE_FOAM: 
		currPiece = new FOAMBOMB; 
		break; 
	case PIECE_CRAZY: 
		currPiece = new CRAZYSHAPE; 
		break; 
	default:
		break;
	}
	 // Determine next piece 
	switch (chooseRandomPieceType()) {
	case PIECE_I:
		nextPiece = new I_Piece; 
		break;
	case PIECE_L:
		nextPiece = new L_Piece; 
		break;
	case PIECE_J:
		nextPiece = new J_Piece; 
		break;
	case PIECE_T:
		nextPiece = new T_Piece;
		break;
	case PIECE_O:
		nextPiece = new O_Piece; 
		break;
	case PIECE_S:
		nextPiece = new S_Piece; 
		break;
	case PIECE_Z:
		nextPiece = new Z_Piece; 
		break;
	case PIECE_VAPOR: 
		nextPiece = new VAPORBOMB; 
		break; 
	case PIECE_FOAM: 
		nextPiece = new FOAMBOMB; 
		break; 
	case PIECE_CRAZY: 
		nextPiece = new CRAZYSHAPE; 
		break; 
	default:
		break;
	}
	currPiece->setxCoord(3);
	currPiece->setyCoord(0); 
	
	nextPiece->setxCoord(NEXT_PIECE_X); 
	nextPiece->setyCoord(NEXT_PIECE_Y); 
	
	int code; 
	int timeAllowed = max(1000 - (100 * (m_level - 1)), 100); // Amount of time dependent on level
	while (m_rowsNeeded > 0 && (m_well.topRow() > 0)) // Loop until # of required vaporized rows is reached || fallen pieces exceed well height
	{ 
		currPiece->displayPiece(m_screen);
		nextPiece->displayPiece(m_screen);
		code = 0;// Helps distinguish collision due to movement vs game's downward shift 
		m_timer.start();
		while (m_timer.elapsed() < timeAllowed) // Allow for  seconds to elapse 
		{
			char move;
			if (getCharIfAny(move))
			{
				// There was a character typed; it's now in ch
				switch (move)
				{
				// Move piece left 
				case ARROW_LEFT:
				case 'a':
					if (currPiece->getPieceType() == PIECE_CRAZY) // Crazy Piece will have reverse effects, so much check to its left instead
					{
						if (m_well.getCell(currPiece->getxCoord() + currPiece->xCoord0() + 1, currPiece->getyCoord() + currPiece->yCoord0()) == '@')
							break;
					}
					else if (checkCollisionLeft(currPiece)) {
						if (currPiece->getPieceType() == PIECE_FOAM) 
						{
							if (m_well.getCell(currPiece->getxCoord() + currPiece->xCoord0() - 1, currPiece->getyCoord() + currPiece->yCoord0()) == '@')
								break;
						}
						else if (currPiece->getPieceType() == PIECE_VAPOR) 
						{
							if (m_well.getCell(currPiece->getxCoord() + currPiece->xCoord0() - 1, currPiece->getyCoord() + currPiece->yCoord0()) == '@')
								break;
						}
						else // Piece will have 4 coord pairs 
						{
							if (m_well.getCell(currPiece->getxCoord() + currPiece->xCoord0() - 1, currPiece->getyCoord() + currPiece->yCoord0()) == '@')
								break;
						}
						code = 1;
						updateGame(currPiece);
						break;
					}
					currPiece->moveLeft();
					break;
				// Move piece right 
				case ARROW_RIGHT:
				case 'd':
					if (currPiece->getPieceType() == PIECE_CRAZY) // Crazy Piece will have reverse effects, so much check to its left instead
					{
						if (m_well.getCell(currPiece->getxCoord() + currPiece->xCoord0() - 1, currPiece->getyCoord() + currPiece->yCoord0()) == '@')
							break;
					}
					else if (checkCollisionRight(currPiece)) {
						if (currPiece->getPieceType() == PIECE_FOAM) 
						{
							if (m_well.getCell(currPiece->getxCoord() + currPiece->xCoord0() + 1, currPiece->getyCoord() + currPiece->yCoord0()) == '@')
								break; 
						}
						else if (currPiece->getPieceType() == PIECE_VAPOR)  
						{
							if (m_well.getCell(currPiece->getxCoord() + currPiece->xCoord1() + 1, currPiece->getyCoord() + currPiece->yCoord1()) == '@')
								break; 
						}
						else
						{ 
							if (m_well.getCell(currPiece->getxCoord() + currPiece->xCoord3() + 1, currPiece->getyCoord() + currPiece->yCoord3()) == '@')
								break;
						}
						code = 1; 
						updateGame(currPiece); 
						break; 
					}
					currPiece->moveRight();
					break;
				// Rotate piece 
				case ARROW_UP:
				case 'w':
					currPiece->rotate();
					break;
				// Accelerate piece down 
				case ARROW_DOWN:
				case 's':
					if (checkCollisionDown(currPiece)) {
						code = 1;
						updateGame(currPiece);
						break;
					}
					currPiece->moveDown(); 
					break; 
				// Place down instantly 
				case ' ': 
					while (!checkCollisionDown(currPiece)) {
						currPiece->moveDown(); 
					}
					code = 1; 
					updateGame(currPiece); 
					break; 
				// Quit game 
				case 'Q': 
				case 'q': 
					return false;  
					break; 
				default:
					break;
				}
				m_screen.clear();
				m_well.display(m_screen, WELL_X, WELL_Y); 
				displayStatus(); 
				currPiece->displayPiece(m_screen);
				nextPiece->displayPiece(m_screen); 
			}
		} 
		// Check if piece has collided NOT due to user input 
		if (checkCollisionDown(currPiece) && code == 0) 
			updateGame(currPiece); // Make whatever changes to the well regarding piece's resting place/special actions before deleting current piece 
		
		// Otherwise no collision yet, refresh and move piece down following timer tick 
		else if (code == 0) {
			m_screen.clear();
			currPiece->moveDown();
			m_well.display(m_screen, WELL_X, WELL_Y);
			displayStatus();
		}
	}
	if (m_well.topRow() <= 0)
		return false;  
	return true;
}

int Game::getLevel() const {
	return m_level; 
}

int Game::getScore() const
{
	return m_score; 
}


void Game::setScore(int rowsFilledatOnce)
{
	switch (rowsFilledatOnce) {
	case 1: 
		m_score += 100; 
		break; 
	case 2: 
		m_score += 200; 
		break;
	case 3:
		m_score += 400; 
		break; 
	case 4: 
		m_score += 800; 
		break; 
	case 5: 
		m_score += 1600; 
		break; 
	default: 
		break; 
	}
}



