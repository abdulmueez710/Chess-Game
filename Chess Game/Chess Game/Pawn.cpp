#include "Pawn.h"
#include "Board.h"

Pawn::Pawn(bool isWhite) : Piece(isWhite) { symbol = isWhite ? 'P' : 'p'; }

bool Pawn::isValidMove(int x1, int y1, int x2, int y2, Board *board) {
  // White pawns move up (decreasing row), Black pawns move down (increasing
  // row)
  int direction = isWhite ? -1 : 1;

  // Moving straight forward (same column)
  if (y1 == y2) {

    // Move 1 step forward
    if (x2 == x1 + direction && board->getPiece(x2, y2) == nullptr) {
      return true;
    }
    // First move: 2 steps forward
    // NOTE: This assumes pawns that haven't moved are still on their starting
    // row (row 6 for white, row 1 for black). No 'hasMoved' flag is tracked.
    if (((isWhite && x1 == 6) || (!isWhite && x1 == 1)) &&
        x2 == x1 + 2 * direction &&
        board->getPiece(x1 + direction, y1) ==
            nullptr // Intermediate square must be clear
        && board->getPiece(x2, y2) == nullptr) {
      return true;
    }
  }
  // Diagonal Capture (one column left or right, one row forward)
  else if ((y2 == y1 + 1 || y2 == y1 - 1) && x2 == x1 + direction) {
    Piece *target = board->getPiece(x2, y2);
    if (target != nullptr && target->getColor() != isWhite) {
      return true;
    }
    // En passant: destination is the square the opponent's pawn skipped last turn
    if (x2 == board->enPassantRow && y2 == board->enPassantCol) {
      return true;
    }
  }

  return false;
}
