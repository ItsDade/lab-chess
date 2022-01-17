#include <algorithm>
#include <vector>
#include "../board/Board.h"
#include "../piece/King.h"
#include "../square/Square.h"
#include "../piece/Rook.h"
#include "../move/Move.h"

bool King::isInCheck(Board* board, const Square& sourcePosition, const Square& targetPosition, const Square& blocked_pos) const {
    // Prendo il pezzo sorgente e il pezzo destinazione
    Piece* sourcePiece = board->getSquarePiece(sourcePosition);
    Piece* targetPiece = board->getSquarePiece(targetPosition);

    if (sourcePosition != targetPosition && dynamic_cast<King*>(targetPiece) != nullptr)
        return true;

    sourcePiece->setMovesNumber(sourcePiece->getMovesNumber() + 1);

    // Al posto del destinazione metto il sorgento e tolgo momentaneamente il sorgente
    board->getSquarePiece(sourcePosition) = nullptr;
    board->getSquarePiece(targetPosition) = sourcePiece;



    Square kingPosition = board->getSquare((Piece*)this);

    bool res = false;
    // Ciclo i pezzi
    for (int y = 0; y < 8 && !res; ++y)
        for (int x = 0; x < 8; ++x)
            if (blocked_pos != Square{ x, y }) {
                Piece* piece = board->getSquarePiece(Square{ x, y });
                // Per ogni pezzo di colore diverso da quello del re
                if (piece != nullptr && piece->getColor() != color) {
                    //Prendo le mosse legali
                    std::vector<Square> legalMoves = piece->getMoves(board, Square{ x, y }, blocked_pos);

                    // Controllo se minacciano il re
                    if (std::find(legalMoves.begin(), legalMoves.end(), kingPosition) != legalMoves.end()) {
                        res =  true;
                    }
                }
            }

    // Ripristino
    // 

    sourcePiece->setMovesNumber(sourcePiece->getMovesNumber() -1);
    board->getSquarePiece(targetPosition) = targetPiece;
    board->getSquarePiece(sourcePosition) = sourcePiece;
    return res;
}

bool King::isInCheck(Board* board) const {
    return isInCheck(board, board->getSquare((Piece*)this), board->getSquare((Piece*)this));
}

std::pair<Square, Square> King::evadeCheck(Board* board, const Square& sourcePosition) const{
    // Prima controllo se può scappare da solo
    for (Square target_pos : getMoves(board, sourcePosition)) {


        if (!isInCheck(board, sourcePosition, target_pos)) {
            // Il re non è piu in scacco, quindi è scappato, ritorno le posizioni di partenza e di arrivo
            return std::pair<Square, Square>{sourcePosition, target_pos};
        }
    }

    // Controllo se qualche mossa legale blocca lo scacco
    // Scorro tutti i pezzi
    for (int y = 0; y < 8; ++y) 
        for (int x = 0; x < 8; ++x) {
            Piece* piece = (*board)[y][x];
            // Se il pezzo è di uguale colore dal re e non è il re
            if (piece != nullptr && piece->getColor() == color && piece != this)
                // Scorro le mosse che il pezzo può fare
                for (Square targetPosition : piece->getMoves(board, Square{ x, y })) 
                    // Se la mossa toglie dallo scacco
                    if (!isInCheck(board, Square{x, y}, targetPosition))
                        // Allora il re non è piu in scacco, ritorno le posizioni di partenza e di arrivo
                        return std::pair<Square, Square>{ Square{x, y}, targetPosition};
            
        }

    // Non può scappare dallo scacco
    return std::pair<Square, Square>{sourcePosition, Square{-1, -1}};
}

bool King::canEvadeCheck(Board* board, const Square& sourcePosition) const {
    return evadeCheck(board, sourcePosition).second != Square{-1, -1};
}

bool King::canEvadeCheck(Board* board) const {
  return canEvadeCheck(board, board->getSquare((Piece*)this));
}

std::vector<Square> King::getDirections(Board* board, const Square& sourcePosition) const {
    std::vector<Square> moves {};

    // Guardo tutte le celle intorno al re
    for(int x = -1; x <= 1; x++)
        for (int y = 0; y <= 1; y++) {
            Square targetPosition = sourcePosition + Square{ x,y };
            Piece* targetPiece = board->getSquarePiece(targetPosition);
            // Se la cella è valida ed è vuota oppure con un pezzo dell'altro giocatore allora la mossa è valida
            if (!(x == 0 && y == 0) && 
                board->isValidSquare(targetPosition) &&
                (targetPiece == nullptr || (targetPiece != nullptr && targetPiece->getColor() != color))) {

                // Per regola i due re non possono essere in celle adiacenti
                bool kingIsNear = false;
                for (int xTarget = -1; xTarget <= 1; xTarget++)
                    for (int yTarget = 0; yTarget <= 1; yTarget++) {
                        Square checkPosition = targetPosition + Square{ x,y };
                        // std::cout << "Checking (" << char(checkPosition.getX() + 'a') << char(checkPosition.getY() + '1') << ")" << std::endl;
                        Piece* checkPiece = board->getSquarePiece(checkPosition);
                        if (board->isValidSquare(checkPosition) && dynamic_cast<King*>(checkPiece) != nullptr) {
                            kingIsNear = true;
                        }
                    }

                if(!kingIsNear)
                    moves.push_back(targetPosition);
            }
        }
    Square kingPosition = board->getSquare((Piece*)this);
    // Se è la prima mossa del re
    if (movesNumber == 0 && (kingPosition.getX() - 4 == 0 || kingPosition.getX() - 3 == 0)) {
    
        // Arrocco corto
        if (dynamic_cast<Rook*>(board->getSquarePiece(kingPosition + Square{ 3, 0 })) != nullptr && // Controllo che ci sia la torre
            board->getSquarePiece(kingPosition + Square{ 1, 0 }) == nullptr && // che la prima cella sia libera
            board->getSquarePiece(kingPosition + Square{ 2, 0 }) == nullptr) // che la seconda cella sia libera
            // Arrocco valido
            moves.push_back(kingPosition + Square{ 2, 0 }); 

        if (dynamic_cast<Rook*>(board->getSquarePiece(kingPosition + Square{ -4, 0 })) != nullptr && // Controllo che ci sia la torre
            board->getSquarePiece(kingPosition + Square{ -1, 0 }) == nullptr && // che la prima cella sia libera
            board->getSquarePiece(kingPosition + Square{ -2, 0 }) == nullptr && // che la seconda cella sia libera
            board->getSquarePiece(kingPosition + Square{ -3, 0 }) == nullptr) // che la terza cella sia libera
            // Arrocco valido
            moves.push_back(kingPosition + Square{ -2, 0 });
    
    }


    return moves;
}
