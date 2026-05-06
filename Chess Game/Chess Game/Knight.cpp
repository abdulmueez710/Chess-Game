#include "Knight.h"
#include "Board.h"

Knight::Knight(bool isWhite) : Piece(isWhite)
{
	symbol = isWhite ? 'N' : 'n';
}

bool Knight::isValidMove(int x1, int y1, int x2, int y2, Board* board)
{

	int rowDiff = (x2 - x1) < 0 ? x1 - x2 : x2 - x1;
	int colDiff = (y2 - y1) < 0 ? y1 - y2 : y2 - y1;
	if (!((rowDiff == 2 && colDiff == 1) || (rowDiff == 1 && colDiff == 2)))
		return false;

	Piece* target = board->getPiece(x2, y2);
	if (target != nullptr && target->getColor() == isWhite) {
		return false; // Can't capture own piece
	}

	return true;
}
