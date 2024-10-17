#pragma once
#include <iostream>
#include <math.h>

class Complex {
    public:
        double real;
        double imag;
        Complex(double r = 0.0, double i = 0.0);
        double getReal();
        double getImag();

        double magnitude();
        double phase();

        Complex operator+(const Complex& other);
        Complex operator-(const Complex& other);
        Complex operator*(const Complex& other);
        Complex operator/(const Complex& other);

        Complex& operator+=(const Complex& other);
        Complex& operator-=(const Complex& other);
        Complex& operator*=(const Complex& other);
        Complex& operator/=(const Complex& other);

        bool operator==(const Complex& other);
        bool operator!=(const Complex& other);

        friend std::ostream& operator<<(std::ostream& stream, const Complex& other);
};