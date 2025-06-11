#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point {
    private :
        const Fixed x;
        const Fixed y;

    public :
        Point();
        Point(const float _x, const float _y);
        Point(const Point& _Point);
        ~Point();
        Point& operator=(const Point& _Point);
        const Fixed& getX(void) const;
        const Fixed& getY(void) const;
};

std::ostream& operator<<(std::ostream& out, const Point& _Point);

#endif