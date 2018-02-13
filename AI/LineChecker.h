#ifndef OTHELLO_LINECHECKER_H
#define OTHELLO_LINECHECKER_H

#include "Point.h"
#include <qlist.h>

class LineChecker{
public:
    int chipColor;
    Point point;
    int ** gameField;

    QList<Point> getActiveTiles();
    //checks a line with a unit vector
    QList<Point> checkALine(Point pattern);

    LineChecker(int chipColor, Point point, int ** field);
    ~LineChecker();
};

#endif //OTHELLO_LINECHECKER_H
