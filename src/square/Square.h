#ifndef SQUARE_H
#define SQUARE_H

#include <string>

class Square {
private:
	int x;
	int y;

public:
	/**
	* Costruisce una posizione.
	*
	* @param x Coordinata x.
	* @param y Coordinata y.
	* @return Nuova posizione.
	*/
	Square(int x = 0, int y = 0) : x{ x }, y{ y } {}

	/**
	* Costruisce una posizione partendo da una stringa in formato "d1 d2".
	*
	* @param input Stringa in formato "d1 d2".
	* @return Nuova posizione.
	*/
	Square(std::string input);

	/**
	* Ritorna la coordinata x della posizione.
	*
	* @return Coordinata x.
	*/
	int getX() const;

	/**
	* Ritorna la coordinata y della posizione.
	*
	* @return Coordinata y.
	*/
	int getY() const;
};

/**
* Operatore +, utilizzato per sommare due posizioni.
*
* @param leftOperator Posizione di sinistra.
* @param rightOperator Posizione di destra.
* @return Posizione somma.
*/
Square operator+(Square leftOperator, Square rightOperator);

/**
* Operatore ==, utilizzato per confrontare due posizioni.
*
* @param leftOperator Posizione di sinistra.
* @param rightOperator Posizione di destra.
* @return true se uguali, false altrimenti.
*/
bool operator==(const Square& leftOperator, const Square& rightOperator);

/**
* Operatore !=, utilizzato per confrontare due posizioni.
*
* @param leftOperator Posizione di sinistra.
* @param rightOperator Posizione di destra.
* @return true se diversi, false altrimenti.
*/
bool operator!=(const Square& leftOperator, const Square& rightOperator);

#endif // SQUARE_H
