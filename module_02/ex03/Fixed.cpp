#include "Fixed.hpp"

int const Fixed::bits = 8;

const Fixed &Fixed::min(const Fixed &fixed1, const Fixed &fixed2)
{
    if (fixed1 < fixed2)
        return fixed1;
    return fixed2;
}

Fixed &Fixed::min(Fixed &fixed1, Fixed &fixed2)
{
    if (fixed1 < fixed2)
        return fixed1;
    return fixed2;
}


Fixed &Fixed::max(Fixed &fixed1, Fixed &fixed2)
{
    if (fixed1 < fixed2)
        return fixed2;
    return fixed1;
}

const Fixed &Fixed::max(const Fixed &fixed1, const Fixed &fixed2)
{
    if (fixed1 < fixed2)
        return fixed2;
    return fixed1;
}

Fixed::Fixed() : fixedPointValue(0)
{
    // std::cout << "Default constructor called" << std::endl;
};

Fixed::Fixed(const int _fixedPointValue)
{
    // std::cout << "Int constructor called" << std::endl;
    this->fixedPointValue = _fixedPointValue << bits;
};

Fixed::Fixed(const float _fixedPointValue)
{
    // std::cout << "Float constructor called" << std::endl;
    this->fixedPointValue = roundf(_fixedPointValue * (1 << bits));
};

Fixed::~Fixed()
{
    // std::cout << "Destructor called" << std::endl;
};

Fixed::Fixed(const Fixed &obj)
{
    // std::cout << "Copy constructor called" << std::endl;
    *this = obj;
}

Fixed &Fixed::operator=(const Fixed &obj)
{
    // std::cout << "Copy assignment operator called" << std::endl;
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

bool Fixed::operator>(const Fixed &obj) const
{
    return this->getRawBits() > obj.getRawBits();
}

bool Fixed::operator<(const Fixed &obj) const
{
    return this->getRawBits() < obj.getRawBits();
}

bool Fixed::operator>=(const Fixed &obj) const
{
    return this->getRawBits() >= obj.getRawBits();
}

bool Fixed::operator<=(const Fixed &obj) const
{
    return this->getRawBits() <= obj.getRawBits();
}

bool Fixed::operator==(const Fixed &obj) const
{
    return this->getRawBits() == obj.getRawBits();
}

bool Fixed::operator!=(const Fixed &obj) const
{
    return this->getRawBits() != obj.getRawBits();
}

Fixed Fixed::operator+(const Fixed &obj) const
{
    Fixed result;
    result.setRawBits(this->fixedPointValue + obj.fixedPointValue);
    return result;
}

Fixed Fixed::operator-(const Fixed &obj) const
{
    Fixed result;
    result.setRawBits(this->fixedPointValue - obj.fixedPointValue);
    return result;
}

Fixed Fixed::operator*(const Fixed &obj) const
{
    Fixed result;
    result.setRawBits((this->fixedPointValue * obj.fixedPointValue) / (1 << bits));
    return result;
}

Fixed Fixed::operator/(const Fixed &obj) const
{
    Fixed result;
    result.setRawBits(this->fixedPointValue / obj.fixedPointValue);
    return result;
}

Fixed &Fixed::operator++()
{
    this->fixedPointValue++;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed temp = *this;
    this->fixedPointValue++;
    return temp;
}

Fixed &Fixed::operator--()
{
    this->fixedPointValue--;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed temp = *this;
    this->fixedPointValue--;
    return temp;
}

int Fixed::getRawBits(void) const
{
    // std::cout << "getRawBits member function called" << std::endl;
    return this->fixedPointValue;
}

void Fixed::setRawBits(int const raw)
{
    this->fixedPointValue = raw;
}

int Fixed::toInt() const
{
    return this->fixedPointValue >> bits;
}

float Fixed::toFloat() const
{
    return (float)this->fixedPointValue / (1 << bits);
}