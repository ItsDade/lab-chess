#include "../headers/Cavallo.h"

Cavallo::Cavallo(char y, int x, Color color) : Piece(y, x, color) {
}

std::string Cavallo::toString() {
	if (color == Color::Black)
		return "C";
	else
		return "c";
}

bool Cavallo::isValidMove(char y, int x) {
	return false;
}
