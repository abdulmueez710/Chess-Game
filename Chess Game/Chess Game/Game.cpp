#include "Game.h"
#include <iostream>
using namespace std;

Game::Game() : whiteTurn(true) {}

void Game::startGame() { board.initialize(); }

void Game::switchTurn() { whiteTurn = !whiteTurn; }

void Game::takeInput() {
  cout << "\n";
  board.display(); // Display the board before taking input

  char col1, col2;  // column letters  (a-h)
  int rank1, rank2; // rank numbers (1-8, as shown on the board)

  cout << (whiteTurn ? "White" : "Black") << "'s turn (e.g. e2 e4): ";
  cin >> col1 >> rank1 >> col2 >> rank2;

  // Convert to lowercase in case the user types uppercase letters
  if (col1 >= 'A' && col1 <= 'Z')
    col1 += 32;
  if (col2 >= 'A' && col2 <= 'Z')
    col2 += 32;

  // Map to 0-based grid indices:
  //   grid_row = 8 - rank  (rank 8 -> row 0, rank 1 -> row 7)
  //   grid_col = letter - 'a'  (a -> 0, h -> 7)
  int row1 = 8 - rank1;
  int row2 = 8 - rank2;
  int gridCol1 = col1 - 'a';
  int gridCol2 = col2 - 'a';

  if (board.movePiece(row1, gridCol1, row2, gridCol2, whiteTurn)) {
    switchTurn(); // Switch turn only if the move was successful
  } else {
    cout << "Invalid move. Try again." << endl;
  }
}

bool Game::checkGameEnd() {
  // Placeholder for game end logic (e.g., checkmate, stalemate)
  return false;
}
