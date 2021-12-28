#include "Alfiere.h"

Alfiere::Alfiere(char y, int x, Color color) : Piece(y, x, color) {
}

std::string Alfiere::toString() {
	if (color == Color::Black)
		return "A";
	else
		return "a";
}

bool Alfiere::isValidMove(char y, int x) {
	return false;
}
