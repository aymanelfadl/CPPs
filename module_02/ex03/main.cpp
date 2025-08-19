#include "Point.hpp"

int main()
{
    Point A(0, 0);
    Point B(10, 0);
    Point C(5, 10);
    Point P(5, -111);

    if (bsp(A, B, C, P))
        std::cout << "Point is inside the triangle" << std::endl;
    else
        std::cout << "Point is outside the triangle" << std::endl;

    return 0;
}