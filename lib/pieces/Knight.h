#ifndef KNIGHT_H
#define KNIGHT_H

// Includes
#include "Piece.h"

class Knight : public Piece {
public:
	// Constructors
	Knight(Color c);

	// Functions
	bool canMove(Board* b, Square* i, Square* f);
	std::string toString();

private:

};

#endif // !KNIGHT_H


