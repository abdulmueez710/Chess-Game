#ifndef GAME_H
#define GAME_H
#include "Board.h"

class Game {
private:
    Board board;
    bool whiteTurn;

public:
    Game();
    void startGame();
    void switchTurn();
    void takeInput();
    bool checkGameEnd();
};

#endif // !GAME-H