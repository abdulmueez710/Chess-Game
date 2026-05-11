#ifndef PIECE_H
#define PIECE_H

class Board;

class Piece {
protected:
  bool isWhite;
  char symbol;
  bool hasMoved;

public:
  Piece(bool isWhite);
  bool getHasMoved();
  void setHasMoved(bool value);
  virtual bool isValidMove(int x1, int y1, int x2, int y2, Board *board) = 0;  // sb Pieces ishi ko override krein ge
  char getSymbol();
  bool getColor();
  virtual ~Piece() = default; // virtual ~Piece() {} --> Same
};

#endif