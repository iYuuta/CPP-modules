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

        Fixed& operator=(const Fixed& _fixed);
        bool operator<(const Fixed& _fixed);
        bool operator<=(const Fixed& _fixed);
        bool operator>(const Fixed& _fixed);
        bool operator>=(const Fixed& _fixed);
        bool operator==(const Fixed& _fixed);
        bool operator!=(const Fixed& _fixed);

        float operator+(const Fixed& _fixed);
        float operator-(const Fixed& _fixed);
        float operator*(const Fixed& _fixed);
        float operator/(const Fixed& _fixed);

        Fixed& operator++(void);
        Fixed& operator--(void);
        Fixed operator++(int);
        Fixed operator--(int);
        
        static Fixed& min(Fixed& _first, Fixed& _second);
        static Fixed& max(Fixed& _first, Fixed& _second);
        static const Fixed& min(const Fixed& _first, const Fixed& _second);
        static const Fixed& max(const Fixed& _first, const Fixed& _second);
        
        int getRawBits( void ) const;
        void setRawBits( int const raw );
        float toFloat( void ) const;
        int toInt( void ) const;
};

std::ostream& operator<<(std::ostream& out, const Fixed& _fixed);

#endif