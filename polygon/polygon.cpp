#include "polygon.h"

void Polygon::add(const Point &p)
{
    points.push_back(p);
}

std::ostream &operator<<(std::ostream &stream, const Polygon &poly)
{
    for(size_t i = 0; i < poly.points.size(); i++)
    {
        stream << "point " << i << ": " << poly.points[i] << std::endl;
    }
    return stream; 
}

Polygon Polygon::operator*(double scalar) const
{
    Polygon res;
    for(size_t i = 0; i < points.size(); i++)
    {
        res.add(Point(points[i].x * scalar, points[i].y * scalar));
    }
    return res;
}

Polygon operator*(double scalar, Polygon &p)
{
    return p * scalar;
}

Polygon& Polygon::operator+=(const Point &vector)
{
    for(size_t i = 0; i < points.size(); i++)
    {
        points[i].x += vector.x;
        points[i].y += vector.y;
    }
    return *this;
}

Point& Polygon::operator[](size_t index)
{
    if(index > points.size() - 1)
    {
        throw InvalidIndexException("Index out of bounds");
    }
    return points[index];
}