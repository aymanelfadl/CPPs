#include "Fixed.hpp"

Fixed::Fixed(){};

Fixed::~Fixed(){};

Fixed::Fixed(const Fixed& obj)
{
    this->fixedPointValue = obj.fixedPointValue;
}

Fixed& Fixed::operator=(const Fixed &obj)
{
    if (this == &obj)
        return *this;
    
    this->fixedPointValue = obj.fixedPointValue;
    return *this;
}

int Fixed::getRawBits(void) const
{
    return bits;
}