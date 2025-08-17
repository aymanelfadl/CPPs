#include "Fixed.hpp"

int const Fixed::bits = 0;

Fixed::Fixed() : fixedPointValue(0)
{
    std::cout << "Default constructor called" << std::endl;
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

    this->fixedPointValue = obj.getRawBits();
    return *this;
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
