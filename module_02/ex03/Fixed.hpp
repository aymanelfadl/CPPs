#pragma once

#include <iostream>

class Fixed
{
private:
    int fixedPointValue;
    const static int bits;

public:
    Fixed();
    Fixed(const int _fixedPointValue);
    Fixed(const float _fixedPointValue);
    Fixed(const Fixed &obj);

    ~Fixed();

    Fixed &operator=(const Fixed &obj);

    bool operator>(const Fixed &obj) const;
    bool operator<(const Fixed &obj) const;
    bool operator>=(const Fixed &obj) const;
    bool operator<=(const Fixed &obj) const;
    bool operator==(const Fixed &obj) const;
    bool operator!=(const Fixed &obj) const;

    Fixed operator+(const Fixed &obj) const;
    Fixed operator-(const Fixed &obj) const;
    Fixed operator*(const Fixed &obj) const;
    Fixed operator/(const Fixed &obj) const;

    Fixed &operator++();
    Fixed operator++(int);

    Fixed &operator--();
    Fixed operator--(int);

    static const Fixed &max(const Fixed &fixed1, const Fixed &fixed2);

    int getRawBits(void) const;
    void setRawBits(int const raw);

    float toFloat(void) const;
    int toInt(void) const;
};

std::ostream &operator<<(std::ostream &os, const Fixed &obj);