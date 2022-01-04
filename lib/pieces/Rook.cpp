#include "Rook.h"
#include "../board/Board.h"
#include "../board/Square.h"

// Constructors
Rook::Rook(Color c) : Piece(c) {}

// Functions
bool Rook::canMove(Board* b, Square* i, Square* f) {
	return false;
}

std::string Rook::toString() {
	if (color == Color::White)
		return "t";
	else
		return "T";
}



