// Precompiler options
#pragma once

// Include files
#include "Color.h"
#include "Piece.h"
#include <string>


// Class header
class Cavallo : public Piece {
public:
	Cavallo(char y, int x, Color color);
	std::string toString();
	bool isValidMove(char y, int x);
private:

};