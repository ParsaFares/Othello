#ifndef OTHELLO_POINT_H
#define OTHELLO_POINT_H

class Point {
public:
    //coordinates
    int x;
    int y;

    bool operator!=(Point point);
    bool operator==(Point point);
    Point &operator=(const Point & right);
    Point operator+(Point & right);
    void operator+=(Point & right);

    Point(){};
    Point(int x, int y);
    Point(const Point &point);
    ~Point(){};
};

#endif //OTHELLO_POINT_H
