#ifndef BISHOP_H
#define BISHOP_H

// Includes
#include "Piece.h"


class Bishop : public Piece {
public:
	// Constructors
	Bishop(Color c);

	// Functions
	bool canMove(Board* b, Square* i, Square* f);
	std::string toString();

private:

};

#endif // !BISHOP_H


