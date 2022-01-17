#ifndef MOVE_H
#define MOVE_H

#include <memory>
#include <string>
#include "../square/Square.h"

class Game;

class Move {
private:

	std::shared_ptr<Square> sourcePosition;
	std::shared_ptr<Square> targetPosition;

	char sourcePiece;
	char promotionPiece;

public:
	/**
	* Costruisce una mossa.
	*
	* @param input Mossa nel formato (esempio) "d1 d2).
	* @return Nuova mossa.
	*/
	Move(std::string input);

	/**
	* Costruisce una mossa da un'altra.
	*
	* @param move Mossa da copiare.
	* @return Nuova mossa.
	*/
	Move(const Move& move);

	/**
	* Ritorna la posizione di partenza della mossa.
	*
	* @param game Reference alla partita.
	* @return Posizione di partenza della mossa.
	*/
	Square getSourcePosition(Game* game) const;

	/**
	* Ritorna la posizione di arrivo della mossa.
	*
	* @param game Reference alla partita.
	* @return Posizione di arrivo della mossa.
	*/
	Square getTargetPosition(Game* game) const;

	/**
	* Ritorna il simbolo del pezzo di promozione.
	*
	* @return Simbolo del pezzo voluto per promozione.
	*/
	char getPromotedPiece() const { return promotionPiece; }

	/**
	* Operatore insert formatted output, utilizzato per stampare la mossa.
	*
	* @param os Output stream.
	* @param mossa Mossa.
	* @return Output stream.
	*/
	friend std::ostream& operator<<(std::ostream& os, const Move& mossa);
};



#endif // MOVEMENT_H
