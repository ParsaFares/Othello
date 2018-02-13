#include "Board.h"

Board::Board() {
    fieldStatus = new int*[8];
    for (int i = 0; i < 8; i++) {
        fieldStatus[i] = new int[8];
        for (int j = 0; j < 8; j++) {
            fieldStatus[i][j] = 0;
        }
    }
// Starting chip initialization
    fieldStatus[3][4] = BLACK_PLAYER;
    fieldStatus[4][3] = BLACK_PLAYER;
    fieldStatus[3][3] = WHITE_PLAYER;
    fieldStatus[4][4] = WHITE_PLAYER;
}

void Board::setScore() {
    blackChipCount = 0;
    whiteChipCount = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (fieldStatus[i][j] == BLACK_PLAYER) {
                blackChipCount++;
            }
            if (fieldStatus[i][j] == WHITE_PLAYER) {
                whiteChipCount++;
            }
        }
    }
}

bool Board::noLegalTurns(int gameStatus) {
    return getActiveTiles(gameStatus).size() == 0;
}

QList<Point> Board::getActiveTiles(int gameStatus){
    QList<Point> allActiveFields;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if(fieldStatus[i][j] == 0){
                LineChecker test(gameStatus, Point(i, j), fieldStatus);
                allActiveFields.append(test.getActiveTiles());
            }
        }
    }
    return allActiveFields;
}

Board::~Board() {
    for (int i = 0; i < 8; i++) {
        delete[] fieldStatus[i];
    }
    delete[] fieldStatus;
}