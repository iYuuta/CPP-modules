#include "Fixed.hpp"

const int Fixed::frac_bits = 8;

Fixed::Fixed() {
    std::cout << "Default constructor called" << std::endl;
    fpn = 0;
}

Fixed::Fixed(const int value) {
    std::cout << "Int constructor called" << std::endl;
    this->fpn = value << frac_bits;
}

Fixed::Fixed(const float value) {
    std::cout << "Float constructor called" << std::endl;
    this->fpn = roundf(value * (1 << frac_bits));
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copy)
{
	std::cout << "Copy constructor called" << std::endl;
	this->fpn = copy.fpn;
}

Fixed& Fixed::operator=(const Fixed& _Fixed) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &_Fixed)
        this->fpn = _Fixed.fpn;
    return *this;
}

int Fixed::getRawBits() const {
    std::cout << "getRawBits member function called" << std::endl;
    return this->fpn;
}

void Fixed::setRawBits(int const raw) {
    std::cout << "setRawBits member function called" << std::endl;
    this->fpn = raw;
}

float Fixed::toFloat( void ) const {
    return ((float)(fpn) / (1 << frac_bits));
};
int Fixed::toInt( void ) const {
    return (fpn >> frac_bits);
}

std::ostream& operator<<(std::ostream& out, const Fixed& _fixed) {
    out << _fixed.toFloat() ;
    return out;
}
