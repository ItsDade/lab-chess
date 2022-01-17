#include "../piece/Bishop.h"
#include "../color/Color.h"
#include "../game/Game.h"
#include "../piece/King.h"
#include "../piece/Knight.h"
#include "../move/Move.h"
#include "../piece/Piece.h"
#include "../piece/Queen.h"
#include "../piece/Rook.h"

// Costruttore
Game::Game() : turn{ Color::WHITE }, turnColorInCheck{ false }, finish{ false }, maxMoves{ -1 }, movesCounter{ 0 }, winner{ Color::NONE } {
    board = new Board();
}

// Costruttore con mosse massime
Game::Game(int mm) : Game() {
    maxMoves = mm;
}

Game::~Game() {
    delete board;
}

std::vector<Piece*> Game::getTeamPieces(Color c){
    std::vector<Piece*> pieces{};
    // Scorro i pezzi
    for (int y = 7; y >= 0; y--) {
        for (int x = 0; x < 8; x++) {
            Piece* piece = (*board)[y][x];
            // Se il colore del pezzp è uguale a quello cercato
            if (piece != nullptr && piece->getColor() == c)
                // Lo aggiungo
                pieces.push_back(piece);
        }
    }

    return pieces;
}

bool Game::takeTurn(Move movement) {
    Square sourcePosition = movement.getSourcePosition(this);
    Square targetPosition = movement.getTargetPosition(this);
    King* turnKing = board->getKings()[turn];

    bool b1 = turnKing->isInCheck(board, sourcePosition, targetPosition);

    bool b2 = turnKing->isInCheck(board, board->getSquare(turnKing), board->getSquare(turnKing), sourcePosition);

    bool b3 = turnKing->isInCheck(board, board->getSquare(turnKing), board->getSquare(turnKing), targetPosition);

    if (board->getSquarePiece(sourcePosition)->getSymbol() == 'R' ? b1 : b2 && b3)
        throw std::runtime_error("Non puoi fare questa mossa perchè mette in scacco il re.");

    // Se è una mossa normale
    if (movement.getPromotedPiece() == '\0') {
        // Controllo che il giocatore ha mosso un pezzo suo
        if (board->getSquarePiece(sourcePosition)->getColor() != turn )
            return false;
        // Eseguo la mossa
        board->move(sourcePosition, targetPosition);
    } else {
        // Promozione
        Piece* target_piece;
        switch (movement.getPromotedPiece()) {
            case 'C':
            target_piece = new Knight{turn};
            break;

            case 'A':
            target_piece = new Bishop{turn};
            break;

            case 'T':
            target_piece = new Rook{turn};
            break;

            case 'D':
            target_piece = new Queen{turn};
            break;

            default:
            target_piece = nullptr;
        }

       // Scampio
        board->swapPieces(sourcePosition, targetPosition, target_piece);
    }

    // Aggiungo la mossa alla history
    history.push_back(movement);

    // Aumento il contatore di mosse
    movesCounter++;

    // Cambio turno
    Color prevTurn = turn;
    turn = turn == Color::WHITE ? Color::BLACK : Color::WHITE;

    // Controllo se il re è in scacco
    turnKing = board->getKings()[turn];
    turnColorInCheck = turnKing->isInCheck(board);

    // Controllo se è finita la partita per scacco
    if (turnColorInCheck && !turnKing->canEvadeCheck(board)) {
        winner = prevTurn;
        finish = true;
    }
    return true;
}

std::ostream& operator<<(std::ostream& os, const Game& game) {
  os << game.board->toString();
  return os;
}
