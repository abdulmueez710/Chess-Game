#include "Game.h"
#include <iostream>
using namespace std;

Game::Game() : whiteTurn(true) {}

void Game::startGame() {
  board.initialize();
}

void Game::switchTurn() {
  whiteTurn = !whiteTurn;
}

void Game::takeInput() {
	cout << "\n";
	board.display(); // Display the board before taking input
  char temp1, temp2;
  int y1, y2;
  cout << "[x = column(horizontal), y = row(vertical)]\n";
  cout << (whiteTurn ? "White" : "Black") << "'s turn (e4 e2): ";
  cin >> temp1 >> y1 >> temp2 >> y2;
  int x1 = temp1 - 'a';
  int x2 = temp2 - 'a';

  // x = horizontal column (bottom numbers), y = vertical row (left numbers)
  // grid[row][col] = grid[y-1][x-1], so swap before passing
  if (board.movePiece(y1 - 1, x1 - 1, y2 - 1, x2 - 1, whiteTurn)) { // -1 for synchronyzation with 0-based indexing
	  switchTurn();		// Switch turn only if the move was successful
  } else {
	cout << "Invalid move. Try again." << endl;
  }
}

bool Game::checkGameEnd() {
  // Placeholder for game end logic (e.g., checkmate, stalemate)
  return false;
}
