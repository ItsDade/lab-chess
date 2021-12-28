// Precompiler options
#pragma once

// Include files
#include "Color.h"
#include "Piece.h"
#include <string>


// Class header
class Empty : public Piece {
public:
	Empty(char y, int x, Color color);
	std::string toString();
	bool isValidMove(char y, int x);
private:

};