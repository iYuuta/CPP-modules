#include "Fixed.hpp"

Fixed::Fixed() {
    std::cout << "Default constructor called" << std::endl;
    fpn = 0;
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