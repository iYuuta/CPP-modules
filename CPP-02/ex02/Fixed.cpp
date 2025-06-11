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

Fixed& Fixed::operator=(const Fixed& _fixed) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &_fixed)
        this->fpn = _fixed.fpn;
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

bool Fixed::operator<(const Fixed& _fixed) {
    if (this->toFloat() < _fixed.toFloat())
        return true;
    return false;
}

bool Fixed::operator<=(const Fixed& _fixed) {
    if (this->toFloat() <= _fixed.toFloat())
        return true;
    return false;
}
bool Fixed::operator>(const Fixed& _fixed) {
    if (this->toFloat() > _fixed.toFloat())
        return true;
    return false;
}
bool Fixed::operator>=(const Fixed& _fixed) {
    if (this->toFloat() >= _fixed.toFloat())
        return true;
    return false;
}
bool Fixed::operator==(const Fixed& _fixed) {
    if (this->toFloat() == _fixed.toFloat())
        return true;
    return false;
}
bool Fixed::operator!=(const Fixed& _fixed) {
    if (this->toFloat() != _fixed.toFloat())
        return true;
    return false;
}

float Fixed::operator+(const Fixed& _fixed) {
    return (this->toFloat() + _fixed.toFloat());
}

float Fixed::operator-(const Fixed& _fixed) {
    return (this->toFloat() - _fixed.toFloat());
}

float Fixed::operator*(const Fixed& _fixed) {
    return (this->toFloat() * _fixed.toFloat());
}

float Fixed::operator/(const Fixed& _fixed) {
    return (this->toFloat() / _fixed.toFloat());
}

Fixed& Fixed::operator++(void) {
    this->fpn++;
    return *this;
}

Fixed& Fixed::operator--(void) {
    this->fpn--;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed tmp = *this;
    this->fpn++;
    return tmp;
}

Fixed Fixed::operator--(int) {
    Fixed tmp = *this;
    this->fpn--;
    return tmp;
}

Fixed& Fixed::min(Fixed& _first, Fixed& _second) {
    if (_first < _second)
        return _first;
    return _second;
}

Fixed& Fixed::max(Fixed& _first, Fixed& _second) {
    if (_first > _second)
        return _first;
    return _second;
}

const Fixed& Fixed::min(const Fixed& _first, const Fixed& _second) {
    if (_first.toFloat() < _second.toFloat())
        return _first;
    return _second;
}

const Fixed& Fixed::max(const Fixed& _first, const Fixed& _second) {
    if (_first.toFloat() > _second.toFloat())
        return _first;
    return _second;
}
