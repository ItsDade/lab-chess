#include "King.h"
#include "../board/Board.h"
#include "../board/Square.h"

// Constructors
King::King(Color c) : Piece(c) {}

// Functions
bool King::canMove(Board* b, Square* i, Square* f) {
	return false;
}

std::string King::toString() {
	if (color == Color::White)
		return "r";
	else
		return "R";
}



