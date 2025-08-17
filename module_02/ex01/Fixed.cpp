#include "Fixed.hpp"

int const Fixed::bits = 0;

Fixed::Fixed() : fixedPointValue(0)
{
    std::cout << "Default constructor called" << std::endl;
};

Fixed::Fixed(const int _fixedPointValue)
{
    std::cout << "Int constructor called" << std::endl;
    this->fixedPointValue = _fixedPointValue * 255;
};

Fixed::Fixed(const float _fixedPointValue)
{
    std::cout << "Float constructor called" << std::endl;
    this->fixedPointValue = _fixedPointValue * 255;
};

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
};

Fixed::Fixed(const Fixed &obj)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = obj;
}

Fixed &Fixed::operator=(const Fixed &obj)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this == &obj)
        return *this;

    this->fixedPointValue = obj.fixedPointValue;
    return *this;
}

std::ostream &operator<<(std::ostream &os, const Fixed &obj)
{
    os << obj.toFloat();
    return os;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return this->fixedPointValue;
}

void Fixed::setRawBits(int const raw)
{
    this->fixedPointValue = raw;
}


int Fixed::toInt() const
{
    return (this->fixedPointValue / 255);
}

float Fixed::toFloat() const
{
    return (float)this->fixedPointValue / 255;
}