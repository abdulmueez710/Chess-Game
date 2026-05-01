#ifndef PIECE_H
#define PIECE_H

class Board;

class Piece {
protected:
  bool isWhite;
  char symbol;

public:
  Piece(bool isWhite);
  virtual bool isValidMove(int x1, int y1, int x2, int y2, Board *board) = 0;
  char getSymbol();
  bool getColor();
  virtual ~Piece() = default;
};

#endif