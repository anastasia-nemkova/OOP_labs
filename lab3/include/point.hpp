#pragma once

#include<iostream>
#include<cmath>

class Point{
private:
    double x_, y_;
public:
    Point() : x_(0.0), y_(0.0) {};
    Point(std::istream &is);
    Point(double x, double y) : x_(x), y_(y) {};

    double getX() const;
    double getY() const;
    double dist(Point &other);

    friend std::istream& operator>>(std::istream& is, Point& p);
    friend std::ostream& operator<<(std::ostream& os, const Point& p);
};

