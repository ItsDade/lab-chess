#ifndef PAWN_H
#define PAWN_H

#include <vector>
#include "../board/Board.h"
#include "../color/Color.h"
#include "../piece/Piece.h"
#include "../square/Square.h"
#include "../piece/King.h"

class Pawn : public Piece {
public:
	/**
	* Costruisce un pezzo di tipo Pedone.
	*
	* @param color Colore del pezzo.
	* @return Nuovo pedone.
	*/
	Pawn(Color color) : Piece('P', color) {}

	/**
	* Ritorna le direzioni possibili o le posizioni possibili.
	*
	* @param board Board.
	* @param sourcePosition Posizione di partenza.
	* @return Direzioni o posizioni possibili.
	*/
	std::vector<Square> getDirections(Board* board, const Square& sourcePosition) const override;
};

#endif // PAWN_H
