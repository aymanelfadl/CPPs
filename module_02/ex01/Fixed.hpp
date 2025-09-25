#pragma once 

#include <iostream>
#include <cmath>

class Fixed
{
    private:
        int fixedPointValue;
        const static int  bits;

    public:
        Fixed();
        Fixed(const int _fixedPointValue);
        Fixed(const float _fixedPointValue);
        Fixed(const Fixed &obj);

        ~Fixed();

        Fixed& operator=(const Fixed &obj);

        int getRawBits(void) const;
        void setRawBits(int const raw);

        float toFloat( void ) const;
        int toInt( void ) const;
};


std::ostream &operator<<(std::ostream &os, const Fixed &obj);