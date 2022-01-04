#include "Pawn.h"
#include "../board/Board.h"
#include "../board/Square.h"

// Constructors
Pawn::Pawn(Color c) : Piece(c) {}

// Functions
bool Pawn::canMove(Board* b, Square* i, Square* f){
	return false;
}

std::string Pawn::toString() {
	if (color == Color::White)
		return "p";
	else
		return "P";
}
