#pragma once

#include "Fixed.hpp"

class Point
{
private:
    Fixed x;
    Fixed y;

public:
    Point();
    Point(const float _x, const float _y);
    Point(const Point &p);

    ~Point();

    Point &operator=(const Point &p);
    Point operator+(const Point &other) const;
    Point operator-(const Point &other) const;

    Fixed getX() const;
    Fixed getY() const;
};

std::ostream &operator<<(std::ostream &os, const Point &p);
bool bsp(Point const a, Point const b, Point const c, Point const point);