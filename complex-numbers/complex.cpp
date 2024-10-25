#include "complex.h"
#include <math.h>
#include <iostream>

Complex::Complex(double r, double i)
{
    real = r;
    imag = i;
}

const double Complex::amplitude()
{
    return sqrt(real * real + imag * imag);
}

const double Complex::phase()
{
    return atan2(imag, real);
}

Complex Complex::operator+(const Complex &other)
{
    return Complex(real + other.real, imag + other.imag);
}

Complex Complex::operator-(const Complex &other)
{
    return Complex(real - other.real, imag - other.imag);
}

Complex Complex::operator*(const Complex &other)
{
    Complex result;
    result.real = (real * other.real) - (imag * other.imag);
    result.imag = (real * other.imag) + (imag * other.real);
    return result;
}

Complex Complex::operator/(const Complex &other)
{
    if(other.real == 0 && other.imag == 0)
    {
        std::cout << "Error: Division by zero" << std::endl;
        exit(1);
    }

    Complex result;
    double denominator = other.real * other.real + other.imag * other.imag;
    result.real = (real * other.real + imag * other.imag) / denominator;
    result.imag = (imag * other.real - real * other.imag) / denominator;
    return result;
}

Complex &Complex::operator+=(const Complex &other)
{
    real += other.real;
    imag += other.imag;
    return *this;
}

Complex &Complex::operator-=(const Complex &other)
{
    real -= other.real;
    imag -= other.imag;
    return *this;
}

Complex &Complex::operator*=(const Complex &other)
{
    double r = real * other.real - imag * other.imag;
    imag = real * other.imag + imag * other.real;
    real = r;
    return *this;
}

Complex &Complex::operator/=(const Complex &other)
{
    double denominator = other.real * other.real + other.imag * other.imag;
    double r = (real * other.real + imag * other.imag) / denominator;
    imag = (imag * other.real - real * other.imag) / denominator;
    real = r;
    return *this;
}

const bool Complex::operator==(const Complex &other)
{
    return real == other.real && imag == other.imag;
}

const bool Complex::operator!=(const Complex &other)
{
    return real != other.real && imag != other.imag;
}

std::ostream &operator<<(std::ostream &stream, const Complex &other)
{
    std::string sign = "";

    if(other.imag >= 0)
    {
        sign = "+";
    }

    stream << other.real << sign << other.imag << "i";
    return stream;
}

Complex operator+(const double num, const Complex &other)
{
    return Complex(other.real + num, other.imag);
}

Complex operator-(const double num, const Complex &other)
{
    return Complex(num - other.real, -other.imag);
}

Complex operator*(const double num, const Complex &other)
{
    return Complex(other.real * num, other.imag * num);
}

Complex operator/(const double num, const Complex &other)
{
    Complex result;
    double denominator = other.real * other.real + other.imag * other.imag;
    result.real = (num * other.real) / denominator;
    result.imag = (-num * other.imag) / denominator;
    return result;
}

bool operator==(const double num, const Complex &other)
{
    return num == other.real && other.imag == 0;
}

bool operator!=(const double num, const Complex &other)
{
    return num != other.real || other.imag != 0;
}
