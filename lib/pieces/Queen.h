#ifndef QUEEN_H
#define QUEEN_H

// Includes
#include "Piece.h"

class Queen : public Piece {
public:
	// Constructors
	Queen(Color c);

	// Functions
	bool canMove(Board* b, Square* i, Square* f);
	std::string toString();

private:

};

#endif // !QUEEN_H


