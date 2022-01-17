#include <algorithm>
#include <cctype>
#include <memory>
#include <regex>
#include <stdexcept>
#include <string>
#include "../color/Color.h"
#include "../game/Game.h"
#include "../move/Move.h"
#include "../piece/Piece.h"
#include "../square/Square.h"
#include "../piece/Pawn.h"

Move::Move(std::string input) : sourcePosition{nullptr}, targetPosition{nullptr}, sourcePiece{'P'}, promotionPiece{'\0'} {
    // Controllo la validità di una mossa tramite regex
    // E' formata da due gruppi:
    // ([a-h][1-8] [a-h][1-8]) controlla che la stringa sia in formato "d1 d2"
    // ( [CATD]) in caso di promozione serve specificare il tipo di pezzo voluto
    std::regex movement_regex{"([a-h][1-8] [a-h][1-8])( [CATD])?", std::regex_constants::icase};
    std::smatch matches;

    if (std::regex_match(input, matches, movement_regex)) {

        // Mossa normale
        std::string positions = matches[1];
        if (positions.length() == 5) {
            sourcePosition = std::unique_ptr<Square>{new Square{positions.substr(0, 2)}};
            targetPosition = std::unique_ptr<Square>{new Square{positions.substr(3, 2)}};
        }

        // Promozione
        if (matches[2].length() > 0) 
            promotionPiece = toupper(std::string{matches[2]}[1]);

    }
    else
        // Se non matcha la regex la mossa non è valida.
        throw std::runtime_error("Mossa non valida.");


}

Move::Move(const Move& move){
    sourcePosition = move.sourcePosition;
    targetPosition = move.targetPosition;
    sourcePiece = move.sourcePiece;
    promotionPiece = move.promotionPiece;
}

Square Move::getSourcePosition(Game* game) const {
    if (sourcePosition != nullptr) {
        // Controllo che la posizione sia valida
        if (!game->getBoard()->isValidSquare(*sourcePosition) || game->getBoard()->getSquarePiece(*sourcePosition) == nullptr)
            throw std::runtime_error("Posizione di partenza non valida.");

        return *sourcePosition;
    }

    throw std::runtime_error("Impossibile trovare posizione di partenza.");
}

Square Move::getTargetPosition(Game* game) const {
    if (targetPosition != nullptr) {
        bool val = promotionPiece != '\0' && targetPosition->getY() != 0 && targetPosition->getY() != 7;
        
        // Controllo che la posizone sia valida
        if (!game->getBoard()->isValidSquare(*targetPosition))
            throw std::runtime_error("Posizione di arrivo non valida.");

        // Se è una mossa di promozione ma senza mossa valida (Senza il pezzo voluto)
        if (dynamic_cast<Pawn*>(game->getBoard()->getSquarePiece(*sourcePosition)) != nullptr && ((game->getTurn() == Color::BLACK && targetPosition->getY() == 0) || (game->getTurn() == Color::WHITE && targetPosition->getY() == 7)))
            if (promotionPiece == '\0') 
                throw std::runtime_error("Il pedone va' promosso.");
      
        // Cercato di fare una promozione quando non si può
        if (val) 
            throw std::runtime_error("Non puoi promuovere questo pezzo ora.");
   

        return *targetPosition;
    }

    // targetPosition = nullptr quindi è errore
    throw std::runtime_error("Posizione di arrivo non trovata.");
}

std::ostream& operator<<(std::ostream& os, const Move& m){
    os << char(m.sourcePosition->getX() + 'a') << char(m.sourcePosition->getY() + '1') << " " <<
        char(m.targetPosition->getX() + 'a') << char(m.targetPosition->getY() + '1') << (m.promotionPiece != '\0' ? " " + std::string(1, m.promotionPiece) : "") << std::endl;
    return os;
}
