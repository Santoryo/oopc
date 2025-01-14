#pragma once
#include <iostream>

class Point
{
public:
    Point() = default;
    Point(float x, float y);
    float x;
    float y;
    Point operator+=(const Point &p);
};

std::ostream &operator<<(std::ostream &stream, const Point &point);