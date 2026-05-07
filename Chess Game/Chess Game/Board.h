#ifndef BOARD_H
#define BOARD_H
#include "Piece.h"

class Board {
private:
  Piece *grid[8][8];

public:
  // En passant: row/col of the square a pawn can be captured on (-1 if none)
  int enPassantRow;
  int enPassantCol;

  Board();
  void initialize();
  void display();
  bool movePiece(int x1, int y1, int x2, int y2, bool whiteTurn);
  bool isInside(int x, int y);
  Piece *getPiece(int x, int y);
};

#endif // !BOARD-H
