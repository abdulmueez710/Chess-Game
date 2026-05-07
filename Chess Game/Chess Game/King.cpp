#include "King.h"
#include "Board.h"

King::King(bool isWhite) : Piece(isWhite) { 
    symbol = isWhite ? 'K' : 'k'; 
}

bool King::isValidMove(int x1, int y1, int x2, int y2, Board *board) {
    // Calculate the difference in coordinates
    int rowDiff = x2 - x1;
    int colDiff = y2 - y1;

    // A King move is valid if it moves exactly 1 square in any direction.
    // This means the difference for both row and column must be between -1 and 1,
    // but they cannot both be 0 (standing still).
    if (rowDiff >= -1 && rowDiff <= 1 && colDiff >= -1 && colDiff <= 1) {
        if (rowDiff == 0 && colDiff == 0) {
            return false; // Cannot move to the same square
        }

        Piece* target = board->getPiece(x2, y2);

        // Valid if the square is empty OR contains an enemy piece
        if (target == nullptr || target->getColor() != isWhite) {
            return true;
        }
    }

    // TODO: Implement Castling (usually involves checking if King has moved 
    // and if the squares between King and Rook are empty/safe)

    return false;
}