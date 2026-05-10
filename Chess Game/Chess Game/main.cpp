#include "Game.h"
#include <iostream>

using namespace std;

int main() {
  Game chessGame;
  chessGame.startGame();

  chessGame.Menu();
  int choice;
  do{
    cout << "Enter your Choice : ";
    cin >> choice;
    if(choice == 1){
      // Main game loop with taking input and checking for game end
      while (!chessGame.checkGameEnd()) { // Check for game end condition
        chessGame.takeInput();
      }
    }
    else if(choice == 2){
      cout << "\n\nInstructions baad mai add karoon ga mai\n\n";
    }
    else if(choice == 3){
      exit(0);
    }
    else{
      cout << "Invalid choice\n";
    }
  }while(choice != 3);
  return 0;
}