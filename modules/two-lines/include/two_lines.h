// Copyright 2018 Panov Aleksander

#ifndef MODULES_TWO_LINES_INCLUDE_TWO_LINES_H_
#define MODULES_TWO_LINES_INCLUDE_TWO_LINES_H_

struct Point {
    double x;
    double y;
    Point();
    Point(double _x, double _y);

    Point& operator=(const Point& point);
    bool operator == (const Point& point) const;
    bool operator != (const Point& point) const;
};

class LineSegment {
 private:
    Point point1;
    Point point2;

 public:
    LineSegment();
    LineSegment(Point _point1, Point _point2);
    LineSegment(const LineSegment &line);

    Point getPoint1() const;
    Point getPoint2() const;
    bool intersect(const LineSegment &line) const;

    LineSegment& operator=(const LineSegment& line);
    bool operator == (const LineSegment& line) const;
    bool operator != (const LineSegment& line) const;
};

#endif  // MODULES_TWO_LINES_INCLUDE_TWO_LINES_H_
