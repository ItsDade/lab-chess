#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <map>
#include "../color/Color.h"
#include "../piece/Piece.h"
#include "../square/Square.h"

class King;

class Board {
private:
	Piece* board[8][8];
	std::map<Color, King*> kings;

public:
	/**
	* Costruisce una nuova board.
	*
	* @return Nuova board.
	*/
	Board();

	~Board();

	/**
	* Ritorna il pezzo contenuto nella board
	* alla posizione pos
	* 
	* @param pos Posizione in cui cercare.
	* @return Puntatore al pezzo se trovato, nullptr altrimenti.
	*/
	Piece*& getSquarePiece(const Square& pos);

	/**
	* Ritorna lo Square in cui è presente il pezzo piece.
	* 
	* @param piece Pezzo da cercare.
	* @return Square contenente piece.
	*/
	Square getSquare(Piece* piece);

	/**
	* Controlla che pos sia uno Square valido nella board.
	*
	* @param pos Posizione da controllare.
	* @return true se valido, false altrimenti.
	*/
	bool isValidSquare(Square& pos);

	/**
	* Esegue uno spostamento da sourcePosition a targetPosition.
	*
	* @param sourcePosition Posizione di partenza.
	* @param targetPosition Posizione di arrivo.
	*/
	void move(Square& sourcePosition, Square& targetPosition);

	/**
	* Permette di cambiare un pezzo della scacchiera con un altro.
	*
	* @param sourcePosition Posizione di partenza.
	* @param targetPosition Posizione di arrivo.
	* @param newPiece Nuovo pezzo da inserire.
	*/
	void swapPieces(Square& sourcePosition, Square& targetPosition, Piece* newPiece);

	/**
	* Ritorna la mappa contenente i re.
	*
	* @return Mappa contenente i re.
	*/
	std::map<Color, King*> getKings() const;

	/**
	* Ritorna la board rappresentata come stringa.
	*
	* @return Board come stringa.
	*/
	std::string toString() const;

	/**
	* Operatore subscript, utilizzato per accedere a board[][].
	*
	* @param y Indice.
	* @return Puntatore al pezzo puntato se trovato, nullptr altrimenti.
	*/
	Piece* const* operator[](int y) const { return board[y]; }
};

/**
* Operatore insert formatted output, utilizzato per stampare la board.
*
* @param os Output stream.
* @return board Board.
*/
std::ostream& operator<<(std::ostream& os, const Board* board);

#endif // BOARD_H
