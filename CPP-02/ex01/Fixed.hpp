#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
    private :
        int fpn;
        const static int frac_bits;

    public :
        Fixed();
        Fixed(const int value);
        Fixed(const float value);
        ~Fixed();
        Fixed(const Fixed& copy);
        Fixed& operator=(const Fixed& _Fixed);
        int getRawBits( void ) const;
        void setRawBits( int const raw );
        float toFloat( void ) const;
        int toInt( void ) const;
};

std::ostream& operator<<(std::ostream& out, const Fixed& _fixed);

#endif