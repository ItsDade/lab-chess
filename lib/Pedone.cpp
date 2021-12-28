#include "Pedone.h"

Pedone::Pedone(char y, int x, Color color) : Piece(y, x, color) {
}

std::string Pedone::toString(){
	if (color == Color::Black)
		return "P";
	else
		return "p";
}

bool Pedone::isValidMove(char y, int x) {
	if (firstMove) {


	
		firstMove = false;
	}
}
