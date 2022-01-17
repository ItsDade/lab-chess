#include <string>
#include "../color/Color.h"
#include "../game/Game.h"
#ifndef PLAYER_H
#define PLAYER_H

class Player {
public:

	/**
	* Costruisce un nuovo giocatore generico.
	*
	* @param c Colore del giocatore.
	* @param g Istanza della partita.
	* @return Nuovo giocatore.
	*/
	Player(Color c, Game* g);

	/**
	* Gestici l'input del giocatore.
	*
	* @return Stringa nel formato (esempio) "d1 d2".
	*/
	virtual std::string takeInput() = 0;

	/**
	* Ritorna il colore del giocatore.
	*
	* @return Colore del giocatore.
	*/
	Color getColor();

protected:
	Color color;
	Game* game;
};

#endif