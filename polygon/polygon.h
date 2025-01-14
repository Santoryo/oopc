#pragma once
#include "point.h"
#include <vector>
#include <exception>

class Polygon
{
public:
    std::vector<Point> points;
    Polygon() = default;
    void add(const Point &p);

    Polygon operator*(double scalar) const;
    Polygon& operator+=(const Point &vector);
    Point& operator[](size_t index);
};

std::ostream &operator<<(std::ostream &stream, const Polygon &poly);
Polygon operator*(double scalar, Polygon &p);

class InvalidIndexException : public std::exception
{
    std::string msg;
    public:
        InvalidIndexException(std::string msg) : msg("[Polygon Error] " + msg) {}
        const char *what() const noexcept override
        {
            return msg.c_str();
        }
};