#ifndef BOARD_H
#define BOARD_H
#include "Piece.h"
#include <string>
using namespace std;

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
  bool isInCheck(bool white);
  bool isCheckmate(bool white);
  bool saveToFile(const string& filename, bool whiteTurn);
  bool loadFromFile(const string& filename, bool& whiteTurn);
};

#endif // !BOARD-H
