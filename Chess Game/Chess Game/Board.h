#ifndef BOARD_H
#define BOARD_H
#include "Piece.h"

class Board {
private:
    Piece* grid[8][8];

public:
    Board();
    void initialize();
    void display();
    bool movePiece(int x1, int y1, int x2, int y2, bool whiteTurn);
    bool isInside(int x, int y);
    Piece* getPiece(int x, int y);
};

#endif // !BOARD-H
