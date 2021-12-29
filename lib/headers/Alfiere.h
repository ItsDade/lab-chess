// Include guards
#ifndef ALFIERE_H
#define ALFIERE_H

// Include files
#include "Color.h"
#include "Piece.h"
#include <string>


// Class header
class Alfiere : public Piece {
public:
	Alfiere(char y, int x, Color color);
	std::string toString();
	bool isValidMove(char y, int x);
private:

};

#endif // !ALFIERE_H