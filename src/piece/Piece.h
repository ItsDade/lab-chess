#ifndef PIECE_H
#define PIECE_H

#include <vector>
#include "../board/Board.h"
#include "../color/Color.h"
#include "../square/Square.h"

class Board;

class Piece {
	protected:
		Piece(char symbol, Color color) : movesNumber{0}, symbol{symbol}, color{color} {}
		int movesNumber;
		char symbol;
		Color color;

	public:

		// Evito slicing
		Piece(const Piece&) = delete;
		Piece& operator=(const Piece&) = delete;

		/**
		* Distruttore virtuale.
		*/
		virtual ~Piece() {}

		/**
		* Ritorna le direzioni possibili o le posizioni possibili.
		*
		* @param board Board.
		* @param sourcePosition Posizione di partenza.
		* @return Direzioni o posizioni possibili.
		*/
		virtual std::vector<Square> getDirections(Board* board, const Square& sourcePosition) const = 0;

		/**
		* Ritorna il numvero di mossa effettuate
		* dal pezzo.
		*
		* @return Numero di mosse fatte dal pezzo.
		*/
		int getMovesNumber() const;

		/**
		* Imposta il numero mosse di un pezzo.
		*
		* @param i Numero da impostare.
		* @return Numero di mosse fatte dal pezzo.
		*/
		void setMovesNumber(int i);

		/**
		* Ritorna il simbolo del pezzo.
		* Torre = T
		* Cavallo = C
		* Alfiere = A
		* Regina = D
		* Re = R
		* Pedone = P
		*
		* @return Simbolo del pezzo.
		*/
		char getSymbol() { return symbol; }

		/**
		* Ritorna il colore del pezzo.
		*
		* @return Colore del pezzo.
		*/
		Color getColor() { return color; }
		
		/**
		* Ritorna le posizioni possibili dal pezzo in sourcePosition.
		*
		* @param board Board.
		* @param sourcePosition Posizione di partenza.
		* @param blockedPositions Posizioni bloccate.
		* @return Vettore di posizioni possibili.
		*/
		std::vector<Square> getMoves(Board* board, const  Square& sourcePosition, const Square& blockedPosition = Square{-1, -1}) const;

		/**
		* Ritorna le posizioni possibili dal pezzo in sourcePosition.
		*
		* @param board Board.
		* @return Vettore di posizioni possibili.
		*/
		std::vector<Square> getMoves(Board* board) const;

		/**
		* Esegue una mossa.
		*
		* @param board Board.
		* @param sourcePosition Posizione di partenza.
		* @param targetPosition Posizioni bloccate.
		*/
		void move(Board* board, Square& sourcePosition, Square& targetPosition);
};

#endif // PIECE_H
