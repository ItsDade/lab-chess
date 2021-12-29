// Include guards
#ifndef EMPTY_H
#define EMPTY_H

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

#endif // !EMPTY_H