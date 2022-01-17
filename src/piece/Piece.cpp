#include <algorithm>
#include <stdexcept>
#include <vector>
#include "../board/Board.h"
#include "../color/Color.h"
#include "../piece/Piece.h"
#include "../square/Square.h"
#include "Pawn.h"
#include "King.h"
#include "Knight.h"

int Piece::getMovesNumber() const {
    return movesNumber;
}

void Piece::setMovesNumber(int i){
    movesNumber = i;
}

std::vector<Square> Piece::getMoves(Board* board, const Square& sourcePosition, const Square& blocked_pos) const {
    std::vector<Square> result;
    // Scorro le direzioni
    for (Square direction : getDirections(board, sourcePosition)) {
        // Prendo il pezzo sorgente
        Piece* sourcePiece = board->getSquarePiece(sourcePosition);

        // Se è un pedone, un re o un cavallo lo gestisco in modo diverso
        if (dynamic_cast<Pawn*>(sourcePiece) != nullptr || dynamic_cast<King*>(sourcePiece) != nullptr || dynamic_cast<Knight*>(sourcePiece) != nullptr) 
            result.push_back(direction);
        else {
            // Calcolo tutte le celle possibili
            for (Square targetPosition = sourcePosition + direction; 
                board->isValidSquare(targetPosition) && targetPosition != blocked_pos;
                targetPosition = targetPosition + direction) {
                Piece* targetPiece = board->getSquarePiece(targetPosition);

                // Se la posizione di arrivo è occupata da un pezzo dello stesso giocatore
                if (targetPiece != nullptr && targetPiece->getColor() == color) break;

                result.push_back(targetPosition);

                if (targetPiece != nullptr) break;

            }
        }
    }

    return result;
}

std::vector<Square> Piece::getMoves(Board* board) const {
    return getMoves(board, board->getSquare((Piece*)this));
}

void Piece::move(Board* board, Square& sourcePosition, Square& targetPosition) {
    std::vector<Square> legalMoves = getMoves(board, sourcePosition);

    // Controllo che la targetPosition sia legale (Controllo che sia compresa dentro a legalMoves)
    if (std::find(legalMoves.begin(), legalMoves.end(), targetPosition) == legalMoves.end())
        throw std::runtime_error("Impossibile muovere il pezzo nella posizione data.");

    // Pezzo mosso, aumento il numero di mosse
    movesNumber += 1;
}
