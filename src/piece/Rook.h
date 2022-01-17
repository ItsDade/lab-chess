#ifndef ROOK_H
#define ROOK_H

#include <vector>
#include "../board/Board.h"
#include "../color/Color.h"
#include "../piece/Piece.h"
#include "../square/Square.h"

class Rook : virtual public Piece {
private:
	static std::vector<Square> directions;

public:
	/**
	* Costruisce un pezzo di tipo Torre.
	*
	* @param color Colore del pezzo.
	* @return Nuova torre.
	*/
	Rook(Color color) : Piece{'T', color} {}

	/**
	* Ritorna le direzioni possibili o le posizioni possibili.
	*
	* @param board Board.
	* @param sourcePosition Posizione di partenza.
	* @return Direzioni o posizioni possibili.
	*/
	std::vector<Square> getDirections(Board* board, const Square& sourcePosition) const override;
};

#endif // ROOK_H
