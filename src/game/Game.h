#ifndef GAME_H
#define GAME_H

#include <iostream>
#include "../board/Board.h"
#include "../color/Color.h"
#include "../move/Move.h"

class Game {
private:
	Board* board;

	Color turn;
	Color winner;

	bool finish;
	bool turnColorInCheck;

	int maxMoves;
	int movesCounter;

	std::vector<Move> history;

public:

	/**
	* Inizializza una nuova partita.
	*
	* @return Nuova partita.
	*/
	Game();

	/**
	* Inizializza una nuova partita.
	*
	* @param mm Numero di mosse massime.
	* @return Nuova partita.
	*/
	Game(int mm);

	/**
	* Distruttore
	*/
	~Game();

	/**
	* Ritorna il colore di chi deve muovere.
	*
	* @return Colore di chi deve muovere.
	*/
	Color getTurn() const { return turn; }

	/**
	* Ritorna il vincitore.
	*
	* @return Vincitore.
	*/
	Color getWinner() const { return isFinished() ? winner : Color::NONE; }

	/**
	* Ritorna la board rispettiva alla partita.
	*
	* @return Board.
	*/
	Board* getBoard() const { return board; }

	/**
	* Ritorna se il giocatore è in scacco.
	*
	* @return true se il giocatore è in scacco, false altrimenti.
	*/
	bool isPlayerInCheck() const { return turnColorInCheck; }

	/**
	* Ritorna se la partita è finita.
	*
	* @return true se la partita è finita, false altrimenti.
	*/
	bool isFinished() const { return (maxMoves > 0 && movesCounter >= maxMoves) || finish; }

	/**
	* Gestisce un turno.
	*
	* @param move Mossa da fare.
	* @return true se turno valido, false altrimenti.
	*/
	bool takeTurn(Move movement);

	/**
	* Prende tutti i pezzi di un giocatore.
	*
	* @param c Colore del giocatore.
	* @return Vettore di pezzi del colore specificato.
	*/
	std::vector<Piece*> getTeamPieces(Color c);

	/**
	* Prende tutte le mosse esguite fino a quel punto nella partita.
	*
	* @return Vettore di mosse.
	*/
	std::vector<Move> getHistory() { return history; }

	/**
	* Operatore insert formatted output, utilizzato per stampare la board.
	*
	* @param os Output stream.
	* @param game Partita.
	* @return Output stream.
	*/
	friend std::ostream& operator<<(std::ostream& os, const Game& game);
};


#endif // GAME_H
