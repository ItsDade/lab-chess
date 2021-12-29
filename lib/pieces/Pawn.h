#ifndef PAWN_H
#define PAWN_H

#include "Piece.h"
#include "../Color/Color.h"

class Pawn : public Piece {
public:
	Pawn(char c, int r, Color co);
	bool isValidMove(char y, int x);
	std::string toString();
};


#endif // !PAWN_H
