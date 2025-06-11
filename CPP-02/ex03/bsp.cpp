#include "Point.hpp"

float get_area(const Point& a, const Point& b, const Point& c) {
    float area;

    area = ((a.getX().toFloat() * (b.getY().toFloat() - c.getY().toFloat()))
            + (b.getX().toFloat() * (c.getY().toFloat() - a.getY().toFloat()))
            + (c.getX().toFloat() * (a.getY().toFloat() - b.getY().toFloat()))) / 2;
    if (area >= 0)
        area *= -1;
    return area;
}

bool bsp( Point const a, Point const b, Point const c, Point const point) {
    float apc_area, abp_area, pbc_area, _area;

    _area = get_area(a, b, c);
    apc_area = get_area(a, point, c);
    abp_area = get_area(a, b, point);
    pbc_area = get_area(point, b, c);
    if (abp_area == 0 || apc_area == 0 || pbc_area == 0)
        return false;
    if (abp_area + apc_area + pbc_area == _area)
        return true;
    return false;
}
