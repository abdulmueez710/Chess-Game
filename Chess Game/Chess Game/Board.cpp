#include "Board.h"
#include "Pawn.h"
#include <iostream>
using namespace std;

Board::Board() {
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      grid[i][j] = nullptr;
    }
  }
}

void Board::initialize() {
  // White Pawns
  for (int j = 0; j < 8; j++) {
    grid[6][j] = new Pawn(true);
  }

  // Black Pawns
  for (int j = 0; j < 8; j++) {
    grid[1][j] = new Pawn(false);
  }
}

void Board::display() {
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      if (grid[i][j] == nullptr)
        cout << ". ";
      else
        cout << grid[i][j]->getSymbol() << " ";
    }
    cout << endl;
  }
}

bool Board::movePiece(int x1, int y1, int x2, int y2) {
  if (!isInside(x1, y1) || !isInside(x2, y2))
    return false;

  Piece *p = grid[x1][y1];

  if (p == nullptr)
    return false;

  Piece *target = grid[x2][y2];

  // Prevent friendly fire entirely for all pieces
  if (target != nullptr && target->getColor() == p->getColor())
    return false;

  if (!p->isValidMove(x1, y1, x2, y2, this))
    return false;

  // Move piece
  if (target != nullptr) {
    delete target; // Clean up captured memory
  }

  grid[x2][y2] = p;
  grid[x1][y1] = nullptr;

  return true;
}

bool Board::isInside(int x, int y) {
  return (x >= 0 && x < 8 && y >= 0 && y < 8);
}

Piece *Board::getPiece(int x, int y) { return grid[x][y]; }
