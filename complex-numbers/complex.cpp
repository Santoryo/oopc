#include "complex.h"
#include <math.h>

Complex::Complex(double r, double i)
{
    real = r;
    imag = i;
}

double Complex::getReal()
{
    return real;
}

double Complex::getImag()
{
    return imag;
}

double Complex::magnitude()
{
    return sqrt(real * real + imag * imag);
}

double Complex::phase()
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

bool Complex::operator==(const Complex &other)
{
    return real == other.real && imag == other.imag;
}

bool Complex::operator!=(const Complex &other)
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
