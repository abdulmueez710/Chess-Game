#include "Piece.h"

Piece::Piece(bool isWhite)
{
	this->isWhite = isWhite;
	this->symbol = ' '; // Initialize to fix warning
	this->hasMoved = false;
}
bool Piece::getHasMoved() { 
	return hasMoved; 
}
void Piece::setHasMoved(bool value) { 
	hasMoved = value; 
}

char Piece::getSymbol()
{
	return symbol;
}

bool Piece::getColor()
{
	return isWhite;
}
