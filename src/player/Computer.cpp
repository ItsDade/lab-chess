#include "Computer.h"
#include "../piece/Pawn.h"
#include <time.h>

std::string Computer::takeInput() {
	// Prendo i pezzi del colore del giocatore
	std::vector<Piece*> pieces = game->getTeamPieces(color);

	// Array per promozione random
	char promotionLetters[] = { 'C', 'A', 'T', 'D' };

	// Variabili che serviranno nel loop sotto
	Piece* randomPiece;
	Square sourcePosition;
	Square targetPosition;

	// Trovo il re
	King* king = game->getBoard()->getKings()[color];
	// e la sua posizione
	Square kingPos = game->getBoard()->getSquare(king);


	std::string res = "";
	do {
		res = "";
		if (king->isInCheck(game->getBoard(), kingPos, kingPos) && king->canEvadeCheck(game->getBoard(), kingPos)) {
			// Il re è in scacco, se può scappare allora scelgo quella mossa
			std::pair<Square, Square> p = king->evadeCheck(game->getBoard(), kingPos);
			sourcePosition = p.first;
			targetPosition = p.second;
			randomPiece = king;
		} else {

			// Mossa a caso
			std::vector<Square> legalMoves;
			do {
				// Prendo un pezzo a caso
				randomPiece = pieces[rand() % pieces.size()];
				// Trovo la sua posizione
				sourcePosition = game->getBoard()->getSquare(randomPiece);
				// Prendo le sue mosse possibili
				legalMoves = randomPiece->getMoves(game->getBoard(), sourcePosition);

				// Se non ha mosse possibili, prendo un altro pezzo
			} while (legalMoves.size() == 0);

			targetPosition = legalMoves[rand() % legalMoves.size()];
		}

		// Costruisco la mossa come stringa
		res += char(sourcePosition.getX() + 'a');
		res += char(sourcePosition.getY() + '1');
		res += " ";
		res += char(targetPosition.getX() + 'a');
		res += char(targetPosition.getY() + '1');
	} while (!game->getBoard()->isValidSquare(sourcePosition) || 
		!game->getBoard()->isValidSquare(targetPosition) || 
		king->isInCheck(game->getBoard(), sourcePosition, targetPosition));


	// Se il pezzo selezionato è un pedone che va in promozione devo aggiungere un pezzo a caso
	if (dynamic_cast<Pawn*>(randomPiece) != nullptr && 
		((randomPiece->getColor() == Color::WHITE && sourcePosition.getY() == 6 && targetPosition.getY() == 7) || 
			(randomPiece->getColor() == Color::BLACK && sourcePosition.getY() == 1 && targetPosition.getY() == 0))) {
		res += " ";
		res += promotionLetters[rand() % 4];
	}
	return res;
}
