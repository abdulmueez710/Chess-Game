#include "Game.h"
#include <iostream>
using namespace std;

Game::Game() : whiteTurn(true) {}

void Game::startGame() {
  board.initialize();

  int x1, y1, x2, y2;

  while (true) {
    board.display();

    cout << "Enter move (x1 y1 x2 y2): ";
    cin >> x1 >> y1 >> x2 >> y2;

    if (!board.movePiece(x1, y1, x2, y2)) {
      cout << "Invalid move!\n";
    }
  }
}

void Game::switchTurn() {
  whiteTurn = !whiteTurn;
}

