#include "Queen.h"
#include "Board.h"
#include <cstdlib>

Queen::Queen(bool isWhite) : Piece(isWhite) {
  symbol = isWhite ? 'Q' : 'q';
}

bool Queen::isValidMove(int x1, int y1, int x2, int y2, Board *board)
{
	int rowDifference = x2 - x1;
	int colDifference = y2 - y1;

	// Prevent from staying in the same position
	if(rowDifference == 0 && colDifference == 0){
		return false;
	}

	Piece *target = board->getPiece(x2, y2);

	if (rowDifference == 0 || colDifference == 0){
		int X_step = (rowDifference == 0) ? 0 : (rowDifference > 0 ? 1 : -1);
		int Y_step = (colDifference == 0) ? 0 : (colDifference > 0 ? 1 : -1);

		int x = x1 + X_step;
		int y = y1 + Y_step;

		while(x != x2 || y!=y2){
			if(board->getPiece(x,y) != nullptr ){
				return false;
			}
			x += X_step;
			y += Y_step;
		}

		if(target == nullptr || target->getSymbol() != (isWhite ? 'Q' : 'q')){
			return true;
		}
	}
	if (abs(rowDifference) == abs(colDifference)){
		int X_step = (rowDifference > 0) ? 1 : -1;
		int Y_step = (colDifference > 0) ? 1 : -1;

		int x = x1 + X_step;
		int y = y1 + Y_step;

		while(x != x2 && y != y2){
			if(board->getPiece(x, y) != nullptr){
				return false;
			}
			x += X_step;
			y += Y_step;
		}

		if (target == nullptr || target->getColor() != isWhite){
			return true;
		}
	}
	return false;
}
