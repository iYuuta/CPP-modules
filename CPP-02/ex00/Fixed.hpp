#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
    private :
        int fpn;
        const static int frac_bits;

    public :
        Fixed();
        ~Fixed();
        Fixed(const Fixed& copy);
        Fixed& operator=(const Fixed& _Fixed);
        int getRawBits( void ) const;
        void setRawBits( int const raw );
};

#endif