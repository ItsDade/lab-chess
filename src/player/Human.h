#ifndef HUMAN_H
#define HUMAN_H
#include "Player.h"

class Human : public Player {
public:

	/**
	* Costruisce un player umano.
	*
	* @param c Colore del giocatore.
	* @param g Istanza della partita.
	* @return Nuovo giocatore (umano).
	*/
	Human(Color c, Game* g) : Player(c, g) {}

	/**
	* Gestici l'input del giocatore.
	*
	* @return Stringa nel formato (esempio) "d1 d2".
	*/
	std::string takeInput();
};

#endif