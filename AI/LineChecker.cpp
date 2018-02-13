#include "LineChecker.h"

LineChecker::LineChecker(int chipColor, Point point, int **field) {
    this->chipColor = chipColor;
    this->point = point;
    gameField = new int * [8];
    for(int i = 0 ; i < 8 ; i++){
        gameField[i] = new int [8];
        for(int j = 0 ; j < 8 ; j++){
            gameField[i][j] = field[i][j];
        }
    }
}

QList<Point> LineChecker::getActiveTiles() {
    gameField[point.x][point.y] = chipColor;

    QList<Point> result;

    // Vertical and horizontal checks
    result.append(checkALine(Point(0, 1)));
    result.append(checkALine(Point(1, 0)));
    result.append(checkALine(Point(0, -1)));
    result.append(checkALine(Point(-1, 0)));

    // Diagonal checks
    result.append(checkALine(Point(1, 1)));
    result.append(checkALine(Point(-1, -1)));
    result.append(checkALine(Point(-1, 1)));
    result.append(checkALine(Point(1, -1)));

    if (result.size() > 0) {
        result.append(Point(point));
        return result;
    } else {
        gameField[point.x][point.y] = 0;
        return result;
    }

}

QList<Point> LineChecker::checkALine(Point pattern) {
    bool isActive = false;
    QList<Point> result;
    for (Point counter = point + pattern ;
         (counter.x >= 0 && counter.x < 8) && (counter.y >= 0 && counter.y < 8);
         counter += pattern) {
        if ((gameField[counter.x][counter.y] == chipColor)) {
            isActive = true;
            break;
        } else if (gameField[counter.x][counter.y] == 0) {
            break;
        } else {
            result.push_back(Point(counter));
        }
    }
    if (isActive) {
        return result;
    } else {
        return QList<Point>();
    }
}


LineChecker::~LineChecker() {
    for(int i = 0; i < 8; i++){
        delete [] gameField[i];
    }

    delete [] gameField;
}