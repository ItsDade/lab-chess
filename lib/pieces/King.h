#ifndef KING_H
#define KING_H

// Includes
#include "Piece.h"

class King : public Piece {
public:
	// Constructors
	King(Color c);

	// Functions
	bool canMove(Board* b, Square* i, Square* f);
	std::string toString();

private:

};

#endif // !KING_H


