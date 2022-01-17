#ifndef QUEEN_H
#define QUEEN_H

#include <vector>
#include "bishop.h"
#include "../board/Board.h"
#include "../color/Color.h"
#include "../piece/Piece.h"
#include "../square/Square.h"
#include "../piece/Rook.h"

class Queen : public Rook, public Bishop {
public:
	/**
	* Costruisce un pezzo di tipo Regina.
	*
	* @param color Colore del pezzo.
	* @return Nuova regina.
	*/
	Queen(Color color) : Piece{'D', color}, Rook{color}, Bishop{color} {}

	/**
	* Ritorna le direzioni possibili o le posizioni possibili.
	*
	* @param board Board.
	* @param sourcePosition Posizione di partenza.
	* @return Direzioni o posizioni possibili.
	*/
	std::vector<Square> getDirections(Board* board, const Square& sourcePosition) const override;
};

#endif // QUEEN_H
