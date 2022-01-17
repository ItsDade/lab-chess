#ifndef COMPUTER_H
#define COMPUTER_H
#include "Player.h"
#include "../piece/King.h"

class Computer : public Player {
public:
	/**
	* Costruisce un player computer.
	*
	* @param c Colore del giocatore.
	* @param g Istanza della partita.
	* @return Nuovo giocatore (computer).
	*/
	Computer(Color c, Game* g) : Player(c, g) {}

	/**
	* Gestici l'input del giocatore.
	*
	* @return Stringa nel formato (esempio) "d1 d2".
	*/
	std::string takeInput();
};

#endif