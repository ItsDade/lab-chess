#include <vector>
#include "../board/Board.h"
#include "../color/Color.h"
#include "../piece/Pawn.h"
#include "../piece/Piece.h"
#include "../square/Square.h"

std::vector<Square> Pawn::getDirections(Board* board, const Square& sourcePosition) const {
    std::vector<Square> result;
    int upOrDown = color == Color::WHITE ? 1 : -1;

    // Controllo il pezzo davanti al pedone
    Square targetPosition = sourcePosition + Square{0, upOrDown};
    Piece* targetPiece = board->getSquarePiece(targetPosition);
    // Se è libero, lo aggiungo alle possibili mosse
    if (targetPiece == nullptr) {
        result.push_back(targetPosition);
    }

    // Controllo se il pedone può mangiare a destra o a sinsitra
    for (int leftOrRight = -1; leftOrRight <= 1; leftOrRight += 2) {
        Square targetPosition = Square{leftOrRight, upOrDown};
        targetPosition = sourcePosition + targetPosition;
        targetPiece = board->getSquarePiece(targetPosition);
        // Se c'è un pezzo target ed è dell'altro giocatore aggiungo alle mosse valide
        if (board->isValidSquare(targetPosition) && targetPiece != nullptr && targetPiece->getColor() != color)
            result.push_back(targetPosition);
    }

    // Controllo se il pedone può fare l'en-passant
    Piece* sourcePiece = board->getSquarePiece(sourcePosition);
    if ((sourcePosition.getY() == 4 && sourcePiece->getColor() == Color::WHITE) || (sourcePosition.getY() == 3 && sourcePiece->getColor() == Color::BLACK) && targetPiece == nullptr) {
        for (int leftOrRight = -1; leftOrRight <= 1; leftOrRight += 2) {
            Square targetPosition = Square{ leftOrRight, upOrDown };
            targetPosition = sourcePosition + targetPosition;
            targetPiece = board->getSquarePiece(targetPosition + Square{ 0, -upOrDown });
            // Se sono in 4/5 traversa e c'è un pezzo di fianco ed è dell'altro giocatore aggiungo alle mosse valide
            if (board->isValidSquare(targetPosition) && targetPiece != nullptr && targetPiece->getColor() != color && dynamic_cast<Pawn*>(targetPiece) != nullptr && targetPiece->getMovesNumber() == 1)
                result.push_back(targetPosition);
        }
    }

    // Se è la prima mossa, il pedone può avanzare di 2 ma solo se la strade è libera
    if (getMovesNumber() == 0) {
        targetPosition = sourcePosition + Square{ 0, 2 * upOrDown};
        targetPiece = board->getSquarePiece(targetPosition);
        Square targetPosition1 = sourcePosition + Square{ 0, upOrDown };
        Piece* targetPiece1 = board->getSquarePiece(targetPosition1);
        if (targetPiece == nullptr && targetPiece1 == nullptr)
            result.push_back(targetPosition);
    } 
    return result;
}
