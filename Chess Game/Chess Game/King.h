#ifndef KING_H
#define KING_H
#include "Piece.h"

class Board;

class King : public Piece {
public:
   King(bool isWhite);
   bool isValidMove(int x1, int y1, int x2, int y2, Board *board) override ;
};

#endif
