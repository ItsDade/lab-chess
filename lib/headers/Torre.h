// Include guards
#ifndef TORRE_H
#define TORRE_H

// Include files
#include "Color.h"
#include "Piece.h"
#include <string>


// Class header
class Torre : public Piece {
public:
	Torre(char y, int x, Color color);
	std::string toString();
	bool isValidMove(char y, int x);
private:

};

#endif // !TORRE_H