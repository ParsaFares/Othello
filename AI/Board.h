#ifndef OTHELLO_BOARD_H
#define OTHELLO_BOARD_H

#define WHITE_PLAYER -1
#define BLACK_PLAYER 1

#include "LineChecker.h"
#include "Point.h"

class Board{
public:
    Board();
    ~Board();

    int blackChipCount;
    int whiteChipCount;

    //changes the counters
    void setScore();
    QList<Point> getActiveTiles(int gameStatus);
    //check if exist legal turn
    bool noLegalTurns(int gameStatus);

    int **fieldStatus;
};

#endif //OTHELLO_BOARD_H
