#include "Knight.h"
#include "../board/Board.h"
#include "../board/Square.h"

// Constructors
Knight::Knight(Color c) : Piece(c) {}

// Functions
bool Knight::canMove(Board* b, Square* i, Square* f) {
	return false;
}

std::string Knight::toString() {
	if (color == Color::White)
		return "c";
	else
		return "C";
}


