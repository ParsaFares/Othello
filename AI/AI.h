#ifndef OTHELLO_AI_H
#define OTHELLO_AI_H

#include "LineChecker.h"
#include "Point.h"
#include "Board.h"

class AI {
public:
    AI(int gameStatus);
    void makeTurn(Board *map);
    ~AI(){};

private:
    //returns best move in this status
    Point getRichestTile(Board *map);
    int player;
};

#endif //OTHELLO_AI_H
