#include "Point.h"

bool Point::operator==(Point point){
    return (point.x == this->x) && (point.y == this->y);
}

bool Point::operator!=(Point point){
    return !(*this==point);
}

Point & Point::operator=(const Point & right){
    this->x = right.x;
    this->y = right.y;
    return *this;
}

Point Point::operator+(Point & right){
    Point sumResault;
    sumResault.x = this->x + right.x;
    sumResault.y = this->y + right.y;
    return sumResault;
}

void Point::operator+=(Point & right){
    *this = *this + right;
}

Point::Point(int x, int y) {
    this->x = x;
    this->y = y;
}

Point::Point(const Point &point){
    this->x = point.x;
    this->y = point.y;
}