#pragma once
#include <iostream>

class Complex
{
public:
    double real;
    double imag;
    Complex(double r = 0.0, double i = 0.0);

    const double amplitude();
    const double phase();

    Complex operator+(const Complex &other);
    Complex operator-(const Complex &other);
    Complex operator*(const Complex &other);
    Complex operator/(const Complex &other);

    Complex &operator+=(const Complex &other);
    Complex &operator-=(const Complex &other);
    Complex &operator*=(const Complex &other);
    Complex &operator/=(const Complex &other);

    const bool operator==(const Complex &other);
    const bool operator!=(const Complex &other);
};

std::ostream &operator<<(std::ostream &stream, const Complex &other);

bool operator==(double num, const Complex &other);
bool operator!=(double num, const Complex &other);

Complex operator+(double num, const Complex &other);
Complex operator-(double num, const Complex &other);
Complex operator*(double num, const Complex &other);
Complex operator/(double num, const Complex &other);