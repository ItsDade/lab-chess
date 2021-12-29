// Include guards
#ifndef RE_H
#define RE_H

// Include files
#include "Color.h"
#include "Piece.h"
#include <string>


// Class header
class Re : public Piece {
public:
	Re(char y, int x, Color color);
	std::string toString();
	bool isValidMove(char y, int x);
private:

};

#endif // !RE_H