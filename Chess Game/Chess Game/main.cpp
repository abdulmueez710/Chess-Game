#include "Game.h"

int main() {
  Game chessGame;
  chessGame.startGame();

  // Main game loop with taking input and checking for game end
  while (!chessGame.checkGameEnd()) { // Check for game end condition
    chessGame.takeInput();
  }

  return 0;
}