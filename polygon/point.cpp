#include "point.h"

Point::Point(float x, float y)
{
    this->x = x;
    this->y = y;
}

std::ostream &operator<<(std::ostream &stream, const Point &point)
{
    stream << "(" << point.x << ", " << point.y << ")";
    return stream; 
}

Point Point::operator+=(const Point &p)
{
    this->x += p.x;
    this->y += p.y;
    return *this;
}