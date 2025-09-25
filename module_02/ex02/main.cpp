#include "Fixed.hpp"

int main(void)
{

    // {
    //     Fixed a;                  // default constructor
    //     Fixed b(10);              // int constructor
    //     Fixed const c(20.42f);    // float constructor
    //     Fixed const d(b);         // copy constructor

    //     a = Fixed(20.4321f);    // assignment

    //     // Print values
    //     std::cout << "a: " << a << std::endl;
    //     std::cout << "b: " << b << std::endl;
    //     std::cout << "c: " << c << std::endl;
    //     std::cout << "d: " << d << std::endl;

    //     // Print integer conversions
    //     std::cout << "a as int: " << a.toInt() << std::endl;
    //     std::cout << "b as int: " << b.toInt() << std::endl;
    //     std::cout << "c as int: " << c.toInt() << std::endl;
    //     std::cout << "d as int: " << d.toInt() << std::endl;

    //     // Max and Min
    //     std::cout << "max(a, b): " << Fixed::max(a, b) << std::endl;
    //     std::cout << "min(a, b): " << Fixed::min(a, b) << std::endl;
    //     std::cout << "max(c, d): " << Fixed::max(c, d) << std::endl;
    //     std::cout << "min(c, d): " << Fixed::min(c, d) << std::endl;
        
    
    //     // Comparisons
    //     std::cout << "b < a: " << (b < a) << std::endl;
    //     std::cout << "b <= a: " << (b <= a) << std::endl;
    //     std::cout << "b > a: " << (b > a) << std::endl;
    //     std::cout << "b >= a: " << (b >= a) << std::endl;
    //     std::cout << "b == a: " << (b == a) << std::endl;
    //     std::cout << "b != a: " << (b != a) << std::endl;

    //     // Arithmetic
    //     std::cout << "b + a: " << (b + a) << std::endl;
    //     std::cout << "b - a: " << (b - a) << std::endl;
    //     std::cout << "b * a: " << (b * a) << std::endl;
    //     std::cout << "b / a: " << (b / a) << std::endl;

    //     // Pre/Post increment/decrement
    //     std::cout << "++b: " << ++b << std::endl;  // pre-increment
    //     std::cout << "b++: " << b++ << std::endl;  // post-increment
    //     std::cout << "b--: " << b-- << std::endl;  // post-decrement
    //     std::cout << "--b: " << --b << std::endl;  // pre-decreme
    
    // }    

    {
        Fixed a;
        Fixed const b(Fixed(5.05f) * Fixed(2));

        std::cout << a << std::endl;
        std::cout << ++a << std::endl;
        std::cout << a << std::endl;
        std::cout << a++ << std::endl;
        std::cout << a << std::endl;
        std::cout << b << std::endl;
        std::cout << Fixed::max(a, b) << std::endl;
    }

    return 0;
}