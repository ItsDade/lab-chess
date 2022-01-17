#ifndef KNIGHT_H
#define KNIGHT_H

#include <vector>
#include "../board/Board.h"
#include "../color/Color.h"
#include "../piece/Piece.h"
#include "../square/Square.h"

class Knight : public Piece {
private:
	static std::vector<Square> directions;

public:
	/**
	* Costruisce un pezzo di tipo Cavallo.
	*
	* @param color Colore del pezzo.
	* @return Nuovo cavallo.
	*/
	Knight(Color color) : Piece{'C', color} {}

	/**
	* Ritorna le direzioni possibili o le posizioni possibili.
	*
	* @param board Board.
	* @param sourcePosition Posizione di partenza.
	* @return Direzioni o posizioni possibili.
	*/
	std::vector<Square> getDirections(Board* board, const Square& sourcePosition) const override;
};

#endif // KNIGHT_H
