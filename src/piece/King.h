#ifndef KING_H
#define KING_H

#include "../board/Board.h"
#include "../color/Color.h"
#include "../square/Square.h"
#include "../piece/Queen.h"
#include "../move/Move.h"

class King : public Queen {
public:
	/**
	* Costruisce un pezzo di tipo Re.
	*
	* @param color Colore del pezzo.
	* @return Nuovo re.
	*/
	King(Color color) : Piece{'R', color}, Queen{color} {}


	/**
	* Ritorna se il re è in scacco.
	*
	* @param board Board.
	* @param sourcePosition Posizione di partenza.
	* @param blockedPositions Posizioni da evitare nel controllo.
	* @return true se il re è in scacco, false altrimenti.
	*/
	bool isInCheck(Board* board, const Square& sourcePosition, const Square& targetPosition, const Square& blocked_pos = Square{-1, -1}) const;

	/**
	* Ritorna se il re può scappare dallo scacco.
	*
	* @param board Board.
	* @param sourcePosition Posizione di partenza.
	* @return true se il re può scappare dallo scacco, false altrimenti.
	*/
	bool canEvadeCheck(Board* board, const Square& sourcePosition) const;

	/**
	* Ritorna se il re è in scacco.
	*
	* @param board Board.
	* @return true se il re è in scacco, false altrimenti.
	*/
	bool isInCheck(Board* board) const;

	/**
	* Ritorna se il re può scappare dallo scacco.
	*
	* @param board Board.
	* @return true se il re può scappare dallo scacco, false altrimenti.
	*/
	bool canEvadeCheck(Board* board) const;

	/**
	* Ritorna due Square (parenza e posizione) della mossa che il re
	* dovrebbe fare per scappare dallo scacco.
	*
	* @param board Board.
	* @param sourcePosition Posizione di partenza.
	* @return pair<partenza, arrivo> se può scappare, pair<partenza, NULL> altrimenti.
	*/
	std::pair<Square, Square> evadeCheck(Board* board, const Square& sourcePosition) const;

	/**
	* Ritorna le direzioni possibili o le posizioni possibili.
	*
	* @param board Board.
	* @param sourcePosition Posizione di partenza.
	* @return Direzioni o posizioni possibili.
	*/
	std::vector<Square> getDirections(Board* board, const Square& sourcePosition) const override;
};

#endif // KING_H
