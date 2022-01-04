#ifndef PAWN_H
#define PAWN_H

// Includes
#include "Piece.h"


class Pawn : public Piece {
	public:
		// Constructors
		Pawn(Color c);

		// Functions
		bool canMove(Board* b, Square* i, Square* f);
		std::string toString();

	private:
		bool firstMove = true;

};

#endif // !PAWN_H

