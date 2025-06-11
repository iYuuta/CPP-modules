#include "Point.hpp"


bool bsp( Point const a, Point const b, Point const c, Point const point);

void test_bsp(const Point& a, const Point& b, const Point& c, const Point& p, bool expected) {
    bool result = bsp(a, b, c, p);
    std::cout << "Test point " << p;
    std::cout << "Expected: " << (expected ? "Inside" : "Outside");
    if (result == expected)
        std::cout << " ✅\n";
    else
        std::cout << " ❌\n";
}

int main() {
    Point a(0.0f, 0.0f);
    Point b(5.0f, 0.0f);
    Point c(2.5f, 5.0f);

    test_bsp(a, b, c, Point(2.5f, 2.0f), true);     // Inside
    test_bsp(a, b, c, Point(5.0f, 5.0f), false);    // Outside
    test_bsp(a, b, c, Point(0.0f, 0.0f), false);    // Corner point
    test_bsp(a, b, c, Point(2.5f, 0.0f), false);    // On bottom edge
    test_bsp(a, b, c, Point(2.5f, 4.9f), true);     // Near top, inside
    test_bsp(a, b, c, Point(3.0f, 1.0f), true);     // Inside
    test_bsp(a, b, c, Point(-1.0f, -1.0f), false);  // Far outside
    return 0;
}
