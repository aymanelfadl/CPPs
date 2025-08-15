#pragma once 

class Fixed
{
    private:
        int fixedPointValue;
        const static int  bits = 8;

    public:
        Fixed();
        ~Fixed();
        Fixed(const Fixed &obj);
        Fixed& operator=(const Fixed &obj);
        int getRawBits(void) const;
        // void setRawBits(int const raw);

};
