#include <cctype>
#include <cmath>
#include <iostream>
#include <map>
#include "../piece/Bishop.h"
#include "../board/Board.h"
#include "../color/Color.h"
#include "../piece/King.h"
#include "../piece/Knight.h"
#include "../piece/Pawn.h"
#include "../piece/Piece.h"
#include "../square/Square.h"
#include "../piece/Queen.h"
#include "../piece/Rook.h"

// board{{nullptr}} serve a inizializzare tutto a nullptr
Board::Board() : board{{nullptr}} {
    int y = 0;
    
    // for che va due volte, prima per i pezzi bianchi, poi per i pezzi neri
    for (int i = 0; i < 2; i++) {
        // Prendo il colore
        Color color = (Color)i;

        // Creo i pezzi
        board[y][0] = new Rook{ color };
        board[y][1] = new Knight{ color };
        board[y][2] = new Bishop{ color };
        board[y][3] = new Queen{color};

        // Creo il re e lo aggiungo alla mappa
        King* king = new King{color};
        board[y][4] = king;
        kings[color] = king;

        board[y][5] = new Bishop{ color };
        board[y][6] = new Knight{ color };
        board[y][7] = new Rook{ color };

        // Prendo la y dei pedoni in base al colore
        y += color == Color::WHITE ? 1 : -1;

        // Creo i pedoni
        for (int x = 0; x < 8; ++x) 
            board[y][x] = new Pawn{color};

        y = 7;
    }
}

Board::~Board() {
    for (int y = 0; y < 8; y++)
        for (int x = 0; x < 8; x++)
            delete board[y][x];
}

std::map<Color, King*> Board::getKings() const { 
    return kings;
}

Piece*& Board::getSquarePiece(const Square& pos){
    return board[pos.getY()][pos.getX()];
}

bool Board::isValidSquare(Square& pos) {
    return pos.getX() >= 0 && pos.getY() >= 0 && pos.getX() < 8 && pos.getY() < 8;
}

Square Board::getSquare(Piece* piece) {
    // Ciclo i pezzi
    for (int y = 0; y < 8; y++) 
        for (int x = 0; x < 8; x++) 
            // Se è uguale ritorno la posizione
            if (board[y][x] == piece) 
                return Square {x, y};
      
    // Pezzo non trovato, errore
    throw std::runtime_error("Pezzo non trovato sulla scacchiera.");
}

void Board::move(Square& sourcePosition, Square& targetPosition) {
  auto sourcePiece = getSquarePiece(sourcePosition);
  sourcePiece->move(this, sourcePosition, targetPosition);

  int offsetX = targetPosition.getX() - sourcePosition.getX();
  int offsetY = targetPosition.getY() - sourcePosition.getY();


  // Gestione en-passant
  bool enPassant = false;
  Square enPassantPosition{targetPosition.getX(), targetPosition.getY()};
  if (dynamic_cast<Pawn*>(sourcePiece) != nullptr && abs(offsetX) == 1 && abs(offsetY) == 1 &&
      (sourcePosition.getY() == 4 && sourcePiece->getColor() == Color::WHITE) || (sourcePosition.getY() == 3 && sourcePiece->getColor() == Color::BLACK) && 
      getSquarePiece(targetPosition) == nullptr) {
      enPassant = true;
      Square newSquare = targetPosition + Square{ 0, (sourcePiece->getColor() == Color::WHITE ? -1 : 1) }; 
      Piece* targetPiece = getSquarePiece(newSquare);
      if ( targetPiece != nullptr && targetPiece->getColor() != sourcePiece->getColor()) {
          enPassantPosition = newSquare;
      }
  }

  // Gestione arrocco
  if (dynamic_cast<King*>(sourcePiece) && abs(offsetX) == 2) {
      Piece* towerPiece;

      // Scambio pezzi
      getSquarePiece(targetPosition) = sourcePiece;
      getSquarePiece(sourcePosition) = nullptr;

      targetPosition = targetPosition + Square{ (offsetX == 2 ? -1 : 1), 0 };
      sourcePosition = sourcePosition + Square{ (offsetX == 2 ? 3 : -4), 0 };
      sourcePiece = getSquarePiece(sourcePosition);
      getSquarePiece(targetPosition) = sourcePiece;
      getSquarePiece(sourcePosition) = nullptr;

      // Siccome offsetX è uguale a 2 o a -2 allora posso ritornare,
      // perchè ho gestito tutti i casi
      return;
  }

  // Per gestione dinamica della memoria, elimino i pezzi dalla board e dalla memoria
  delete getSquarePiece(enPassantPosition); // enPassantPosition contiene il target dell'enpassant se è stato fatto, del target position altrimenti

  // Muovo il pezzo
  getSquarePiece(targetPosition) = sourcePiece;
  getSquarePiece(sourcePosition) = nullptr;

  
  if (enPassantPosition != targetPosition)
      getSquarePiece(enPassantPosition) = nullptr;

}

void Board::swapPieces(Square& getSourcePosition, Square& getTargetPosition, Piece* target_piece) {
  delete getSquarePiece(getTargetPosition);
  getSquarePiece(getTargetPosition) = target_piece;

  delete getSquarePiece(getSourcePosition);
  getSquarePiece(getSourcePosition) = nullptr;
}

std::string Board::toString() const
{
    std::string res = "";
    for (int y = 7; y >= 0; y--) {
        res += char(y+1 + '0');
        res += " ";
        for (int x = 0; x < 8; x++) {
            auto piece = board[y][x];

            if (piece != nullptr)
                res += char(piece->getColor() == Color::BLACK ? piece->getSymbol() : tolower(piece->getSymbol()));
            else
                res += " ";
        }
        res += "\n";
    }
    res += "\n  ABCDEFGH";
    
    return res;
}


std::ostream& operator<<(std::ostream& os, const Board& board) {
    os << board.toString();
    return os;
}