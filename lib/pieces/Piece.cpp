#include "Piece.h"

// Constructor
Piece::Piece(Color c){
	color = c;
}

// Getter
bool Piece::isAlive() {
	return alive;
}

Color Piece::getColor(){
	return color;
}

// Setter
void Piece::setAlive(bool a) {
	alive = a;
}