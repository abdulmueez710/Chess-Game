#ifndef GAME_H
#define GAME_H
#include "Board.h"

class Game {
private:
    Board board;
    bool whiteTurn;

public:
    Game();
    void Menu();
    void startGame();
    void switchTurn();
    void takeInput();
    bool checkGameEnd();
};

#endif 