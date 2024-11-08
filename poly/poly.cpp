
#include "poly.h"
#include <iostream>
#include <iomanip>
#include <cmath>

std::string parseCoefficient(int key, double value, bool displaySign);

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

Poly::Poly(double val)
{
    poly[0] = val;
}

Poly operator+(const Poly &p1, const Poly &p2)
{
    Poly result = p1;
    for(auto coefficient : p2.poly)
    {
        const int key = coefficient.first;
        if(result.poly.count(key) > 0)
        {
            result.poly[key] += p2.poly.at(key);
        }
        else
        {
            result.poly[key] = p2.poly.at(key);
        }
    }
    result.deleteZeros();
    return result;
}

Poly operator-(const Poly &p1, const Poly &p2)
{
    Poly result = p1;
    for(auto coefficient : p2.poly)
    {
        const int key = coefficient.first;
        if(result.poly.count(key) > 0)
        {
            result.poly[key] -= p2.poly.at(key);
        }
        else
        {
            result.poly[key] = -p2.poly.at(key);
        }
    }
    result.deleteZeros();
    return result;
}

Poly operator*(const Poly &p1, const Poly &p2)
{
    Poly result;
    for(auto i1 : p1.poly)
    {
        for(auto i2 : p2.poly)
        {
            const int key = i1.first + i2.first;
            const double value = i1.second * i2.second;
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
    result.deleteZeros();
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

std::ostream &operator<<(std::ostream &stream, const Poly &other)
 {
    if(other.checkIfZero())
    {
        stream << "0";
        return stream;
    }

    bool displaySign = false;
    for(auto p = other.poly.rbegin(); p != other.poly.rend(); ++p)
    {
        stream << parseCoefficient(p->first, p->second, displaySign);
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

bool Poly::checkIfZero() const
{
    for(auto coefficient : poly)
    {
        if(coefficient.second != 0)
        {
            return false;
        }
    }
    return true;
}

void Poly::deleteZeros()
{
    Poly result = *this;
    for(auto p : poly)
    {
        if(p.second == 0)
        {
            result.poly.erase(p.first);
        }
    }
    *this = result;
}

