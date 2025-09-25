#pragma once

#include <iostream>
#include <cmath>

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

    static Fixed &min(Fixed &fixed1, Fixed &fixed2);
    static const Fixed &min(const Fixed &fixed1, const Fixed &fixed2);
    
    static Fixed &max(Fixed &fixed1, Fixed &fixed2);
    static const Fixed &max(const Fixed &fixed1, const Fixed &fixed2);

    int getRawBits(void) const;
    void setRawBits(int const raw);

    float toFloat(void) const;
    int toInt(void) const;
};

std::ostream &operator<<(std::ostream &os, const Fixed &obj);