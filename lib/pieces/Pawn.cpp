#include "Pawn.h"

Pawn::Pawn(char c, int r, Color co) : Piece(c, r, co) {}

bool Pawn::isValidMove(char y, int x)
{
	return true;
}

std::string Pawn::toString(){
	if (color == Color::Black)
		return "P";
	else
		return "p";
}
