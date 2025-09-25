#include "Point.hpp"

Point::Point() : x(0), y(0) {}

Point::~Point() {}

Point::Point(const Point &p)
{
    *this = p;
}

Point &Point::operator=(const Point &p)
{
    if (this == &p)
        return *this;
    
    this->x = p.x;
    this->y = p.y;
    return (*this);
}

Point::Point(const float _x, const float _y) : x(_x), y(_y) {}

std::ostream &operator<<(std::ostream &os, const Point &p)
{
    os << "(" << p.getX() << "," << p.getY() << ")";
    return os;
}

Fixed Point::getX() const
{
    return this->x;
}

Fixed Point::getY() const
{
    return this->y;
}

// algorithm TrianglesAreaApproach(P, A, B, C):
// INPUT
//    P = the point to check if it is inside the triangle
//    A = the first vertex of the triangle
//    B = the second vertex of the triangle
//    C = the third vertex of the triangle
// OUTPUT
//    Returns true if the point P is inside the triangle ABC, false otherwise

// triangle_area <- TriangleArea(A, B, C)
// area_sum <- 0

// area_sum <- area_sum + TriangleArea(A, B, P)
// area_sum <- area_sum + TriangleArea(A, C, P)
// area_sum <- area_sum + TriangleArea(B, C, P)

// if triangle_area = area_sum:
//     return true
// else:
//     return false

Point Point::operator+(const Point &other) const
{
    return Point(this->x.toFloat() + other.x.toFloat(), this->y.toFloat() + other.y.toFloat());
}

Point Point::operator-(const Point &other) const
{
    return Point(this->x.toFloat() - other.x.toFloat(), this->y.toFloat() - other.y.toFloat());
}

static float triangleArea(const Point &A, const Point &B, const Point &C)
{
    return std::abs(
        (
            A.getX().toFloat() * (B.getY().toFloat() - C.getY().toFloat()) +
            B.getX().toFloat() * (C.getY().toFloat() - A.getY().toFloat()) +
            C.getX().toFloat() * (A.getY().toFloat() - B.getY().toFloat())) *
        0.5f);
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    float totalArea = triangleArea(a, b, c);

    float acp = triangleArea(a, c, point);
    float abp = triangleArea(a, b, point);
    float cbp = triangleArea(c, b, point);

    return totalArea == (acp + abp + cbp);
}
