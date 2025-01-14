#include "point.h"
#include "polygon.h"

Point p1;
Point p2;
Polygon poly;

int main()
{
    p1.x  = 1.0f;
    p1.y = 2.1f;

    p2.x = 5;
    p2.y = 10;

    std::cout << "Point 1: " << p1 << std::endl;

    poly.add(p1);
    poly.add(p2);

    std::cout << "Polygon 1:" << std::endl << poly << std::endl;

    poly = poly * 2;
    std::cout << "Polygon 1:" << std::endl << poly << std::endl;

    poly = 2 * poly;
    std::cout << "Polygon 1:" << std::endl << poly << std::endl;

    Point vector(1.1, 1.1);

    (poly += vector) += vector;
    std::cout << "Polygon 1:" << std::endl << poly << std::endl;

    std::cout << "Polygon's 1st point " << poly[1] << std::endl;
    poly[1].x = 999;
    std::cout << "Polygon 1:" << std::endl << poly << std::endl;

    try
    {
        poly[2].x = 21;
    }
    catch(InvalidIndexException &e)
    {
        std::cerr << e.what() << std::endl;
    }
}