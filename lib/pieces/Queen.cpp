#include "Queen.h"
#include "../board/Board.h"
#include "../board/Square.h"

// Constructors
Queen::Queen(Color c) : Piece(c) {}

// Functions
bool Queen::canMove(Board* b, Square* i, Square* f) {
	return false;
}

std::string Queen::toString() {
	if (color == Color::White)
		return "d";
	else
		return "D";
}

