#include "Pawn.h"
#include "Board.h"

Pawn::Pawn(bool isWhite) : Piece(isWhite)
{
	symbol = isWhite ? 'P' : 'p';
}

bool Pawn::isValidMove(int x1, int y1, int x2, int y2, Board* board)
{
    int direction = isWhite ? -1 : 1;

    // Moving straight forward
    if (y1 == y2) {
        // Move 1 step
        if (x2 == x1 + direction && board->getPiece(x2, y2) == nullptr) {
            return true;
        }
        // First move (2 steps)
        if (((isWhite && x1 == 6) || (!isWhite && x1 == 1))
            && x2 == x1 + 2 * direction
            && board->getPiece(x1 + direction, y1) == nullptr
            && board->getPiece(x2, y2) == nullptr) {
            return true;
        }
    }
    // Diagonal Capture
    else if ((y2 == y1 + 1 || y2 == y1 - 1) && x2 == x1 + direction) {
        Piece* target = board->getPiece(x2, y2);
        if (target != nullptr && target->getColor() != isWhite) {
            return true;
        }
    }

    return false;
}
