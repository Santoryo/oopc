
#include "poly.h"
#include <iostream>
#include <iomanip>
#include <cmath>

double Poly::operator()(double point) const
{
    double result = 0;
    for(auto coefficient : poly)
    {
        result += coefficient.second * pow(point, coefficient.first);
    }
    return result;
}

double& Poly::operator[](int index)
{
    return poly[index];
}

Poly::Poly() {}

Poly::Poly(double c)
{
    this->poly[0] = c;
}

Poly::Poly(const Poly &p)
{
    this->poly = p.poly;
}

const Poly Poly::operator+(const Poly &other) const
{
    Poly result = *this;
    for(auto coefficient : other.poly)
    {
        const int first = coefficient.first;
        if(result.poly.count(first) > 0)
        {
            result.poly[first] += other.poly.at(first);
        }
        else
        {
            result.poly[first] = other.poly.at(first);
        }
    }
    return result;
}

Poly operator+(double scalar, const Poly &other)
{
    Poly result = other;
    result.poly[0] += scalar;
    return result;
}

const Poly Poly::operator-(const Poly &other) const
{
    Poly result = *this;
    for(auto coefficient : other.poly)
    {
        const int first = coefficient.first;
        if(result.poly.count(first) > 0)
        {
            result.poly[first] -= other.poly.at(first);
        }
        else
        {
            result.poly[first] = -other.poly.at(first);
        }
    }
    return result;
}

Poly operator-(double scalar, const Poly &other)
{
    Poly result = other;
    result.poly[0] -= scalar;
    return result;
}

const Poly Poly::operator*(const Poly &other) const
{
    Poly result;
    for(auto c1 : this->poly)
    {
        for(auto c2 : other.poly)
        {
            const int key = c1.first + c2.first;
            const double value = c1.second * c2.second;
            if(result.poly.count(key) > 0)
            {
                result.poly[key] += value;
            }
            else
            {
                result.poly[key] = value;
            }
        }
    }
    return result;
}

Poly operator*(double scalar, const Poly &other)
{
    Poly result = other;
    for(auto &coefficient : result.poly)
    {
        coefficient.second *= scalar;
    }
    return result;
}

Poly Poly::operator-() const
{
    Poly result = *this;
    for(auto &coefficient : result.poly)
    {
        coefficient.second = -coefficient.second;
    }
    return result;
}

std::ostream &operator<<(std::ostream &stream, const Poly &p)
 {
    if(checkIfZero(p))
    {
        stream << "0";
        return stream;
    }

    bool displaySign = false;
    for(auto c = p.poly.rbegin(); c != p.poly.rend(); ++c)
    {
        stream << parseCoefficient(c->first, c->second, displaySign);
        displaySign = true;
    }
    return stream;
}

std::string parseCoefficient(int key, double value, bool displaySign)
{
    std::string sign = value > 0 ? " + " : " - ";
    std::string coefficient = std::to_string(std::abs(value));
    std::string variable = "x^" + std::to_string(key);

    if(key == 0) variable = "";
    if(key == 1) variable = "x";
    if(!displaySign) sign = "";
    if(!displaySign && value < 0) sign = "-";

    return sign + coefficient.substr(0, coefficient.find(".") + 3) + variable;
}

bool checkIfZero(const Poly &other)
{
    for(auto coefficient : other.poly)
    {
        if(coefficient.second != 0)
        {
            return false;
        }
    }
    return true;
}

