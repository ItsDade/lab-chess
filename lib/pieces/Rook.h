#ifndef ROOK_H
#define ROOK_H

// Includes
#include "Piece.h"

class Rook : public Piece {
public:
	// Constructors
	Rook(Color c);

	// Functions
	bool canMove(Board* b, Square* i, Square* f);
	std::string toString();

private:

};

#endif // !ROOK_H


