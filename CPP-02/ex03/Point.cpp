#include "Point.hpp"

Point::Point() {};

Point::~Point() {};

Point::Point(const float _x, const float _y): x(_x), y(_y) {}

Point::Point(const Point& _Point): x(_Point.x.toFloat()), y(_Point.y.toFloat()){}

Point& Point::operator=(const Point& _Point) {
    if (this == &_Point)
        return *this;
    return *this;
}

const Fixed	&Point::getX(void) const {
	return this->x;
}

const Fixed	&Point::getY(void) const {
	return this->y;
}

std::ostream& operator<<(std::ostream& out, const Point& _Point) {
    out << "X: " << _Point.getX() << ",  Y: " << _Point.getY() << std::endl;
    return out;
}